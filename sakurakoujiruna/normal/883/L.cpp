#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using db = double;
using vi = vector<int>;
#define pb push_back
#define fir first
#define sec second

struct taxi {
	int id, pos; ll ts;
	bool operator <(taxi i) const {
		return tie(ts, id) < tie(i.ts, i.id);
	}
};

set <taxi> r;
map <int, set <taxi>> w;

int main() {
	int n, k, m; cin >> n >> k >> m;
	for(int i = 1; i <= k; i ++) {
		int x; scanf("%d", &x);
		w[x].insert({i, x, 0});
	}
	
	ll now = 0;
	
	while(m --) {
		ll t; int a, b;
		cin >> t >> a >> b;
		
		if(now < t) now = t;
		
		while(r.size() && r.begin() -> ts <= now) {
			w[r.begin() -> pos].insert(*r.begin());
			r.erase(r.begin());
		}
		if(!w.size()) {
			now = r.begin() -> ts;
			while(r.size() && r.begin() -> ts <= now) {
				w[r.begin() -> pos].insert(*r.begin());
				r.erase(r.begin());
			}
		}
		
		auto f = [&](auto it) {
			taxi i = *((it -> second).begin());
			(it -> second).erase(i);
			
			printf("%d %lld\n", i.id, now + abs(i.pos - a) - t);
			
			i.ts = now + abs(a - i.pos) + abs(a - b);
			i.pos = b;
			if((it -> second).size() == 0)
				w.erase(it);
			r.insert(i);
		};
		
		auto it = w.lower_bound(a);
		if(it == w.begin())
			f(it);
		else {
			auto jt = prev(it);
			if(it == w.end())
				f(jt);
			else {
				int di = abs(a - it -> fir);
				int dj = abs(a - jt -> fir);
				if(di < dj) f(it);
				else if(di > dj) f(jt);
				else {
					taxi i = *((it -> second).begin());
					taxi j = *((jt -> second).begin());
					if(i < j) f(it);
					else f(jt);
				}
			}
		}
	}
	
	return 0;
}