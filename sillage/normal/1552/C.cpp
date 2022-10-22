#include<bits/stdc++.h>
using namespace std;
int vis[220];
void solve(){
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> cd;
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= k; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y) swap(x, y);
		cd.push_back(make_pair(x, y));
		vis[x] = vis[y] = 1;
	}
	vector<int> g;
	for (int i = 1; i <= 2 * n; i++) if (!vis[i]) g.push_back(i);
	for (int i = 1; i <= n - k; i++) cd.push_back(make_pair(g[i - 1], g[i - 1 + n - k]));
	sort(cd.begin(), cd.end());
	//for (auto pr : cd) printf("%d %d\n", pr.first, pr.second);
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++){
			if (cd[j].first > cd[i].first && cd[j].first < cd[i].second && cd[j].second > cd[i].second) cnt++;
		}
	cout << cnt << endl;


}
int main(){
	int T;
	cin >> T;
	while(T--) solve();
}