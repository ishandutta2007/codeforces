#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-1;c=getchar();}
	while(isdigit(c)) {x=(x<<1)+(x<<3)+(c^48);c=getchar();}
	return x*f;
}

struct node{
	int a[2][2];
}f[500010],g[500010];
int n;
vector<int>to[500010];
int siz[500010];
long long ans;
node trans(node x,node y){
	node z;
	z.a[0][0]=x.a[0][0]*y.a[1][0];
	z.a[0][1]=x.a[0][1]*y.a[1][0]+x.a[0][0]*(y.a[1][1]+y.a[0][0]);
	z.a[1][0]=x.a[0][0]*y.a[0][0]+x.a[1][0]*y.a[1][0];
	z.a[1][1]=x.a[1][1]*y.a[1][0]+x.a[1][0]*(y.a[1][1]+y.a[0][0])+x.a[0][1]*y.a[0][0]+x.a[0][0]*y.a[0][1];
	return z;
}
void dfs(int x,int fa){
	siz[x]=1;f[x].a[0][0]=1;
	vector<int>::iterator it;
	for(it=to[x].begin();it!=to[x].end();++it){
		int v=(*it);
		if(v==fa){
			to[x].erase(it);break ;
		}
	}
	for(int i=0;i<to[x].size();++i){
		int v=to[x][i];
		dfs(v,x);
		siz[x]+=siz[v]; 
		f[x]=trans(f[x],f[v]);
	}
}
node merge(node x,node y){
	node z;
	z.a[0][0]=x.a[0][0]*y.a[0][0];
	z.a[0][1]=x.a[0][0]*y.a[0][1]+x.a[0][1]*y.a[0][0];
	z.a[1][0]=x.a[0][0]*y.a[1][0]+x.a[1][0]*y.a[0][0];
	z.a[1][1]=x.a[0][0]*y.a[1][1]+x.a[1][1]*y.a[0][0]+x.a[1][0]*y.a[0][1]+x.a[0][1]*y.a[1][0];
	return z;
}
vector<node>vec[500010];
void dfs1(int x,int fa){
//	node sum=g[x];if(x==1) sum.a[0][0]=1;
	node sum; sum.a[0][0]=1;sum.a[1][1]=sum.a[1][0]=sum.a[0][1]=0;
	if(x!=1) sum=trans(sum,g[x]);
//	
	vec[x].push_back(sum);
	for(int i=0;i<to[x].size();++i){
		int v=to[x][i];
		sum=trans(sum,f[v]);
		vec[x].push_back(sum);
	}
	sum.a[0][0]=1,sum.a[0][1]=sum.a[1][0]=sum.a[1][1]=0;
	for(int i=to[x].size()-1;i>=0;--i){
		int v=to[x][i];
		g[v]=merge(vec[x][i],sum);
		sum=trans(sum,f[v]);
		dfs1(v,x);
	}
}
int main(){
	n=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		to[u].push_back(v),to[v].push_back(u);
	}
	if(n&1){
		printf("0\n");
		return 0;
	}
	dfs(1,0);
	dfs1(1,0);
	for(int i=2;i<=n;++i){
		if(siz[i]&1) ans+=1ll*(f[i].a[1][1]+f[i].a[0][0])*(g[i].a[1][1]+g[i].a[0][0]);
		else if(f[i].a[1][0]>0&&g[i].a[1][0]>0) ans+=1ll*siz[i]*(n-siz[i]);
	}
	printf("%lld\n",ans);
	return 0;
}