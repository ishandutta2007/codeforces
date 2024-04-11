#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
#include<map> 
#define PII pair<int,int>
#define pb push_back
#define ep emplace_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){ if(c=='-') f=-1; c=getchar();}
	while(c>='0'&&c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return f==1?x:~x+1;
}
inline void print(int x){
	if(x<0) putchar('-'),x=~x+1;
	if(x>=10) print(x/10);
	putchar((x%10)|48);
}
int n;
int a[200010];
vector<int>vec[200010];
int dfn[200010],pos[200010],siz[200010];
int idx;
int sum[200010];
int Fa[200010];
map<int,set<int> >Map;
void fail(){
	printf("0\n");exit(0);
}
void dfs(int x,int fa){Fa[x]=fa;
	dfn[x]=++idx;pos[idx]=x;siz[idx]=1;
	for(int v:vec[x]){
		if(v==fa) continue ;
		dfs(v,x);
		siz[dfn[x]]+=siz[dfn[v]];
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;++i) a[i]=read();
	for(int i=1;i<n;++i){
		int u=read(),v=read();
		vec[u].pb(v);vec[v].pb(u);if(a[u]==a[v]) fail();
	}
	dfs(1,0);for(int i=1;i<=n;++i) Map[a[i]].insert(dfn[i]);
	for(auto i:Map){
//		printf("%d %d\n",i.fi,i.se.size());
		set<int>st=i.se;
		int m=st.size();
		if(m==1) continue ;
		vector<int>nd(m+1);
		int cnt=-1;
		for(int j:st){
			nd[++cnt]=j;
		}
		nd[m]=n+1;
		int p=0;
		if(nd[1]<nd[0]+siz[nd[0]]){
			int u=pos[nd[0]];
			for(int v:vec[u]){
				if(v==Fa[u]) continue ;
				if(nd[1]<dfn[v]+siz[dfn[v]]){
//					printf("v:%d\n",v);printf("cnt:%d\n",cnt);
					if(nd[cnt]>=dfn[v]+siz[dfn[v]]) fail();
					++sum[1],--sum[dfn[v]];
					++sum[dfn[v]+siz[dfn[v]]];p=1;
					break ;
				}
			}
		}
		for(int i=p;i<=cnt;++i){
			if(nd[i+1]<nd[i]+siz[nd[i]]){
				fail();
			}
			++sum[nd[i]];--sum[nd[i]+siz[nd[i]]];
		}
	}
	int ans=0;
	int pre=0;
	for(int i=1;i<=n;++i){
		pre+=sum[i];if(pre==0) ++ans;
	}
	printf("%d\n",ans);
}