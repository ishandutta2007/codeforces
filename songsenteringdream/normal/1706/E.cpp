#include<cstdio>
#include<vector>
#include<iostream>
#include<utility>
#include<set>
using namespace std;
const int o=2e5+10;
int T,n,m,q,l[o],r[o],fa[o],b[o],ans[o];set<int> s[o];vector<pair<int,int> > chg[o];vector<int> ask[o];
int fr(int x){return fa[x]==x?x:fa[x]=fr(fa[x]);}
inline int lowbit(int x){return x&-x;}
inline void modify(int pos,int val){for(;pos<=n;pos+=lowbit(pos)) b[pos]=max(b[pos],val);}
inline int query(int pos){int res=0;for(;pos;pos-=lowbit(pos)) res=max(res,b[pos]);return res;}
int main(){
	for(scanf("%d",&T);T--;putchar('\n')){
		scanf("%d%d%d",&n,&m,&q);
		for(int i=1;i<=n;++i) s[fa[i]=i].clear(),s[i].insert(i),chg[i].clear(),ask[i].clear(),b[i]=0;
		for(int i=1,u,v,t;i<=m;++i){
			scanf("%d%d",&u,&v);
			if((u=fr(u))^(v=fr(v))){
				if(s[u].size()<s[v].size()) swap(u,v);
				for(set<int>::iterator iter,Iter=s[v].begin();Iter!=s[v].end();++Iter){
					if((iter=s[u].upper_bound(t=*Iter))!=s[u].end()) chg[t].push_back(make_pair(*iter,i));
					if((iter=s[u].lower_bound(t))!=s[u].begin()) chg[*--iter].push_back(make_pair(t,i));
				}
				for(fa[v]=u;!s[v].empty();s[v].erase(s[v].begin())) s[u].insert(*s[v].begin());
			}
		}
		for(int i=1;i<=q;++i) scanf("%d%d",&l[i],&r[i]),ask[l[i]].push_back(i);
		for(int i=n;i;--i){
			for(int j=chg[i].size();j--;) modify(chg[i][j].first,chg[i][j].second);
			for(int j=ask[i].size();j--;) ans[ask[i][j]]=query(r[ask[i][j]]);
		}
		for(int i=1;i<=q;++i) printf("%d ",ans[i]);
	}
	return 0;
}