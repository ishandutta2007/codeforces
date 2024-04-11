#include <bits/stdc++.h>
#define ll long long
#define maxn 1000005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll jc[maxn], bjc[maxn];
char inp[maxn];
int cnt[3][maxn];

ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int q(int tp, int l, int r) {
	return cnt[tp][r] - cnt[tp][l - 1];
}
ll c(int a, int b) {
	if (a < b) return 0;
	return jc[a] * bjc[b] % mod * bjc[a - b] % mod;
}
ll s[2][maxn];
int main() {
	scanf("%s", inp + 1);
	jc[0] = bjc[0] = 1;
	for (int i = 1; i < maxn; i++)
		jc[i] = jc[i - 1] * i % mod, 
		bjc[i] = ksm(jc[i], mod - 2);
	int l = strlen(inp+ 1);
	for (int i = 1; i <= l; i++) {
		for (int j = 0; j < 3; j++)
			cnt[j][i] = cnt[j][i - 1];
		if (inp[i] == '(') cnt[0][i]++;
		else if (inp[i] == ')') cnt[2][i]++;
		else cnt[1][i]++;
	}
	int sm = q(1, 1, l);
	for (int j = 0; j < 2; j++) {
		int ns = sm - j;
		for (int q = 0; q < maxn; q++)
			s[j][q] = c(ns, q);
		for (int q = maxn - 2; q >= 0; q--) 
			s[j][q] = (s[j][q] + s[j][q + 1]) % mod;
	}
	ll ans = 0;
	for (int i = 1; i <= l; i++) {
		if (inp[i] == '(') continue;
		else {
			int u = q(1, 1, i - 1);
			int v = q(1, i + 1, l);
			int ldis = 1 + q(2, i + 1, l) - q(0, 1, i - 1);
			ldis += v;
			u += v;
		//	cout << i << ' ' << u << ' ' << v << ' ' << ldis << endl;
			ans += s[q(1, 1, l) - u][max(ldis, 0)];
			ans %= mod;
		}
	}
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}