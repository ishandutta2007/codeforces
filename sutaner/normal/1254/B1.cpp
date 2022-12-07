#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define ll long long int 
#define maxn 200019
using namespace std;

int n;
int a[maxn];

int main(){
	#ifndef ONLINE_JUDGE
		freopen("B.in", "r", stdin);
	#endif
	scanf("%d", &n);
	ll sum = 0;
	rep(i, 1, n) scanf("%d", &a[i]), sum += a[i]; 
	if (sum == 1) {printf("-1"); return 0;}
	ll tans = -1;
	rep(i, 2, sum){
		if (sum % i == 0) {								
			ll ans = 0;
			int j = 1;
			while (j <= n){
				int rest = i;
				while (j <= n && rest){
					if (a[j] == 1) {
						if (rest <= (i >> 1)) ans += j;
						else if (rest >= ((i + 1) >> 1) + 1) ans -= j;
						rest--;
					}
					j++;
				}
			}
			tans = (tans == -1) ? ans : min(tans, ans);
		}
	}
	printf("%lld", tans);
	return 0;
}