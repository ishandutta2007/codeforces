//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
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
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
ll a[63];
int n, m;
ll md;
/*
struct th {
	int r[63];
	th() {memset(r, 0, sizeof(r));}
};*/

unordered_map<ll, vi> dp[63];
unordered_map<ll, bool> hv[63];
ll qq;
vi gt(int x, ll c) { // x ~  
	if (hv[x][c]) return dp[x][c];
	hv[x][c] = 1;
	vi cur(m + 1);
	for (int i = 0; i < m + 1; i++) cur[i] = 0;
	if (x == m) {
		int cnt = 0;
		for (int j = 0; j < m; j++) 
			if (c & (1ll << j)) cnt++;
		cur[cnt]++;
	}
	else {
		if (!a[x]) cur = gt(x + 1, c);
		else {
			cur = gt(x + 1, c);
			vi um = gt(x + 1, (c ^ a[x]) & qq);
			for (int j = 1; j <= m; j++)
				cur[j] = (cur[j] + um[j - 1]) % mod;
		}
	}
	dp[x][c] = cur;
	return cur;
}
int main() {
	cin >> n >> m;
	int tt = n;
	for (int j = 0; j < n; j++) {
		ll q;
		scanf("%lld", &q);
		for (int j = m - 1; j >= 0; j--) {
			ll ns = (1ll << j);
			if (q & ns) {
				if (!a[j]) {
					a[j] = q;
					tt--;
					break;
				}
				else q ^= a[j];
			}
		} 
	} 
	md = ksm(2, tt);
	ll ur = 0;
	for (int j = m - 1; j >= 0; j--) {
		if (a[j]) {
			for (int k = j + 1; k < m; k++)
				if (a[k] & (1ll << j)) a[k] ^= a[j];
		}
		else ur += (1ll << j);
	}
	qq = ur;
	for (int i = 0; i < m; i++)	
		dp[i].rehash((1 << (m / 2))), 
		hv[i].rehash(1 << (m / 2));
	vi pq = gt(0, 0);
	for (int i = 0; i <= m; i++) {
		ll ans = pq[i] * md % mod;
		printf("%lld ", ans);
	}
	return 0;
}