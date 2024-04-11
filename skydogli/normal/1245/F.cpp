#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 35
LL f[N+5][2][2];
int T,l,r;
LL calc(LL a,LL b){
	if(a<0||b<0)return 0;
	memset(f,0,sizeof(f));
	f[N][1][1]=1;
	for(int i=N-1;i>=0;--i){
		for(int j=0;j<2;++j)
			for(int k=0;k<2;++k){
				bool nexj=(j&&!((a>>i)&1ll)),nexk=(k&&!((b>>i)&1ll));
				f[i][nexj][nexk]+=f[i+1][j][k];
				//cover 0
				if(((a>>i)&1)||!j) f[i][j][nexk]+=f[i+1][j][k];
				if(((b>>i)&1)||!k) f[i][nexj][k]+=f[i+1][j][k];
			}
	}
	return f[0][0][0]+f[0][1][0]+f[0][0][1]+f[0][1][1];
}
signed main()
{
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&l,&r);
		printf("%lld\n",calc(r,r)-calc(l-1,r)*2ll+calc(l-1,l-1));
	}
	return 0;
}