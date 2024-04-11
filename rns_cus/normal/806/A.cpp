#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int T, x, y, p, q;
LL ans;

int main(){
//	freopen("a.in", "r", stdin);
	for(scanf("%d", &T); T --; ){
		scanf("%d %d %d %d", &x, &y, &p, &q);
		if(p == 0){
			if(x == 0) puts("0");
			else puts("-1");
			continue;
		}
		if(p == q){
			if(x == y) puts("0");
			else puts("-1");
			continue;
		}
		if(1ll * x * q >= 1ll * y * p){
			LL t = (x + p - 1) / p;
			assert(t * p - x <= t * q - y);
			ans = t * q - y;
		}
		else{
			LL a = ((LL)p * y - (LL)q * x + q - p - 1) / (q - p);
			LL t = (x + a + p - 1) / p;
			assert(t * p - x <= t * q - y);
			ans = t * q - y;
		}
		printf("%I64d\n", ans);
	}
}