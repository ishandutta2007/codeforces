// LUOGU_RID: 91301997
// Problem: D1. Balance (Easy version)
// Contest: Codeforces - Codeforces Round #830 (Div. 2)
// URL: https://codeforc.es/contest/1732/problem/D1
// Memory Limit: 256 MB
// Time Limit: 3000 ms
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
const ll N = 2e5+5;

ll n;
map<ll, ll> buc, lst;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	for(scanf("%lld", &n);n;n--) {
		char op[3];
		ll x;
		scanf("%s%lld", op, &x);
		if(op[0] == '+') buc[x] = 1;
		else {
			ll ans = max(lst[x], x);
			while(buc[ans]) ans += x;
			printf("%lld\n", lst[x] = ans);
		}
	}
	return 0;
}