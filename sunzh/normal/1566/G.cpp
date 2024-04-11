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
#define int long long
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
struct edge{
	int u,v,w;
	friend bool operator ==(edge x,edge y){
		return x.w==y.w&&min(x.u,x.v)==min(y.u,y.v)&&max(x.u,x.v)==max(y.u,y.v);
	}
	friend bool operator <(edge x,edge y){
		return x.w==y.w?(min(x.u,x.v)==min(y.u,y.v)?max(x.u,x.v)<max(y.u,y.v):min(x.u,x.v)<min(y.u,y.v)):x.w<y.w;
	}
};
set<edge>st;
set<PII>SS;
set<PII>sa[100010],sb[100010];
map<PII,int>Map;
int ans[100010];
void del(int x){
	if(sa[x].size()==3){
		int res=0;
		auto it=sa[x].begin();
		for(int i=0;i<3;++i) res+=(*it).fi,++it;
		SS.erase(mp(res,x));
	}
	for(auto i:sa[x]){
		st.erase(edge{x,i.se,i.fi});
	}
}
void rel(int x){
	while(sa[x].size()&&sb[x].size()){
		auto it=*(--sa[x].end()),it2=*sb[x].begin();
		if(it<it2) break ;
		sa[x].erase(it);sb[x].erase(it2);sa[x].insert(it2);sb[x].insert(it);
	}
	while(sa[x].size()<3&&sb[x].size()){
		auto it=*sb[x].begin();sb[x].erase(it);sa[x].insert(it);
	}
}
void upd(int x){
	if(sa[x].size()==3){
		int res=0;
		auto it=sa[x].begin();
		for(int i=0;i<3;++i) res+=(*it).fi,++it;
		SS.insert(mp(res,x));
	}
	for(auto i:sa[x]){
		if(sa[i.se].find(mp(i.fi,x))!=sa[i.se].end()) st.insert(edge{x,i.se,i.fi});
	}
}
void add(edge e){
	int u=e.u,v=e.v,w=e.w;
	del(u);del(v);
	sb[u].insert(mp(w,v));
	sb[v].insert(mp(w,u));
	rel(u);rel(v);
	upd(u);upd(v);
}
void del(edge e){
	int u=e.u,v=e.v,w=e.w;
	del(u);del(v);
	if(sa[u].count(mp(w,v))) sa[u].erase(mp(w,v));else sb[u].erase(mp(w,v));
	if(sa[v].count(mp(w,u))) sa[v].erase(mp(w,u));else sb[v].erase(mp(w,u));
	rel(u);rel(v);
	upd(u);upd(v);
}
void solve(){
	int res=0x7f7f7f7f;
	if(SS.size()) res=(*SS.begin()).fi;
	vector<edge>V;
	int cnt=0;
	// printf("%d\n",st.size());
	while(cnt<9&&st.size()){
		// printf("cnt:%d\n",cnt);
		++cnt;V.pb(*st.begin());st.erase(st.begin());
	}
	// printf("%d\n",V.size());
	for(int i=0;i<cnt;++i){
		for(int j=i+1;j<cnt;++j){
			if(V[i].u!=V[j].u&&V[i].u!=V[j].v&&V[i].v!=V[j].u&&V[i].v!=V[j].v) res=min(res,V[i].w+V[j].w);
		}
	}
	printf("%lld\n",res);
	for(edge i:V) st.insert(i);
}
signed main(){
	n=read(),m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read(),w=read();
		if(u>v) swap(u,v);Map[mp(u,v)]=w;
		add(edge{u,v,w});
	}
	int q=read();
	solve();
	for(int i=1;i<=q;++i){
		int op=read();
		if(op==0){
			int u=read(),v=read();
			if(u>v) swap(u,v);
			del(edge{u,v,Map[mp(u,v)]});
		}
		else{
			int u=read(),v=read(),w=read();
			if(u>v) swap(u,v);
			add(edge{u,v,Map[mp(u,v)]=w});
		}
		solve();
	}
}