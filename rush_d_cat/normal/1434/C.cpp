#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 200000 + 10;
int t,a,b,c,d;
int main() {
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		LL ans=a;
		LL term=-a+1LL*c*b;
		if(term<0){
			printf("-1\n"); continue;
		}
		if(d>=c){
			printf("%lld\n", ans); continue;
		}
		LL k=1LL*d*b;
		LL c=a/k;
		LL res=(c+1)*a - (c*(c+1)/2)*k;
		ans=max(ans,res);
		printf("%lld\n", ans);
	}
}