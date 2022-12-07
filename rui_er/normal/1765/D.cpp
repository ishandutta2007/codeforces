// LUOGU_RID: 96019996
// Problem: D. Watch the Videos
// Contest: Codeforces - 2022-2023 ICPC, NERC, Southern and Volga Russian Regional Contest (Online Mirror, ICPC Rules, Preferably Teams)
// URL: https://codeforces.com/contest/1765/problem/D
// Memory Limit: 512 MB
// Time Limit: 1000 ms
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

ll n, m, a[N];
multiset<ll, greater<ll> > st;
template<typename T> void chkmin(T& x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T& x, T y) {if(x < y) x = y;}

int main() {
	scanf("%lld%lld", &n, &m);
	rep(i, 1, n) scanf("%lld", &a[i]);
	rep(i, 1, n) st.insert(a[i]);
	ll ans = 1, lst = 0;
	while(!st.empty()) {
		auto it = st.lower_bound(m-lst);
		if(it == st.end()) ++ans, lst = 0;
		else {
			lst = *it;
			st.erase(it);
		}
	}
	printf("%lld\n", accumulate(a+1, a+1+n, 0LL) + ans);
	return 0;
}