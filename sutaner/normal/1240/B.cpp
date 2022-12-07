#include <bits/stdc++.h>
#define ll long long int 
#define maxn 300019
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
using namespace std;
int n, m;
int a[maxn], b[maxn];
int l[maxn], r[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		rep(i, 1, n) scanf("%d", &a[i]), b[i] = a[i];
		sort(b + 1, b + 1 + n);
		int m = unique(b + 1, b + 1 + n) - b - 1;
		if (m == 1) {
			printf("0\n");
			continue;
		}
		rep(i, 1, n) a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
		per(i, n, 1) l[a[i]] = i; 
		rep(i, 1, n) r[a[i]] = i;
		int ans = n + 1;
		srep(i, 1, m){
			int _i = i;
			while (i < m && l[i + 1] > r[i]) i++;
			ans = min(ans, m - (i - _i + 1));
		}
		printf("%d\n", ans);
		/*bool f = 1;
		per(i, m - 1, 1){
			if (r[i] > l[i + 1]){
				ans = min(ans, i);
				f = 0;
				break;
			}
		}
		if (f) ans = 0;
		
		f = 1;
		rep(i, 2, m){
			if (l[i] < r[i - 1]){
				ans = min(ans, m - i + 1);
				f = 0;
				break;
			}
		}
		if (f) ans = 0;*/
		
		//printf("%d\n", ans);
	}
	return 0;
}