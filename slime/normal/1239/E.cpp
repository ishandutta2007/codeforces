#include <bits/stdc++.h>
#define ll long long
#define maxn 100005 /*rem*/
#define mod 998244353
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
int n;
int w[maxn];
ll dp[3][29], b[2][26], c[2][26];
ll ans;
int tp[maxn];
void upd() {
	if (dp[0][0] < ans) {
		ans = dp[0][0];
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < n; j++)
				c[i][j] = b[i][j];
	}
} 
ll cal() {
	int pl[2] = {0, n - 1};
	for (int i = 0; i < 2 * n; i++)
		if (tp[i] == 0) b[0][pl[0]++] = w[i];
		else b[1][pl[1]--] = w[i];
	for (int i = 1; i >= 0; i--)
		for (int j = n - 1; j >= 0; j--)
			dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]) + b[i][j];
	upd();
	return dp[0][0];
}
int main() {
	cin >> n;
	for (int i = 0; i < 2 * n; i++)
		cin >> w[i], tp[i] = (i >= n);
	sort(w, w + 2 * n); 
	ans = 1ll * maxn * maxn * maxn;
	while (1) {
		if (rand() % 100 == 0 && 1.0 * clock() / CLOCKS_PER_SEC > 1) break;
		random_shuffle(tp, tp + 2 * n);
		cal();
		ll nans = dp[0][0];
		while (1) {
			if (rand() % 1000 == 0) break;
			int fl = 0;
			for (int p1 = 0; p1 < 2 * n; p1++)
				for (int p2 = p1 + 1; p2 < 2 * n; p2++) 
					if (tp[p1] != tp[p2]) {
						swap(tp[p1], tp[p2]);
						if (cal() < nans) 
							nans = dp[0][0], fl = 1;
						else swap(tp[p1], tp[p2]);
					}
			if (!fl) break;
		}
 	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < n; j++)
			printf("%lld ", c[i][j]);
		cout << endl;
	}
	return 0;
}