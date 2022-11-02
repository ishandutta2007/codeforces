#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define N 2020

const int mod = 1e9 + 7;

char s[N];
int dp[N][N], rp[N], n, k, tmp;

int main() {
///	freopen("in.txt", "r", stdin);

	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);

	dp[0][0] = 1, rp[0] = 1;

	for(int i = 1; i <= n; i ++){
		int aa = 'z' - s[i];
		if(aa){
			for(int j = i - 1; j >= 0; j --){
				tmp = (i - j) * (n + 1 - i);
				if(tmp > k) break;
				for(int t = 0; t <= k - tmp; t ++){
					dp[i][t + tmp] = (dp[i][t + tmp] + (LL)aa * dp[j][t]) % mod;
				}
			}
		}
		if(aa < 25){
			for(int t = 0; t <= k; t ++){
				dp[i][t] = (dp[i][t] + (LL)(25 - aa) * rp[t]) % mod;
			}
		}
		for(int t = 0; t <= k; t ++) rp[t] = (rp[t] + dp[i][t]) % mod;
	}
	cout << rp[k] << endl;
}