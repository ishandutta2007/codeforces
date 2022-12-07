#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define erep(i, x) for (register int i = h[x]; i; i = e[i].next)
#define ll long long int 
#define pii pair<int, int>
#define fi first
#define se second
#define lowbit(x) (x & -x)
#define pb push_back
#define maxn 4020
#define maxm 
#define M 
using namespace std;

int n, m, k;
int a[maxn];

int main(){
	
		//freopen("A.in", "r", stdin);
		
	int T;
	scanf("%d", &T);
	while (T--){	
		scanf("%d%d%d", &n, &m, &k);
		rep(i, 1, n) scanf("%d", a + i);
		int mx = 0;
		if (m - 1 <= k){
			rep(i, 1, m) mx = max(mx, a[i]), mx = max(mx, a[n + 1 - i]);
			printf("%d\n", mx);
		}
		else {
			int rest = m - 1 - k;
			rep(l, 0, k){
				int mi = 2000000020, r = k - l;
				int lptr = l + 1, rptr = n - r - rest;
				rep(j, 0, rest){
					mi = min(mi, max(a[lptr], a[rptr]));
					lptr++, rptr++;
				} 
				mx = max(mx, mi);
			}
			printf("%d\n", mx);
		}
	}
	return 0;
}