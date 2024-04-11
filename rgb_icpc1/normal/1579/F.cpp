#include <bits/stdc++.h>

using namespace std;
#define endl '\n'
const int MX = 1000005;
int a[MX], rlt[MX];
bool can[MX], vis[MX];
int N, d;
bool _dfs(int u) {
	if(!a[u]) return 1;
	if(vis[u]) return can[u];
	vis[u] = 1;
	int v = (u - d + N) % N;
	can[u] = _dfs(v);
	return can[u];
}
int dfs(int u) {
	if(!a[u]) return 0;
	if(rlt[u]) return rlt[u];
	int v = (u - d + N) % N;
	rlt[u] = dfs(v) + 1;
	can[u] = can[v];
	return rlt[u];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("in.txt", "r", stdin);
//	freopen("O", "w", stdout);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int Tc;
	for (cin >> Tc; Tc--; ) {
		cin >> N >> d;
		for(int i = 0 ; i < N ; i ++) cin >> a[i], rlt[i] = 0, can[i] = 0, vis[i] = 0;
		bool valid = 1;
		for(int i = 0 ; i < N ; i ++) {
			if(!a[i]) continue;
			valid &= _dfs(i);
		}
		if(!valid) {
			cout << "-1" << endl;
			continue;
		}
		for(int i = 0 ; i < N ; i ++) rlt[i] = dfs(i);
		int ans = -1;
		for(int i = 0 ; i < N ; i ++) if(ans < rlt[i]) ans = rlt[i];
		cout << ans << endl;
		
	}
	
	return 0;
}