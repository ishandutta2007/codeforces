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

struct DSU{
	int fa[1<<17];
	DSU(){loop(i,1<<17)fa[i]=i;}
	int inline root(int x){return fa[x]==x?x:(fa[x]=root(fa[x]));}
}dsu;

int n,m,q;
vector<int> nei[1<<17];
int ceng[1<<17];
int fa[20][1<<17];
int hv[1<<17],qzh[1<<17];

void inline dfs(int now){
	ceng[now]=ceng[fa[0][now]]+1;
	foreach(i,nei[now]){
		if(!ceng[*i]){
			fa[0][*i]=now;
			dfs(*i);
			if(dsu.root(*i)==dsu.root(now))hv[now]|=hv[*i];
		}else if(ceng[*i]+1<ceng[now]){
			if(!((ceng[now]^ceng[*i])&1))hv[now]=1;
			for(int j=dsu.root(now);ceng[j]>ceng[*i]+1;j=dsu.root(j))
				dsu.fa[j]=fa[0][j];
		}
	}
}

void inline dfs2(int now){
	qzh[now]+=hv[now];
	foreach(i,nei[now])if(ceng[*i]==ceng[now]+1){
		if(dsu.root(*i)==dsu.root(now))hv[*i]|=hv[now];
		qzh[*i]=qzh[now];dfs2(*i);
	}
}

int inline lca(int a,int b){
	if(ceng[a]>ceng[b])swap(a,b);
	int toup=ceng[b]-ceng[a];
	while(toup)b=fa[__builtin_ctz(toup)][b],toup&=(toup-1);
	if(a==b)return a;
	range(i,19,0,-1)if(fa[i][a]!=fa[i][b])a=fa[i][a],b=fa[i][b];
	return fa[0][a];
}

bool inline query(int a,int b){
	int c=lca(a,b);
	if(!c)return 0;
	if((ceng[a]^ceng[b])&1)return 1;
	else return qzh[a]+qzh[b]-2*qzh[c];
}

int main(){
	scanf("%d%d",&n,&m);
	cont(i,m){
		int a,b;scanf("%d%d",&a,&b);
		nei[a].pub(b);nei[b].pub(a);
	}
	cont(i,n)if(!ceng[i])dfs(i),dfs2(i);
	cont(i,19)cont(j,n)fa[i][j]=fa[i-1][fa[i-1][j]];
	scanf("%d",&q);
	while(q--){
		int a,b;scanf("%d%d",&a,&b);
		puts(query(a,b)?"Yes":"No");
	}
	return 0;
}