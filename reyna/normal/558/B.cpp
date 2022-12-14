//In the name of God
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 9;
vector<int> p[N];
int main() {
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n;i++) {
		int x; cin >> x;
		p[x].push_back(i);
	}
	int mx = 0;
	for(int i = 0; i < N;++i) mx = max(mx,(int)p[i].size());
	int l = 0,sz = 1e9;
	for(int i = 0; i < N;++i) {
		if(p[i].size() == mx && p[i].size()) {
			if(p[i][p[i].size() - 1] - p[i][0] + 1 < sz) {
				sz = p[i][p[i].size() - 1] - p[i][0] + 1;
				l = p[i][0];
			}
		}
	}
	cout << l + 1 << ' ' << l + sz << '\n';
	return 0;
}