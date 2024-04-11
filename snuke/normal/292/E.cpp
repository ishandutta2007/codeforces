#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<string>
#include<string.h>
#include<cstdlib>
#include<ctime>
#include<cmath>
#include<map>
#include<set>
#include<bitset>
#include<iostream>
#include<sstream>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define each(c,it) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define pb push_back
#define snuke srand((unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef pair<int,P> Q;

const int MX = 100005, INF = 1000000000, mod = 1000000009;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-9;
const int dx[4] = {-1,0,1,0}, dy[4] = {0,-1,0,1}; //<^>v

// Segment tree (RMQ type)
struct seg{
	vector<ll> d; vector<P> e; int sz, sz2;
	seg(){}
	seg(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		sz2 = sz<<1; d.resize(sz2); e.resize(sz2); init(mx);
	}
	void init(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		sz2 = sz<<1; fill(rng(d),-1); fill(rng(e),P(-1,-1));
	}
	Q sch(int i){
		Q q = Q(-1,P(-1,-1));
		for(i+=sz;i>0;i>>=1) maxs(q,Q(d[i],e[i]));
		return q;
	}
	void qu(int a, int b, int x, P p, int i=1, int l=0, int r=INF){
		if(r == INF) r = sz;
		if(a <= l && r <= b){
			d[i] = x; e[i] = p;
			return;
		}
		int c = l+r>>1;
		if(a < c) qu(a,b,x,p,i<<1,l,c);
		if(c < b) qu(a,b,x,p,i<<1|1,c,r);
	}
};
//

int a[MX], b[MX];


int main(){
	int n, m, t, x, y, k; Q q;
	scanf("%d%d",&n,&m);
	
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) scanf("%d",&b[i]);
	
	seg tr(n+10);
	
	rep(i,m){
		scanf("%d",&t);
		if(t == 1){
			scanf("%d%d%d",&x,&y,&k);
			tr.qu(y,y+k,i,P(x,y));
		} else {
			scanf("%d",&k);
			q = tr.sch(k);
			if(q.fi == -1){
				printf("%d\n",b[k-1]);
			} else {
				printf("%d\n",a[k-(q.se.se-q.se.fi)-1]);
			}
		}
	}
	
	return 0;
}