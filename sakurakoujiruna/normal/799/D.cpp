#include <bits/stdc++.h>
using namespace std;

const int N = 2e5L + 11, M = 1e3L + 11;

int c[N];

int p[M], q[M];
int ip[N], iq[N];

int dp[2][M][M];

void upd(int &a, int b) {
	if(!~a || a > b)
		a = b;
}

int main() {
	ios :: sync_with_stdio(0);
	int a, b, ih, iw, n; cin >> ih >> iw >> a >> b >> n;
	for(int i = 0; i < n; i ++) cin >> c[i];
	sort(c, c + n, greater<int>());
	
	int ans = -1;
	for(int _ = 0; _ < 2; _ ++) {
		int h = (ih + a - 1) / a;
		int w = (iw + b - 1) / b;
		
		int ch = 0;
		for(int i = h; i >= 1; i --)
			if(i == h || (h + i - 1) / i != p[ch]) {
				p[++ ch] = (h + i - 1) / i;
				ip[(h + i - 1) / i] = ch;
			}
		
		int cw = 0;
		for(int i = w; i >= 1; i --)
			if(i == w || (w + i - 1) / i != q[cw]) {
				q[++ cw] = (w + i - 1) / i;
				iq[(w + i - 1) / i] = cw;
			}
		/*
		for(int i = 1; i <= cw; i ++)
			cout << i << ' ' << q[i] << '\n';
		*/
		//cout << ch << ' ' << cw << '\n';
		memset(dp, -1, sizeof dp); dp[0][ip[h]][iq[w]] = 0;
		int now = 0;
		for(int i = 0; i < min(n, 40); i ++) {
			int nxt = now ^ 1;
			memset(dp[nxt], -1, sizeof dp[nxt]);
			for(int j = 1; j <= ch; j ++)
				for(int k = 1; k <= cw; k ++) if(~dp[now][j][k]) {
					//cout << i << ' ' << p[j] << ' ' << q[k] << ' ' << dp[now][j][k] << '\n';
					upd(dp[nxt][ip[(p[j] + c[i] - 1) / c[i]]][k], dp[now][j][k] + 1);
					upd(dp[nxt][j][iq[(q[k] + c[i] - 1) / c[i]]], dp[now][j][k] + 1);
					upd(dp[nxt][j][k], dp[now][j][k]);
				}
			now = nxt;
		}
		upd(ans, dp[now][1][1]);
		swap(ih, iw);
	}
	cout << ans << '\n';
}