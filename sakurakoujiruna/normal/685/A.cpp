#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int ans = 0;
bool vis[7];
ll pow7[7];
int n, m;
int bn = 0, bm = 0;

void dfs(int x, ll sn, ll sm) {
	if(x == bn + bm && sn < n && sm < m) {
		ans ++; return;
	}
	for(int i = 0; i < 7; i ++) if(!vis[i]) {
		vis[i] = true;
		if(x < bm) dfs(x + 1, sn, sm + pow7[x] * i);
		else dfs(x + 1, sn + pow7[x - bm] * i, sm);
		vis[i] = false;
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin >> n >> m;
	for(int w = 1; w < n; w *= 7) bn ++;
	for(int w = 1; w < m; w *= 7) bm ++;
	if(n == 1) bn = 1;
	if(m == 1) bm = 1;
	pow7[0] = 1;
	for(int i = 1; i < 7; i ++)
		pow7[i] = pow7[i - 1] * 7;
	fill(vis, vis + 7, false);
	if(bn + bm <= 7) dfs(0, 0, 0);
	cout << ans << '\n';
	return 0;
}