//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 5005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
int c[maxn][maxn];
int to(int x, int y) {
	return c[x + y][x]; 
} 
int cal(int n, int m) { //  
	ll ans = 0;
	for (int i = 1; i < n; i++) {
		ll sum = 0;
		for (int j = m - 1; j >= 1; j--) {
			ll cur = 1ll * to(j - 1, i) * to(m - j, i - 1) % mod * sum;
			ans = (ans + cur) % mod;
			cur = 1ll * to(j, n - 1 - i) * to(m - j - 1, n - i) % mod;
			sum = (sum + cur) % mod;
		}
	}
	return ans;
}
int main() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) c[i][j] = 1;
			else {
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
			}
		}
	}
	int n, m;
	cin >> n >> m;
	ll ans = cal(n, m) + cal(m, n);
	ans %= mod;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++) {
			ll cr = 1ll * to(i, j - 1) * to(i - 1, m - j) % mod * to(m - j - 1, n - i) % mod * to(n - i - 1, j);
			ans = (ans + cr) % mod;
		}
	ans *= 2;
	ans %= mod;
	if (ans < 0) ans += mod;
	cout << ans << endl;
	return 0;
}