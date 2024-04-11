#include <bits/stdc++.h>

using namespace std;

int tc, n;

int query(vector<int> le, vector<int> fi) {
	cout << le.size() << " " << fi.size() << " ";
	for (int v : le) cout << v << " ";
	for (int v : fi) cout << v << " ";
	cout << endl;
	int res;
	cin >> res;
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc;
	while (tc--) {
		cin >> n;
		vector<int> g;
		g.push_back(1);
		vector<int> stuff;
		for (int i = 2; i <= n; i++) {
			stuff.push_back(i);
		}
		int md = query(g, stuff);
		while (stuff.size() != 1) {
			int mid = (stuff.size()/2);
			vector<int> o1, o2;
			for (int i = 0; i < mid; i++) {
				o1.push_back(stuff[i]);
			}
			for (int i = mid; i < stuff.size(); i++) {
				o2.push_back(stuff[i]);
			}
			stuff.clear();
			if (query(g, o1) == md) {
				for (int v : o1) stuff.push_back(v);
			}
			else {
				for (int v : o2) stuff.push_back(v);
			}
		}

		vector<int> cg;
		for (int i = 1; i <= n; i++) {
			if (i != stuff[0]) cg.push_back(i);
		}
		int ans = query(stuff, cg);
		cout << -1 << " " << ans << endl;

	}
}