// Problem: CF1110E Magic Stones
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1110E
// Memory Limit: 250 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//By: OIer rui_er
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=(y);x<=(z);x++)
#define per(x,y,z) for(ll x=(y);x>=(z);x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
#define fileIO(s) do{freopen(s".in","r",stdin);freopen(s".out","w",stdout);}while(false)
using namespace std;
typedef long long ll;
const ll N = 2e5+5;

ll n, a[N], b[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) scanf("%lld", &b[i]);
	if(a[1] != b[1] || a[n] != b[n]) return puts("No")&0;
	per(i, n, 2) a[i] -= a[i-1];
	per(i, n, 2) b[i] -= b[i-1];
	sort(a+2, a+1+n);
	sort(b+2, b+1+n);
	rep(i, 2, n) if(a[i] != b[i]) return puts("No")&0;
	puts("Yes");
	return 0;
}