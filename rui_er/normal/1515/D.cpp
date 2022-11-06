//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
#define loop while(true)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define fil(x,y) memset(x, y, sizeof(x))
#define cpy(x,y) memcpy(x, y, sizeof(y))
#define mulT0 int T; for(scanf("%d", &T);T;T--)
#define mulT1 int T, rnds; for(scanf("%d", &T),rnds=1;rnds<=T;rnds++)
using namespace std;
typedef long long ll;
const int N = 2e5+5;

int n, l, r, a[N], L[N], R[N];

int main() {
	mulT0 {
		scanf("%d%d%d", &n, &l, &r);
		rep(i, 1, n) scanf("%d", &a[i]);
		rep(i, 1, n) L[i] = R[i] = 0;
		rep(i, 1, l) ++L[a[i]];
		rep(i, l+1, n) ++R[a[i]];
		int Lres = 0, Rres = 0;
		rep(i, 1, n) {
			int mx = min(L[i], R[i]);
			L[i] -= mx; R[i] -= mx;
			Lres += L[i]; Rres += R[i]; 
		}
		if(Lres == Rres) printf("%d\n", Lres);
		else if(Lres < Rres) {
			int ans = 0;
			rep(i, l+1, n) {
				if(R[a[i]] > 1) {
					int qwq = min(R[a[i]]/2, (Rres-Lres)/2);
					ans += qwq;
					R[a[i]] -= 2 * qwq;
					Rres -= 2 * qwq;
//					printf("qwq=%d ans=%d Rres=%d\n", qwq, ans, Rres);
				}
				if(Lres == Rres) break;
			}
			ans += Rres;
			printf("%d\n", ans);
		}
		else {
			int ans = 0;
			rep(i, 1, l) {
				if(L[a[i]] > 1) {
					int qwq = min(L[a[i]]/2, (Lres-Rres)/2);
					ans += qwq;
					L[a[i]] -= 2 * qwq;
					Lres -= 2 * qwq;
				}
				if(Lres == Rres) break;
			}
			ans += Lres;
			printf("%d\n", ans);
		}
	}
	return 0;
}