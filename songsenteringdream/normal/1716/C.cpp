#include<cstdio>
#include<iostream>
using namespace std;
const int o=2e5+10,inf=1e9+o*2;
int T,m,a[2][o],b[2][o],ans;
int main(){
	for(scanf("%d",&T);T--;printf("%d\n",ans)){
		scanf("%d",&m);ans=inf;
		for(int i=0;i<2;++i) for(int j=1;j<=m;++j) scanf("%d",&a[i][j]);
		a[0][1]=-1;
		b[0][m]=max(a[0][m]+2,a[1][m]+1);b[1][m]=max(a[1][m]+2,a[0][m]+1);
		for(int i=m;--i;)
			b[0][i]=max(a[0][i]+(m-i+1)*2,max(b[0][i+1]+1,a[1][i]+1)),
			b[1][i]=max(a[1][i]+(m-i+1)*2,max(b[1][i+1]+1,a[0][i]+1));
		for(int i=1,cur=0,t=-1;i<=m;++i)
			t=max(t+1,a[cur][i]+1),ans=min(ans,max(t+(m-i+1)*2-1,b[cur][i])),cur=!cur,
			t=max(t+1,a[cur][i]+1),ans=min(ans,max(t+(m-i)*2,b[cur][i]));
	}
	return 0;
}