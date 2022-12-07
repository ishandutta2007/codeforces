#include <bits/stdc++.h>
#define maxr 100000
#define endl 1
#define maxn 400019
#define M 998244353
#define ll long long int 
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define gc() ((p1 == p2 && (p2 = (p1 = buffer) + fread(buffer, 1, maxr, stdin), p1 == p2)) ? EOF : *p1++)
using namespace std;

ll power(ll x, ll y){
	ll ans = 1, con = x;
	while (y){
		if (y & 1) ans = ans * con % M;
		con = con * con % M;
		y >>= 1;
	}
	return ans;
}
ll getinv(ll x){
	return power(x, M - 2);
}

int n, q;
int a[maxn];
bool vis[maxn];
set<int> s;
set<int> :: iterator it;
ll sufs[maxn];
ll sufm[maxn];
ll inv100;
ll ans = 0;
ll getans(int l, int r){
	return sufm[r] * (sufs[l] + M - sufs[r]) % M;
}
int main(){
	inv100 = getinv(100);
	scanf("%d%d", &n, &q);
	rep(i, 1, n) scanf("%d", &a[i]);
	s.insert(1), s.insert(n + 1);
	vis[1] = vis[n + 1] = 1;
	ll now = 1;
	per(i, n, 1){
		now = now * a[i] % M * inv100 % M;
		sufs[i] = (sufs[i + 1] + getinv(now)) % M;
	}
	ans = sufs[1];
	//printf("%lld\n", ans);
	sufm[n + 1] = 1;
	per(i, n, 1) sufm[i] = sufm[i + 1] * a[i] % M * inv100 % M;
	int x;
	rep(i, 1, q) {
		scanf("%d", &x);
		if (!vis[x]){
			vis[x] ^= 1;
			it = s.upper_bound(x);
			int r = *it;
			it--;
			int l = *it;
			ans = (ans + M - getans(l, r)) % M;
			ans = (ans + getans(l, x)) % M;
			ans = (ans + getans(x, r)) % M;
			s.insert(x);
		}
		else {
			vis[x] ^= 1;
			it = s.upper_bound(x);
			int r = *it;
			it = s.lower_bound(x);
			it--;
			int l = *it;
			ans = (ans + getans(l, r)) % M;
			ans = (ans + M - getans(l, x)) % M;
			ans = (ans + M - getans(x, r)) % M;
			s.erase(x);
		}
		printf("%lld\n", ans);
	}
    return 0;
}