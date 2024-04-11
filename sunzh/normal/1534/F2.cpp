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
int dp[400010];
bool reachable[400010],imp[400010];
vector<int>edg[400010];
set<PII>s;
int a[400010];
PII val[400010];
void pus(PII &x,PII y){
	if(y.fi==0) return ;
	if(x.fi==0) x=y;
	else x.fi=min(x.fi,y.fi),x.se=max(x.se,y.se);
}
vector<int>tmp[400010];
void insert(PII x){
	// printf("%d %d\n",x.fi,x.se);
	tmp[x.se].pb(x.fi);
}
int tre[400010];
void upd(int x,int k){
	while(x){
		tre[x]=min(tre[x],k);x-=x&-x;
	}
}
int qry(int x){
	int res=0x3f3f3f3f;
	while(x<=m+1){
		res=min(res,tre[x]);x+=x&-x;
	}
	return res;
}
void getans(){
	dp[1]=0;upd(1,0);
	for(int i=2;i<=m+1;++i){
		if(!a[i-1]) dp[i]=dp[i-1];
		else{
			dp[i]=0x3f3f3f3f;
			for(int j:tmp[i-1]){
				dp[i]=min(dp[i],qry(j)+1);
			}
		}
		upd(i,dp[i]);
	}
	dp[m]=dp[m+1];
}
int main(){
	memset(tre,0x3f,sizeof(tre));
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
			// printf("i:%d,j:%d,bel:%d\n",i,j,bel[getid(i,j)]);
			// printf("i:%d,j:%d,%d\n",i,j,bel[getid(i,j)]);
			for(int v:vec[getid(i,j)]){
				int u=getid(i,j);
				if(bel[u]!=bel[v]){
					if(!s.count(mp(bel[u],bel[v]))){
						edg[bel[u]].pb(bel[v]);
						// printf("%d %d\n",bel[u],bel[v]);
						s.insert(mp(bel[u],bel[v]));
					}
				}
			}
		}
	}
	for(int i=1;i<=m;++i){
		a[i]=read();
		int x=a[i];if(!x) continue ;
		for(int j=n;j>=1;--j) if(str[getid(j,i)]=='#'){
			--x;if(!x){
				imp[bel[getid(j,i)]]=1;
				pus(val[bel[getid(j,i)]],mp(i,i));
				break ;
			}
		}
	}
	for(int i=cnt;i>=1;--i)if(imp[i]||reachable[i]){
		// printf("i:%d\n",i);
		for(int j:edg[i]){
			reachable[j]=1;
		}
	}
	for(int i=1;i<=m;++i){
		int x=a[i];if(!x) continue ;
		for(int j=n;j>=1;--j) if(str[getid(j,i)]=='#'){
			--x;if(!x){
				if(reachable[bel[getid(j,i)]]) a[i]=0;
				break ;
			}
		}
	}
	for(int i=1;i<=cnt;++i) if(!reachable[i]) {
		for(int j:edg[i]) if(!reachable[j]) pus(val[i],val[j]);
		insert(val[i]);
	}
	getans();
	printf("%d\n",dp[m]);
}