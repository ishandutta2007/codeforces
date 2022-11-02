#include<bits/stdc++.h>
#define W(xx,yy) ((xx)*m+yy)
const int N=404;
using namespace std;
int n,m,r,M,f[N*N],ans,dfn[N*N],
u,v,a[N][N];
bool test;
char mp[N][N];
int get(int x){
	return f[x]^x?f[x]=get(f[x]):x;
}
inline void uni(int u,int v){
	u=get(u),v=get(v);
	if(u==v)puts("0"),exit(0);
	f[u]=v;
}
int tpp;
inline void sol(bool d){
	r=0,memset(a,0,sizeof a);
	for(int i=0,j;i<n;i++)
	for(j=0;j<m;j++)
	if((i+j&1)^d&&f[W(i,j)]==W(i,j))r++;
	if(r<2){ans++;return;}
	r=0;tpp=0;
	for(int i=1,j;i<n;i++)
	for(j=1;j<m;j++)
	if(mp[i][j]=='*'){
	tpp++;
		if((i+j&1)^d)u=W(i-1,j-1),v=W(i,j);
		else u=W(i-1,j),v=W(i,j-1);
		u=get(u),v=get(v);
		//cerr<<"link "<<u/m<<','<<u%m<<"~"<<v/m<<','<<v%m<<endl;
		if(u==v)continue;
		if(!dfn[u])dfn[u]=++r;
		if(!dfn[v])dfn[v]=++r;
		if(r>=N){
			//if(test)cout<<"res "<<tpp<<endl;
			return;
		}
		a[u=dfn[u]][v=dfn[v]]--,
		a[v][u]--;
	}
	for(int i=0,j;i<n;i++)
	for(j=0;j<m;j++)
	if((i+j&1)^d&&!dfn[get(W(i,j))])return;
	for(int i=1,j;i<=r;i++){
		for(j=1;j<=r;j++)
		if(i^j)a[i][i]-=a[i][j];
		for(j=1;j<=r;j++)
		a[i][j]%=M;
	}
	int sum=1;
	for(int i=1,j,k;i<r;i++){
		if(!a[i][i])
		for(j=i+1;j<r;j++)
		if(a[j][i])swap(a[i],a[j]),sum=-sum;
		u=a[i][i],v=1;
		if(!u)return;
		sum=1ll*sum*u%M;
		for(k=M-2;k;k>>=1)
		k&1?v=1ll*v*u%M:0,u=1ll*u*u%M;
		for(j=i+1;j<r;j++)
		if(a[j][i]){
			u=1ll*a[j][i]*v%M;
			for(k=i;k<r;k++)
			a[j][k]=(a[j][k]-1ll*a[i][k]*u)%M;
		}
	}
	//cerr<<sum<<"?\n";
	ans+=sum;
}
int main(){
	scanf("%d%d%d",&n,&m,&M);
	n++,m++;
	for(int i=0;i<n*m;i++)f[i]=i;
	for(int i=1;i<n;i++){
		scanf("%s",mp[i]+1);
		if(n==101&&M==5&&mp[1][1]=='/')test=1;
		for(int j=1;j<m;j++)
		if(mp[i][j]=='/')
		uni(W(i-1,j),W(i,j-1));
		else if(mp[i][j]=='\\')
		uni(W(i,j),W(i-1,j-1));
	}
	sol(0),sol(1);
	printf("%d",(ans%M+M)%M);
}