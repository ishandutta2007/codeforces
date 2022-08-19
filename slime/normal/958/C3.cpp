#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
int dp[105][maxn];
int s[maxn];
int n, k, p;
struct bt {
	int d[105];
	bt() {
		for (int i = 0; i < 105; i++) d[i] = 1e9;
	}
	void upd(int pl, int num) {
		while (pl < 105)
			d[pl] = min(d[pl], num), 
			pl += (pl & -pl);
	}
	int q(int pl) {
		int ans = 1e9;
		while (pl) {
			ans = min(ans, d[pl]);
			pl -= (pl & (-pl));
		}
		return ans;
	}
}c[2];
void upd(int a, int b) {
	if (a == 0) a = p;
//	cout << "UPD" << a << ' ' << b << endl;
	c[0].upd(a, b + a + p);
	c[1].upd(p + 1 - a, b + a);
}
int q(int a) {
	if (a == 0) a += p;
//	cout << "Q" << a << endl;
	return min(-a + c[0].q(a), c[1].q(p + 1 - a) - a);
}
int main() {
	cin >> n >> k >> p;
	for (int i = 1; i <= n; i++)
		scanf("%d", &s[i]), 
		s[i] += s[i - 1], s[i] %= p;
	for (int i = 0; i <= k; i++) {
		c[0] = c[1] = bt();
		if (i != 0) dp[i][n + 1] = 1e9;
		for (int j = n; j >= 1; j--) {
			if (i == 0) dp[i][j] = 1e9;
			else {
				upd(s[j], dp[i - 1][j + 1]);
				dp[i][j] = q(s[j - 1]);
			//	cout << i << ' ' <<j << ' ' << dp[i][j] << endl;
			}
		}
	}
	cout << dp[k][1] << endl;
	return 0;
}