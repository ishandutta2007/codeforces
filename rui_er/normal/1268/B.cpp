// Problem: CF1268B Domino for Young
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1268B
// Memory Limit: 250 MB
// Time Limit: 3000 ms
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
const ll N = 3e5+5;

ll n, a[N], cnt[2];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld", &n);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		cnt[i&1] += a[i] >> 1;
		cnt[(i&1)^1] += a[i] - (a[i] >> 1);
	}
	printf("%lld\n", min(cnt[0], cnt[1]));
	return 0;
}