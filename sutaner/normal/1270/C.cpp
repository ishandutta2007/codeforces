#include <bits/stdc++.h>
#define rep(i, l, r) for (register int i = l; i <= r; i++)
#define per(i, r, l) for (register int i = r; i >= l; i--)
#define srep(i, l, r) for (register int i = l; i < r; i++)
#define sper(i, r, l) for (register int i = r; i > l; i--)
#define maxn 200019
#define ll long long int 
using namespace std;

int n;
ll a[maxn];

int main(){
	//#ifndef ONLINE_JUDGE
	//	freopen("C.in", "r", stdin);
	//#endif
	int T;
	scanf("%d", &T);
	while (T--){
		scanf("%d", &n);
		ll xsum = 0, sum = 0;
		rep(i, 1, n) scanf("%lld", &a[i]), xsum ^= a[i], sum += a[i];
		sum += xsum;
		printf("2\n");
		printf("%lld %lld\n", xsum, sum);
	}
	return 0;
}