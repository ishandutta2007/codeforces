#include<bits/stdc++.h>
using namespace std;
#define int long long
int read(){
	int a=0;char c=getchar();
	while(c>'9'||c<'0')c=getchar();
	while('0'<=c&&c<='9'){
		a=a*10+c-48;
		c=getchar();
	}
	return a;
}
#define MN 100005
int f[205][100005],n,m;
#define eps 1e-10
int vis[MN];
signed main(){
	n=read();m=read();
	f[0][0]=1;
	for(int i=1;i<=n;++i){
		int t=read(),x=read(),y=read();
		for(int j=0;j<=m;++j){
			if(!vis[j]&&j)continue;
			if(vis[j]<i)f[i][j]=0;
			if(f[i][j]==y)continue;
			int to=0;
			if(t==1)to=ceil(1.0*j+1.0*x/1e5-eps);
			else to=ceil(1.0*j*x/1e5-eps);
			if(to>m)continue;
		//	cerr<<"? "<<i<<" "<<j<<" "<<to<<endl;
			if(!vis[to])vis[to]=i,f[i][to]=f[i][j]+1;
		}
	}
	for(int i=1;i<=m;++i)if(vis[i])printf("%lld ",vis[i]);
	else printf("-1 ");
	return 0;
}