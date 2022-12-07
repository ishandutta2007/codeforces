#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 
#define ll long long int 
using namespace std;

int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("A.in", "r", stdin);
	//#endif
	int mx1 = 0, mx2 = 0, n, k1, k2, x;
	int T;
	scanf("%d", &T);
	while (T--){
		mx1 = 0, mx2 = 0;
		scanf("%d%d%d", &n, &k1, &k2);
		rep(i, 1, k1) scanf("%d", &x), mx1 = max(mx1, x);
		rep(i, 1, k2) scanf("%d", &x), mx2 = max(mx2, x);
		if (mx1 > mx2) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}