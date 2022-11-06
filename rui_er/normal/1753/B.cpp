// LUOGU_RID: 91302122
// Problem: B. Factorial Divisibility
// Contest: Codeforces - Codeforces Round #829 (Div. 1)
// URL: https://codeforc.es/contest/1753/problem/B
// Memory Limit: 256 MB
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
const ll N = 5e5+5;

ll n, x, a[N], cnt[N];
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &x);
	rep(i, 1, n) {
		scanf("%lld", &a[i]);
		++cnt[a[i]];
	}
	rep(i, 1, x-1) {
		int carry = cnt[i] / (i + 1);
		cnt[i+1] += carry;
		cnt[i] %= i + 1;
		if(cnt[i]) return puts("No")&0;
	}
	puts("Yes");
	return 0;
}