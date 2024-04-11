#include<bits/stdc++.h>
using namespace std;
#define MN 1005
#define ld double
int n,p[MN][MN];
bool vis[MN];
ld f[MN],prod[MN],F[MN];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j)
			scanf("%d",&p[i][j]);
	}
	for(int i=1;i<=n;++i)f[i]=1e100,prod[i]=1;
	f[n]=0;
	for(int i=1;i<=n;++i){
		int pos=0;
		for(int j=1;j<=n;++j)
			if(!vis[j]&&(!pos||f[pos]>f[j]))pos=j;
		if(!pos)break;
		vis[pos]=1;
//		cerr<<"OK: "<<pos<<" "<<f[pos]<<endl;
		for(int j=1;j<=n;++j){
			if(vis[j]||!p[j][pos])continue;
			ld pp=p[j][pos]/100.0;
			ld newf=(F[j]+prod[j]*pp*f[pos]+1.0)/(1.0-prod[j]*(1-pp));
//			cerr<<"edg "<<i<<" "<<j<<": "<<newf<<endl;
			if(newf<f[j]){
				f[j]=newf;
				F[j]+=prod[j]*pp*f[pos];
				prod[j]*=(1-pp);
			}
		}
	}
	printf("%.10lf",f[1]);
	return 0;
}