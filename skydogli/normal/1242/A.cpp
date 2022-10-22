#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
LL n,m,q,T,a[MN];
vector<LL>p;
LL ans;
char ch[MN];
int main(){
	scanf("%lld",&n);
	LL tmp=n,G=0;
	if(n==1){puts("1");return 0;}
	for(LL i=2;i*i<=n;++i){
		if(n%i==0){
			while(n%i==0)n/=i;G=i;
			break;
		}
	}
	if(n==tmp){
		printf("%lld",n);
		return 0;
	}
	if(n==1){
		printf("%lld",G);
		return 0;
	}
	puts("1");
	return 0;
}