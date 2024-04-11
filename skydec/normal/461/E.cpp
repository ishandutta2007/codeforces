#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<assert.h>
#define pb push_back
#define rep(i,j,k) for(int i=(j);i<=(int)k;i++)
#define per(i,j,k) for(int i=(j);i>=(int)k;i--)
#define lowbit(x) ((x)&(-(x)))
#define fi first
#define se second
#define pii pair<int,int>
#define VI vector<int>
#define S(x) x.size()
using namespace std;
typedef long long LL;
typedef double db;
const LL inf=((LL)1e18)+5ll;
const int N=110000;
LL n;char a[N];int m;
int go[N*35][4];int tot=1;
LL g[5][5];
void dfs(int now,int st,int dep){
	for(int i=0;i<=3;i++)if(go[now][i])dfs(go[now][i],st,dep+1);
	else{if(dep<g[st][i])g[st][i]=dep;}
}
LL A[5][5],c[5][5],b[5][5];
void lu(){
	rep(i,0,3)rep(j,0,3){
		b[i][j]=inf;
		rep(k,0,3)if(A[i][k]+A[k][j]<=b[i][j])b[i][j]=A[i][k]+A[k][j];
	}
	
	rep(i,0,3)rep(j,0,3)A[i][j]=b[i][j];
}
void pang(){
	rep(i,0,3)rep(j,0,3){
		b[i][j]=inf;
		rep(k,0,3)if(A[i][k]+c[k][j]<=b[i][j])b[i][j]=A[i][k]+c[k][j];
	}
	
	rep(i,0,3)rep(j,0,3)c[i][j]=b[i][j];
}
inline bool check(LL meach){
	memset(c,0,sizeof c);
	rep(i,0,3)rep(j,0,3)A[i][j]=g[i][j];
	for(;meach;meach>>=1,lu())if(meach&1)pang();
	LL mi=inf;
	rep(i,0,3)rep(j,0,3)if(c[i][j]<=mi)mi=c[i][j];
	return mi<n;
}
int main(){
	scanf("%I64d",&n);
	scanf("%s",a+1);m=strlen(a+1);
	rep(i,1,m){
		int now=1;
		for(int j=i;j<i+30&&j<=m;j++){
			if(!go[now][a[j]-'A'])go[now][a[j]-'A']=++tot;
			now=go[now][a[j]-'A'];
		}
	}
	rep(i,0,3)rep(j,0,3)g[i][j]=inf;
	
	rep(i,0,3)dfs(go[1][i],i,1);
	
	LL l=0;LL r=inf;LL ans=0;
	while(l<r){
		LL mid=(l+r)/2ll;
		if(check(mid-1))ans=mid,l=mid+1;
		else r=mid;
	}
	if(check(l-1))ans=l;
	printf("%I64d\n",ans);
	return 0;
}