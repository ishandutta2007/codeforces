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

struct Segnode{
	int mn,mx,tag;
	friend Segnode inline operator+(const Segnode &a,const Segnode &b){
		Segnode res;
		res.mn=min(a.mn,b.mn);
		res.mx=max(a.mx,b.mx);
		res.tag=a.tag&b.tag&(a.mn>b.mx);
		return res;
	}
};

const int maxn=1<<18;

struct Segtree{
	Segnode t[maxn<<1];
	Segtree(){loop(i,maxn<<1)t[i].mn=Inf,t[i].mx=-Inf,t[i].tag=1;}
	void change(int a,Segnode x){
		a+=maxn;t[a]=x;
		while(a>>=1)t[a]=t[a<<1]+t[a<<1|1];
	}
}seg;

int n,m,q;
set<pair<int,int> > ts[2];
set<int> ids[2][1<<18];

Segnode inline getnode(int x){
	Segnode res;
	res.mn=!ids[0][x].size()?Inf:*ids[0][x].begin();
	res.mx=!ids[1][x].size()?-Inf:*ids[1][x].rbegin();
	res.tag=(res.mn>res.mx);
	return res;
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	while(q--){
		int x,y;scanf("%d%d",&x,&y);x--,y--;
		int lx=x&1;x>>=1;y>>=1;
		if(ts[lx].count(mak(x,y)))ts[lx].erase(mak(x,y)),ids[lx][x].erase(y),seg.change(x,getnode(x));
		else ts[lx].insert(mak(x,y)),ids[lx][x].insert(y),seg.change(x,getnode(x));
		puts(seg.t[1].tag?"YES":"NO");
	}
	return 0;
}