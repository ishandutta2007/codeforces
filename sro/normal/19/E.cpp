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

int n,m;
vector<pair<int,int> > nei[10005];
bool lgl[10005];
int ceng[10005],col[10005],id[10005];
int fa[20][10005];
int f[10005],g[10005];
vector<int> nt,er,ans;

void inline predfs(int now,int lst,int lvl,int clr){
	ceng[now]=lvl;
	col[now]=clr;
	lgl[now]=1;
	foreach(i,nei[now])if(i->first!=lst){
		if(!lgl[i->first]){
			predfs(i->first,now,lvl+1,clr^1);
			fa[0][i->first]=now;
			id[i->first]=i->second;
		}else if(now<i->first){
			nt.pub(i->second);
			if(col[now]==col[i->first])er.pub(i->second);
		}
	}
}

int inline lca(int a,int b){
	if(ceng[a]>ceng[b])swap(a,b);
	int toup=ceng[b]-ceng[a];
	loop(i,16)if((toup>>i)&1)b=fa[i][b];
	if(a==b)return a;
	range(i,15,0,-1)if(fa[i][a]!=fa[i][b])a=fa[i][a],b=fa[i][b];
	return fa[0][a];
}

void inline dfs(int now,int lst){
	lgl[now]=1;
	foreach(i,nei[now])if(i->first!=lst){
		if(!lgl[i->first]){
			dfs(i->first,now);
			f[now]+=f[i->first];
			g[now]+=g[i->first];
		}else{
			int fa=lca(now,i->first);
			if(col[now]==col[i->first])f[now]++,f[fa]--;
			else g[now]++,g[fa]--;
		}
	}
}

int main(){
	scanf("%d%d",&n,&m);
	cont(i,m){
		int u,v;scanf("%d%d",&u,&v);
		nei[u].pub(mak(v,i));nei[v].pub(mak(u,i));
	}
	cont(i,n)if(!lgl[i])predfs(i,0,1,0);
	if(!er.size())foreach(i,nt)ans.pub(*i);
	else if(er.size()==1)ans.pub(er[0]);
	cont(i,15)cont(j,n)fa[i][j]=fa[i-1][fa[i-1][j]];
	int ers=0;
	cont(i,n)foreach(j,nei[i])if(col[i]==col[j->first])ers++;ers>>=1;
	memset(lgl,0,sizeof(lgl));
	cont(i,n)if(!lgl[i])dfs(i,0);
	cont(i,n)if(id[i]&&f[i]==ers&&!(f[i]&&g[i]))ans.pub(id[i]);
	sort(all(ans));ans.erase(unique(all(ans)),ans.end());
	printf("%d\n",(int)ans.size());
	loop(i,ans.size())printf("%d%c",ans[i]," \n"[i==ans.size()-1]);
	return 0;
}