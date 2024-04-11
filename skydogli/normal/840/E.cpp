#include<bits/stdc++.h>
using namespace std;
#define MN 50005
#define LL long long
#define mp make_pair
#define fir first
#define sec second
#define pii pair<int,int>
inline void chkmax(int &a,int b){if(a<b)a=b;}
inline void chkmin(int &a,int b){if(a>b)a=b;}
inline int read(){
	   int a=0,fh=1;char c=getchar();
	   while(c>'9'||c<'0'){if(c=='-')fh=-1;c=getchar();}
	   while('0'<=c&&c<='9'){
		   a=a*10+c-48;
		   c=getchar();
	   }
	   return a*fh;
}
const int B=256,b=8;
int cnt,add[MN][2],vis[MN];
int n,q,a[MN],mx[MN][B+5],f[MN][B+5];
int dep[MN],fa[MN],lst[MN];
vector<int>edge[MN];
void init(int x){add[x][0]=add[x][1]=0;}
void Ins(int x){
	int now=0;
	for(int i=b-1;i>=0;--i){
		int op=(x>>i)&1;
		if(!add[now][op]){add[now][op]=++cnt;init(cnt);}
		now=add[now][op];
	}
}
int qry(int x,int u){
	int now=0,tmp=0,res=0;
	for(int i=b-1;i>=0;--i){
		int op=((x>>i)&1)^1;
		if(add[now][op])res+=(1<<i),now=add[now][op],tmp|=(op<<i);
		else now=add[now][!op],tmp|=((op^1)<<i);
	}
	return res<<b|mx[u][tmp];
}
void dfs(int x){
	if(dep[x]>=B){
		int v=x;
		cnt=0;init(0);
		for(int i=1;i<=B;++i){
			int tmp=a[v]>>b;
			chkmax(mx[x][tmp],((i-1)^a[v])%B);
			if(vis[tmp]!=x){vis[tmp]=x;Ins(tmp);}
			v=fa[v];
		}
		lst[x]=v;
		for(int i=1;i<=B;++i){
			f[x][i]=qry(i-1,x);
		}
	}
	for(int i=0;i<edge[x].size();++i)
		if(fa[x]!=edge[x][i]){
			fa[edge[x][i]]=x;
			dep[edge[x][i]]=dep[x]+1;
			dfs(edge[x][i]);
		}
}
int main(){
	n=read();q=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	dep[1]=1;dfs(1);
	while(q--){
		int u=read(),v=read();
		int res=0,x=v;
		for(int i=1;dep[x]-dep[u]>B;++i){
			res=max(res,f[x][i]);
			x=lst[x];
		}
		while(fa[u]!=x){
			res=max(res,a[x]^(dep[v]-dep[x]));
			x=fa[x];
		}
		printf("%d\n",res);
	}
	return 0;
}