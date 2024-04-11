#include <bits/stdc++.h>
using namespace std;

using vi = vector <int>;
#define pb push_back

struct comp {
	int cnt;
	vi l, h;
	void w() const {
		cout << "------\n";
		cout << cnt << '\n';
		for(int i : l) cout << i << ' '; cout << '\n';
		for(int i : h) cout << i << ' '; cout << '\n';
	}
	comp(int cnt, vi l, vi h) : cnt(cnt), l(l), h(h) {}
	bool operator <(comp c) const {
		for(int i = 0; i < l.size(); i ++)
			if(l[i] >= c.l[i]) return 0;
		return 1;
	}
	comp merge(comp c) {
		comp r = *this;
		r.cnt += c.cnt;
		for(int i = 0; i < l.size(); i ++) {
			r.l[i] = min(r.l[i], c.l[i]);
			r.h[i] = max(r.h[i], c.h[i]);
		}
		return r;
	}
	
	bool inter(comp c) const {
		int a = 0, b = 0, t = 0;
		for(int i = 0; i < l.size(); i ++) {
			if(h[i] < c.l[i])
				a ++;
			else if(c.h[i] < l[i])
				b ++;
			else
				t ++;
		}
		return a && b || t;
	}
};

int main() {
	
	int n, k; cin >> n >> k;
	set <comp> st;
	for(int i = 1; i <= n; i ++) {
		//cout << "------\n";
		vi v;
		for(int j = 0; j < k; j ++) {
			int x; scanf("%d", &x);
			v.pb(x);
		}
		comp c(1, v, v);
		
		auto it = st.lower_bound(c);
		vector <comp> erase;
		
		if(it != st.begin() && prev(it) -> inter(c)) it --;
		
		while(it != st.end() && it -> inter(c)) {
			//cout << "!\n";
			erase.pb(*it);
			c = c.merge(*it);
			//it -> w();
			it ++;
		}
		
		for(auto i : erase)
			st.erase(i);
		//c.w();
		st.insert(c);
		
		printf("%d\n", st.rbegin() -> cnt);
	}
}