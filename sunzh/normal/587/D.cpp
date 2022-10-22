#include<cstdio>
#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
#include<set>
#include<vector>
#include<cmath>
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
int n,m;
int tot;
struct edge{
	int to,nxt,col,w,num;
}e[1000010];
int head[500010];
void add(int x,int y,int c,int w,int num){
	e[++tot].nxt=head[x];head[x]=tot;
	e[tot].col=c,e[tot].to=y,e[tot].w=w,e[tot].num=num;
}
vector<int>vec[4000010];
int cnt;
int idx;
int dfn[4000010],low[4000010],belong[4000010];
int scc;
int top;
int stk[4000010];
bool vis[4000010];
void tarjan(int x){
	dfn[x]=low[x]=++idx;
	stk[++top]=x;vis[x]=1;
	for(int v:vec[x]){
		if(!dfn[v]){
			tarjan(v);
			low[x]=min(low[x],low[v]);
		}
		else if(vis[v]) low[x]=min(low[x],dfn[v]);
	}
	if(dfn[x]==low[x]){
		++scc;
		while(stk[top]!=x){
			belong[stk[top]]=scc;vis[stk[top]]=0;--top;
		}
		belong[x]=scc;--top;vis[x]=0;
	}
}
bool check(int mid){
	for(int i=1;i<=cnt;++i) vec[i].clear();
	cnt=2*m;
	for(int i=1;i<=n;++i){
		vector<int>tmp;
		set<PII>st;
		for(int j=head[i];j;j=e[j].nxt){
			if(e[j].w>mid){
				vec[e[j].num].pb(e[j].num+m);
			}
			tmp.pb(e[j].num);st.insert(mp(e[j].col,e[j].num));
		}
		int p1,p2;p1=p2=-1;
		for(int x:tmp){
			int s1=++cnt,s2=++cnt;
			if(p1!=-1) vec[p1].pb(s1),vec[s2].pb(p2),vec[p1].pb(x+m),vec[x].pb(p2);
			p1=s1,p2=s2;
			vec[x].pb(s1),vec[s2].pb(x+m);
		}
		for(auto it=st.begin();it!=st.end();++it){
			int c=it->fi;
			auto it2=it;
			vector<int>t;t.pb(it->se);
			while(1){
				++it2;
				if(it2==st.end()) break ;
				if((it2->fi)!=c) break ;
				t.pb(it2->se);
				it=it2;
			}
			int pr1,pr2;pr1=pr2=-1;
			for(int x:t){
				int s1=++cnt,s2=++cnt;
				if(pr1!=-1){
					vec[pr1].pb(s1),vec[s2].pb(pr2);vec[pr1].pb(x),vec[x+m].pb(pr2);
				}
				vec[x+m].pb(s1);vec[s2].pb(x);
				pr1=s1,pr2=s2;
			}
		}
	}
	top=0;
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));memset(vis,0,sizeof(vis));memset(belong,0,sizeof(belong));
	idx=0;scc=0;
	for(int i=1;i<=cnt;++i) if(!dfn[i]) tarjan(i);
	for(int i=1;i<=m;++i) if(belong[i]==belong[i+m]) return false ;
	return true ;
}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),col=read(),w=read();
		add(u,v,col,w,i);add(v,u,col,w,i);
	}
	cnt=2*m;
	
	
	int l=0,r=1e9;
	int res=-1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)) res=mid,r=mid-1;
		else l=mid+1;
	}
	if(res==-1){
		printf("No\n");return 0;
	}
	printf("Yes\n");
	check(res);
	vector<int>ans;
	for(int i=1;i<=m;++i) if(belong[i]<belong[i+m]) ans.pb(i);
	printf("%d %d\n",res,ans.size());
	for(int i:ans) printf("%d ",i);
}