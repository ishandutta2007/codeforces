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
const int N=210000;
int dep[N];int fa[22][N];int size[N];int n,m;
vector<int>p[N];
void dfs(int x){
	size[x]=1;dep[x]=dep[fa[0][x]]+1;
	rep(i,0,p[x].size()-1)if(p[x][i]!=fa[0][x]){
		fa[0][p[x][i]]=x;
		dfs(p[x][i]);
		size[x]+=size[p[x][i]];
	}
}
int lca(int a,int b){
	if(dep[a]<dep[b])swap(a,b);
	per(k,20,0)if((1<<k)&(dep[a]-dep[b]))a=fa[k][a];
	
	if(a==b)return a;
	
	per(k,20,0)if(fa[k][a]!=fa[k][b]){
		a=fa[k][a];
		b=fa[k][b];
	}
	return fa[0][a];
}
int getfa(int x,int v){
	per(k,20,0)if((1<<k)&v)x=fa[k][x];
	return x;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n-1){
		int a,b;scanf("%d%d",&a,&b);
		p[a].pb(b);p[b].pb(a);
	}
	dfs(1);
	rep(i,1,20)rep(j,1,n)fa[i][j]=fa[i-1][fa[i-1][j]];
	scanf("%d",&m);
	while(m--){
		int a,b;scanf("%d%d",&a,&b);
		
		if(a==b){
			printf("%d\n",n);
			continue;
		}
		
		int pa=lca(a,b);
		
		if((dep[a]+dep[b]-2*dep[pa])&1){
			printf("0\n");
			continue;
		}
		
		int md=(dep[a]+dep[b]-2*dep[pa])/2;
		//printf("%d %d %d %d\n",dep[a],dep[b],dep[pa],md);
		if(dep[a]-md>dep[pa]){
			int gt=getfa(a,md);
			int gt2=getfa(a,md-1);
			printf("%d\n",size[gt]-size[gt2]);
		}
		else if(dep[a]-md==dep[pa]){
			int gt1=getfa(a,md-1);
			int gt2=getfa(b,md-1);
			printf("%d\n",n-size[pa]+size[pa]-size[gt1]-size[gt2]);
		}
		else{
			swap(a,b);
			int gt=getfa(a,md);
			int gt2=getfa(a,md-1);
			printf("%d\n",size[gt]-size[gt2]);
		}
	}
	return 0;
}