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
#include<iostream>
#include<sstream>
#include<cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; i++)
#define rrep(i,n) for(int i = 1; i <= n; i++)
#define drep(i,n) for(int i = n-1; i >= 0; i--)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 300005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v
const int mod = 1000000009;

int f[MX*2], g[MX*2];

// Segment tree (RMQ type)
struct seg{
	vector<ll> d, e1, e2; int sz, sz2;
	seg(){}
	seg(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		sz2 = sz<<1; d.resize(sz2,0); e1.resize(sz2,0); e2.resize(sz2,0);
	}
	void fil(){ drep(i,sz) d[i] = d[i<<1]+d[i<<1|1];}
	void addr(int a, int b, ll x, ll y, int i=1, int l=0, int r=INF){
		if(r == INF) r = sz;
		if(a <= l && r <= b){
			e1[i] += x;
			e2[i] += y;
			return;
		}
		int nr = min(r,b);
		int nl = max(l,a);
		(d[i] += x*g[nr-nl])%=mod;
		(d[i] += y*g[nr-nl-1])%=mod;
		int c = l+r>>1;
		if(a < c) addr(a,b,x,y,i<<1,l,c);
		if(c < b) {
			ll nx = 0, ny = 0; int nc = max(0,c-max(a,l));
			(nx += x*f[nc+1])%=mod;
			(ny += x*f[nc])%=mod;
			(nx += y*f[nc])%=mod;
			if(c) (ny += y*f[nc-1])%=mod;
		  addr(a,b,nx,ny,i<<1|1,c,r);
		}
	}
	int qu(int a, int b, int i=1, int l=0, int r=INF){
		if(r == INF) r = sz;
		(d[i] += e1[i]*g[r-l])%=mod;
		(d[i] += e2[i]*g[r-l-1])%=mod;
		if (l+1 != r) {
			(e1[i<<1] += e1[i])%=mod;
			(e2[i<<1] += e2[i])%=mod;
			int c = (r-l)>>1;
			(e1[i<<1|1] += e1[i]*f[c+1])%=mod;
			(e2[i<<1|1] += e1[i]*f[c])%=mod;
			(e1[i<<1|1] += e2[i]*f[c])%=mod;
			if(c) (e2[i<<1|1] += e2[i]*f[c-1])%=mod;
		}
		e1[i] = e2[i] = 0;
		if(a <= l && r <= b) return d[i];
		int c = l+r>>1; int res = 0;
		if(a < c) (res += qu(a,b,i<<1,l,c)) %= mod;
		res %= mod;
		if(c < b) (res += qu(a,b,i<<1|1,c,r)) %= mod;
		res %= mod;
		return res;
	}
};
//

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	f[1] = f[2] = 1;
	rrep(i,n*2+5) f[i+2] = (f[i]+f[i+1])%mod;
	rep(i,n*2+5) g[i] = f[i];
	rrep(i,n*2+5) (g[i] += g[i-1]) %= mod;
	seg t(n+5);
	rep(i,n) scanf("%I64d",&t.d[t.sz+i]);
	t.fil();
	rep(j,m){
		int tp, l, r;
		scanf("%d%d%d",&tp,&l,&r);
		--l;
		if(tp == 1) {
			t.addr(l, r, 1, 0);
		} else {
			printf("%d\n",t.qu(l, r));
		}
	}
	
	return 0;
}