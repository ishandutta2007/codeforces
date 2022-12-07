#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 2000019
#define maxp 2000019
using namespace std;

int n;
ll a[maxn], _a[maxn];


bool vis[maxp];
int p[maxp];
int cnt = 0;
void init(){	
	srep(i, 2, maxp){
		if (!vis[i]) p[++cnt] = i;
		rep(j, 1, cnt){
			if (i * p[j] >= maxp) break;
			vis[i * p[j]] = 1;
			if (i % p[j] == 0) break;
		}
	}
}

ll tans = -1;
void play(ll i){
	ll ans = 0;
	rep(j, 1, n) _a[j] = a[j] % i;
	ll j = 1;
	while (j <= n){
		ll rest = 1, kk;
		while (j <= n && rest <= i){
			if (_a[j] && rest <= (i >> 1)) kk = min((i >> 1) - rest + 1, _a[j]), ans -= j * kk, _a[j] -= kk, rest += kk;
			if (_a[j] && (i & 1) && rest == (i >> 1) + 1) _a[j]--, rest++;
			if (_a[j] && rest >= ((i + 1) >> 1) + 1) kk = min(i - rest + 1, _a[j]), ans += j * kk, _a[j] -= kk, rest += kk;
			if (!_a[j]) j++;
		}
	}
	//return ans;
	tans = (tans == -1) ? ans : min(tans, ans);
}

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	init();
	scanf("%d", &n);
	ll sum = 0;
	rep(i, 1, n) scanf("%lld", &a[i]), sum += a[i]; 
	if (sum == 1) {printf("-1"); return 0;}
	//ll tans = -1;
	rep(x, 1, cnt){
		ll i = p[x];
		if ((ll)i * i > sum) break;
		if (sum % i == 0) {	
			while (sum % i == 0) sum /= i;
			play(i);
		}
	}
	if (sum > 1) play(sum);
	printf("%lld", tans);
	return 0;
}