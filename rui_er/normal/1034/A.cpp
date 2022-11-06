//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const int N = 3e5+5, K = 1.5e7+5, inf = 0x3f3f3f3f;

int n, a[N], buc[K], tab[K], p[K], tot, ans = inf;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}
void sieve(int lim) {
	rep(i, 2, lim) {
		if(!tab[i]) p[++tot] = i;
		rep(j, 1, tot) {
			if(i * p[j] > lim) break;
			tab[i*p[j]] = 1;
			if(!(i % p[j])) break;
		}
	}
}

int main() {
	scanf("%d", &n);
	int g = 0, ok = 0;
	rep(i, 1, n) scanf("%d", &a[i]);
	rep(i, 1, n) g = __gcd(g, a[i]);
	rep(i, 1, n) ok |= ((a[i] /= g) > 1);
	if(!ok) return puts("-1")&0;
	rep(i, 1, n) ++buc[a[i]];
	sieve(K-5);
	rep(i, 1, tot) {
		int k = p[i], now = n;
		for(int j=k;j<=K-5;j+=k) now -= buc[j];
		chkmin(ans, now);
	}
	printf("%d\n", ans);
	return 0;
}