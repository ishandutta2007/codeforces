// LUOGU_RID: 96020008
// Problem: K. Torus Path
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/K
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug(format...) fprintf(stderr, format)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 205;

ll n, a[N][N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) rep(j, 1, n) scanf("%lld", &a[i][j]);
	ll sum = 0, mn = 0x3f3f3f3f3f3f3f3fll;
	rep(i, 1, n) rep(j, 1, n) sum += a[i][j];
	rep(i, 1, n) chkmin(mn, a[i][n+1-i]);
	printf("%lld\n", sum-mn);
	return 0;
}