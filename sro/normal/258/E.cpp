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
vector<int> nei[1<<17];
vector<int> hv[1<<17];
int bg[1<<17],en[1<<17],tmc;
int res[1<<17];

struct Segtree{
	int dt[8<<17],is[8<<17];
	void inline add(int l,int r,int x,int now=1,int nl=1,int nr=n){
		if(nl>r||nr<l)return;
		if(nl>=l&&nr<=r)dt[now]+=x;
		else{
			int m=(nl+nr)>>1;
			add(l,r,x,now<<1,nl,m);
			add(l,r,x,now<<1|1,m+1,nr);
		}
		if(dt[now])is[now]=nr-nl+1;
		else is[now]=is[now<<1]+is[now<<1|1];
	}
}seg;

void dfs(int now,int lst){
	bg[now]=++tmc;
	foreach(i,nei[now])if(*i!=lst)dfs(*i,now);
	en[now]=tmc;
}

void dfs2(int now,int lst){
	if(hv[now].size())seg.add(bg[now],en[now],1);
	foreach(i,hv[now])seg.add(bg[*i],en[*i],1);
	res[now]=max(0,seg.is[1]-1);
	foreach(i,nei[now])if(*i!=lst)dfs2(*i,now);
	if(hv[now].size())seg.add(bg[now],en[now],-1);
	foreach(i,hv[now])seg.add(bg[*i],en[*i],-1);
}

int main(){
	scanf("%d%d",&n,&m);
	cont(i,n-1){
		int a,b;scanf("%d%d",&a,&b);
		nei[a].pub(b);nei[b].pub(a);
	}
	cont(i,m){
		int a,b;scanf("%d%d",&a,&b);
		hv[a].pub(b);hv[b].pub(a);
	}
	dfs(1,0);
	dfs2(1,0);
	cont(i,n)printf("%d%c",res[i]," \n"[i==n]);
	return 0;
}