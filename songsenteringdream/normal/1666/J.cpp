#include<cstdio>
#include<iostream>
using namespace std;
const int o=210;const long long inf=1e18;
int n,rt[o][o],fa[o];long long f[o][o],c[o][o],g[o][o];
int slv(int l,int r){
	if(l>r) return 0;
	fa[slv(l,rt[l][r]-1)]=rt[l][r];
	return fa[slv(rt[l][r]+1,r)]=rt[l][r];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) scanf("%lld",&c[i][j]),c[i][j]+=c[i][j-1];
	for(int i=1;i<=n;++i) for(int j=i;j<=n;++j) for(int k=i;k<=j;++k) g[i][j]+=c[k][n]-c[k][j]+c[k][i-1];
	for(int i=n;i;--i) for(int j=i;j<=n;++j){
		f[i][j]=inf;
		for(int k=i;k<=j;++k) f[i][j]=min(f[i][j],f[i][k-1]+f[k+1][j]);
		for(int k=i;k<=j;++k) if(f[i][k-1]+f[k+1][j]==f[i][j]) rt[i][j]=k;
		f[i][j]+=g[i][j];
	}
	slv(1,n);
	for(int i=1;i<=n;++i) printf("%d ",fa[i]);
	return 0;
}