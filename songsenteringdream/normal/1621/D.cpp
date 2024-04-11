#include<cstdio>
#include<iostream>
using namespace std;
const int o=510,inf=2e9;
int T,n,c[o][o],x[o];long long ans=inf;
int main(){
	for(scanf("%d",&T);T--;printf("%lld\n",ans),ans=inf){
		scanf("%d",&n);
		for(int i=1;i<=2*n;++i) for(int j=1;j<=2*n;++j) scanf("%d",&c[i][j]);
		x[1]=1;x[2]=n;x[3]=n+1;x[4]=2*n;
		for(int i=1;i<5;++i) for(int j=1;j<5;++j)
			if((x[i]>n)^(x[j]>n)) ans=min(ans,(long long)c[x[i]][x[j]]);
		for(int i=2*n;i>n;--i) for(int j=2*n;j>n;--j) ans+=c[i][j];
	}
	return 0;
}