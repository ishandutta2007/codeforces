#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<vector>
#include<ctime>
#include<cstring>
#include<map>
#include<cmath>
#include<queue>
#define mp make_pair
#define PII pair<int,int>
#define fi first
#define se second
#define pb push_back
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==-1?~x+1:x;
}
int n,m;
char str[400010];
int getid(int x,int y){
	return (x-1)*m+y;
}
set<int>st[400010];
vector<int>vec[400010];
int dfn[400010],low[400010],idx,top,stk[400010];
int bel[400010],cnt;
int in[400010];bool vis[400010];
void tarjan(int x){
	vis[x]=1;
	stk[++top]=x;dfn[x]=low[x]=++idx;
	for(int v:vec[x]){
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(low[x]==dfn[x]){
		++cnt;
		while(stk[top]!=x){
			vis[stk[top]]=0;
			bel[stk[top]]=cnt;--top;
		}
		bel[x]=cnt;--top;vis[x]=0;
	}
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;++i) scanf("%s",str+getid(i,1));
	// printf("%s\n",str+1);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) if(str[getid(i,j)]=='#'){
			st[j].insert(i);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) if(str[getid(i,j)]=='#'){
			auto it=st[j].upper_bound(i);if(it!=st[j].end()){
				vec[getid(i,j)].pb(getid(*it,j));
			}
			if(i>1&&str[getid(i-1,j)]=='#') vec[getid(i,j)].pb(getid(i-1,j));
			it=st[j-1].lower_bound(i);
			if(it!=st[j-1].end()){
				vec[getid(i,j)].pb(getid(*it,j-1));
			}
			it=st[j+1].lower_bound(i);
			if(it!=st[j+1].end()){
				vec[getid(i,j)].pb(getid(*it,j+1));
			}
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) if(str[getid(i,j)]=='#'&&!dfn[getid(i,j)]) tarjan(getid(i,j));
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j) if(str[getid(i,j)]=='#'){
			// printf("i:%d,j:%d,%d\n",i,j,bel[getid(i,j)]);
			for(int v:vec[getid(i,j)]){
				int u=getid(i,j);
				if(bel[u]!=bel[v]){
					++in[bel[v]];
				}
			}
		}
	}
	int ans=0;
	for(int i=1;i<=cnt;++i) (ans+=(in[i]==0));
	printf("%d\n",ans);
}