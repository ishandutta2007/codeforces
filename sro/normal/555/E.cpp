/* by Natsu Kinmoe */
#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(),(x).end()
#define loop(i,n) for(int i=0;i<(n);i++)
#define cont(i,n) for(int i=1;i<=(n);i++)
#define circ(i,a,b) for(int i=(a);i<=(b);i++)
#define range(i,a,b,c) for(int i=(a);((c)>0?i<=(b):i>=(b));i+=(c))
#define foreach(it,v) for(__typeof((v).begin()) it=(v).begin(),_e_D_=(v).end();it!=_e_D_;it++)
#define y0 y0O0OO00OO0OO0OO0OOO00OO0OO0O0O000OO0
#define y1 y1II11II11III11I1III11II111IIII1II1I1
#define pub push_back
#define pob pop_back
#define mak make_pair

typedef long long ll;
typedef long double lf;
const int Inf=0x3f3f3f3f;
const ll INF=0x3f3f3f3f3f3f3f3fll;
/* Source code starts here */

int n,m,q;
int u[1<<18],v[1<<18],s[1<<18],t[1<<18];
vector<pair<int,int> > nei[1<<18];
int fa[1<<18],fg[1<<18],fr[20][1<<18];
int dfn[1<<18],low[1<<18],tmc;
vector<int> gur,son[1<<18],hv[1<<18];
set<int> gs;
int ids;
bool lgl[1<<18];
int bl[1<<18],in[1<<18],out[1<<18],ceng[1<<18];
multiset<int> ups,dns;

void inline tarjan(int now,int lst,int egs){
	fa[now]=lst;fg[now]=egs;
	dfn[now]=low[now]=++tmc;
	foreach(i,nei[now]){
		if(!dfn[i->first]){
			tarjan(i->first,now,i->second);
			low[now]=min(low[now],low[i->first]);
		}else if(i->second!=egs){
			low[now]=min(low[now],dfn[i->first]);
		}
	}
}

void inline dfs(int now,int lst,int lid){
	bl[now]=lid;lgl[now]=1;
	foreach(i,nei[now])if(fg[i->first]==i->second){
		if(gs.count(i->second))son[lid].pub(++ids),dfs(i->first,now,ids);
		else dfs(i->first,now,lid);
	}
}

void inline dfs2(int now){
	in[now]=++tmc;lgl[now]=1;
	foreach(i,son[now]){
		fr[0][*i]=now;
		ceng[*i]=ceng[now]+1;
		dfs2(*i);
	}
	out[now]=++tmc;
}

int inline lca(int a,int b){
	if(ceng[a]>ceng[b])swap(a,b);
	int toup=ceng[b]-ceng[a];
	while(toup)b=fr[__builtin_ctz(toup)][b],toup&=toup-1;
	if(a==b)return a;
	range(i,19,0,-1)if(fr[i][a]!=fr[i][b])a=fr[i][a],b=fr[i][b];
	return fr[0][a];
}

void inline dfs3(int now){
	lgl[now]=1;
	bool up=0,dn=0;
	multiset<int>::iterator it=ups.lower_bound(in[now]);
	if(it!=ups.end()&&*it<=out[now])up=1;
	it=dns.lower_bound(in[now]);
	if(it!=dns.end()&&*it<=out[now])dn=1;
	if(up&&dn)exit(0&puts("No"));
	foreach(i,hv[now]){
		ups.insert(in[s[*i]]);
		dns.insert(in[t[*i]]);
	}
	foreach(i,son[now])dfs3(*i);
	foreach(i,hv[now]){
		ups.erase(ups.find(in[s[*i]]));
		dns.erase(dns.find(in[t[*i]]));
	}
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	cont(i,m){
		scanf("%d%d",u+i,v+i);
		nei[u[i]].pub(mak(v[i],i));
		nei[v[i]].pub(mak(u[i],i));
	}
	cont(i,q)scanf("%d%d",s+i,t+i);
	cont(i,n)if(!dfn[i])tarjan(i,0,-1);
	cont(i,m){
		if(fa[u[i]]==v[i])swap(u[i],v[i]);
		if(fa[v[i]]==u[i]&&low[v[i]]>dfn[u[i]]){
			gur.pub(i);
			gs.insert(i);
		}
	}
	cont(i,n)if(!lgl[i])dfs(i,0,++ids);
	memset(lgl,0,sizeof(lgl));tmc=0;
	cont(i,ids)if(!lgl[i])dfs2(i);
	cont(i,19)cont(j,ids)fr[i][j]=fr[i-1][fr[i-1][j]];
	cont(i,q){
		s[i]=bl[s[i]];t[i]=bl[t[i]];
		if(s[i]==t[i])continue;
		int th=lca(s[i],t[i]);
		if(!th)return 0&puts("No");
		hv[th].pub(i);
	}
	memset(lgl,0,sizeof(lgl));
	cont(i,ids)if(!lgl[i])dfs3(i);
	return 0&puts("Yes");
}