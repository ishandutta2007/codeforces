#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> v(n);
	vector<vector<int>> pf(n);
	for(auto &x : v)
		cin >> x;
	for(int i = 0; i < n; i++) {
		int x = v[i];
		for(int b = 30; b >= 0; b--) {
			if(x >> b)
				pf[i].push_back(x >> b);
		}
	}
	sort(pf.begin(), pf.end());
	/*for(int i = 0; i < n; i++) {
		for(auto p : pf[i])
			cout << p << " ";
		cout << endl;
	}*/
	int lo = n, hi = 1000000000;
	vector<int> ans;
	while(lo < hi) {
		int mi = (lo + hi)/2;
		bool good = true;
		set<int> used;
		ans.clear();
		for(int i = 0; i < n; i++) {
			bool found = false;
			for(int j = pf[i].size() - 1; j >= 0; j--) {
				if(pf[i][j] > mi)
					continue;
				if(used.count(pf[i][j]))
					continue;
				used.insert(pf[i][j]);
				ans.push_back(pf[i][j]);
				found = true;
				break;
			}
			if(!found) {
				good = false;
				break;
			}
		}
		if(good)
			hi = mi;
		else
			lo = mi + 1;
	}
	ans.clear();
	set<int> used;
	for(int i = 0; i < n; i++) {
		for(int j = pf[i].size() - 1; j >= 0; j--) {
			if(pf[i][j] > lo)
				continue;
			if(used.count(pf[i][j]))
				continue;
			used.insert(pf[i][j]);
			ans.push_back(pf[i][j]);
			break;
		}
	}
	for(auto x : ans)
		cout << x << " ";
	cout << endl;
}