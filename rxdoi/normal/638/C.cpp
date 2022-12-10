// by 
// program sky  :)

#include <stdio.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define pb push_back
#define x first
#define y second

using namespace std;

typedef pair<int ,int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;

inline int IN(){
	char c;Rin x=0;for(;oo<48;);
	for(;c>47;oo)x=(x<<3)+(x<<1)+c-48;return x;
}

int n,day;
VII Ed[200005];
VI an[200005];

void dfs(int u,int ff=0,int _=0){
	int t=0;
	for(PII it:Ed[u]){
		int v=it.x,e=it.y;
		if(v==ff)continue;
		if((++t)==_)++t;
		day=max(day,t);
		an[t].pb(e);
		dfs(v,u,t);
	}
}

int main(){
// say hello
	n=IN();
	rep(i,1,n){
		int u=IN(),v=IN();
		Ed[u].pb({v,i});Ed[v].pb({u,i});
	}
	dfs(1);
	printf("%d\n",day);
	For(i,1,day){
		printf("%u ",an[i].size());
		for(int e:an[i])printf("%d ",e);
		puts("");
	}
// never say goodbye
}