#include<bits/stdc++.h>
using namespace std;
#define MN 200005
#define LL long long
#define int long long
int T,n,m,a[MN];
signed main(){
	scanf("%d",&T);
	while(T--){
		scanf("%lld",&n);
		LL S=0,tmp=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a[i]);
			tmp^=a[i];
			S+=a[i];
		}
		int qwq=tmp;
		printf("2\n%lld %lld\n",tmp,S+tmp);
		/*
		tmp<<=1;
		if(tmp==S){puts("0");puts("");continue;}
		if(tmp>S){
			int d=tmp-S;
			if(!(d&1)){puts("2");printf("%lld %lld\n",d/2,d/2);}
			else{
				int a=d/2;
				if((qwq&1)){
				
				puts("2");
					printf("%lld ",qwq);
					S+=qwq;
					tmp=0;
					printf("%lld\n",S);
				}
				else printf("3\n%lld %lld 1\n",a,a);
			}
			continue;
		}
		else
		{
			int a=S-tmp;
			puts("3");
			printf("%lld %lld %lld\n",(a^qwq),(a&qwq),(a&qwq));
		}*/
	}
	return 0;
}