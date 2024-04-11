//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define rep(x,y,z) for(ll x=y;x<=z;x++)
#define per(x,y,z) for(ll x=y;x>=z;x--)
#define debug printf("Running %s on line %d...\n",__FUNCTION__,__LINE__)
using namespace std;
typedef long long ll;
const ll N = 1e5+5;

ll n, a[N], b[N], id[N], sumA, sumB, chkA, chkB;
template<typename T> void chkmin(T &x, T y) {if(x > y) x = y;}
template<typename T> void chkmax(T &x, T y) {if(x < y) x = y;}

int main() {
	ll tm = clock();
	srand(time(0));
	scanf("%lld", &n);
	rep(i, 1, n) scanf("%lld", &a[i]), sumA += a[i];
	rep(i, 1, n) scanf("%lld", &b[i]), sumB += b[i];
	rep(i, 1, n) id[i] = i;
	while(1.0 * (clock() - tm) / CLOCKS_PER_SEC <= 1.85) {
		random_shuffle(id+1, id+1+n);
		chkA = 0; chkB = 0;
		rep(i, 1, n/2+1) {
			chkA += a[id[i]];
			chkB += b[id[i]];
		}
		if(chkA * 2 > sumA && chkB * 2 > sumB) {
			printf("%lld\n", n/2+1);
			rep(i, 1, n/2+1) printf("%lld%c", id[i], " \n"[i==n/2+1]);
			break;
		}
	}
	return 0;
}