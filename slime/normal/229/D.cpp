#include <bits/stdc++.h>
#define ll long long
#define maxn 2000005 /*rem*/
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
int n;
ll h[maxn];
ll dp[maxn];
int res[maxn];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		
	}
	ll s = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) dp[i] = h[i], res[i] = 0;
		else {
			s = 0;
			for (int j = i; j >= 1; j--) {
				s += h[j];
				if (s >= dp[j - 1]) {
					dp[i] = s;
					res[i] = res[j - 1] + (i - j);
		//			cout << "??? " << i << ' ' << j << endl;
					break;
					
				}
			}
		}
	//	cout << i << ' ' << dp[i] << ' ' << res[i] << endl;
	}
	cout << res[n] << endl;
	return 0;
}