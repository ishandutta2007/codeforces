#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using vi = vector<int>;
using db = double;
#define pb push_back
#define fir first
#define sec second

int main() {
	int n; cin >> n;
	
	multiset <int> l, r, sp1, sp2;
	ll ans = 0;
	for(int i = 1; i <= n; i ++) {
		int x; scanf("%d", &x);

		int c0 = sp1.size() ? x - *sp1.begin() : -1;
		int c1 = sp2.size() ? x - *sp2.begin() : -1;
		int c2 = (r.size() && sp2.size()) ? x + *sp2.rbegin() - 2 * (*r.begin()) : -1;
		int c3 = r.size() ? x - *r.begin() : -1;
		
		vector <pair <int, int>> v = {{c0, 0}, {c1, 1}, {c2, 2}, {c3, 3}};
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		
		if(v[0].fir < 0)
			sp2.insert(x);
		else {
			if(v[0].sec == 0) {
				l.insert(*sp1.begin());
				r.insert(x);
				sp1.erase(sp1.begin());
				ans += c0;
			} else if(v[0].sec == 1) {
				l.insert(*sp2.begin());
				r.insert(x);
				sp2.erase(sp2.begin());
				ans += c1;
			} else if(v[0].sec == 2) {
				l.insert(*r.begin());
				r.erase(r.begin());
				r.insert(*sp2.rbegin());
				r.insert(x);
				sp2.erase(sp2.find(*sp2.rbegin()));
				ans += c2;
			} else {
				sp1.insert(*r.begin());
				r.erase(r.begin());
				r.insert(x);
				ans += c3;
			}
			for(int x : sp2)
				sp1.insert(x);
			sp2 = {};
		}
		//cout << i << ' ' << ans << '\n';
	}
	cout << ans << '\n';
	
	return 0;
}