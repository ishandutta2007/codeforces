#include <bits/stdc++.h>
using namespace std;

#define rep(i, from, to) for (int i = from; i < int(to); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
struct pii {
	mutable int first, second;
	pii(int a, int b) : first(a), second(b) {}
};
bool operator<(pii a, pii b) {
	return make_pair(a.first, a.second) < make_pair(b.first, b.second);
}
typedef vector<int> vi;

int main() {
	cin.sync_with_stdio(false);
	int N;
	cin >> N;
	vi a(N);
	map<int, vi> hs;
	rep(i,0,N) {
		cin >> a[i];
		hs[-a[i]].push_back(i);
	}
	set<pii> intv;
	vi res(N, -1);
	trav(pa, hs) {
		int h = -pa.first;
		trav(x, pa.second) {
			auto it = intv.lower_bound(pii(x, 0));
			int c = 0, len2 = 0;
			if (it != intv.end() && it->first == x+1) {
				it->first = x;
				c++;
				len2 = it->second - it->first;
			}
			if (it != intv.begin()) {
				auto it2 = it; --it2;
				if (it2->second == x-1) {
					it2->second = x;
					len2 = it2->second - it2->first;
					c++;
					if (c == 2) {
						it2->second = it->second;
						intv.erase(it);
						len2 = it2->second - it2->first;
					}
				}
			}
			if (c == 0) {
				intv.insert(pii(x, x));
			}
			res[len2] = max(res[len2], h);
		}
	}
	int prev = -1;
	for (int l = N; l --> 0; ) {
		res[l] = max(res[l], prev);
		prev = res[l];
	}
	rep(i,0,N)
		cout << res[i] << ' ';
	cout << endl;
}