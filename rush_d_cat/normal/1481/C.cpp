#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t; cin >> t;
	while (t --) {
		int n, m; cin >> n >> m;
		vector<int> a(n), b(n), c(m);
		for (int i = 0; i < n; i ++) cin >> a[i];
		for (int i = 0; i < n; i ++) cin >> b[i];
		for (int i = 0; i < m; i ++) cin >> c[i];


		set< pair<int,int> > gg, ok;

		for (int i = 0; i < n; i ++) {
			if (a[i] == b[i]) ok.insert(make_pair(a[i], i)); else gg.insert(make_pair(b[i], i));
		} 

		bool wandan = false;
		vector<int> res(m);
		for (int i = m - 1; i >= 0; i --) {
			int x  = c[i];

			auto it = gg.lower_bound(make_pair(x, 0));
			if (it != gg.end() && (*it).first == x) {
				res[i] = (*it).second + 1;
				gg.erase(it); 
			} else {
				auto it = ok.lower_bound(make_pair(x, 0));
				if (it != ok.end() && (*it).first == x) {
					res[i] = (*it).second + 1;
					ok.erase(it);
				} else if (i < m-1) {
					res[i] = res[i+1];
				} else {
					wandan = true;
				}
			}
		}
		if (gg.size()) wandan = true;
		cout << (wandan ? "NO" : "YES") << endl;
		if (! wandan) {
			for (int i = 0; i < m; i ++) cout << res[i] << " \n"[i==m-1];
		}
	}
}