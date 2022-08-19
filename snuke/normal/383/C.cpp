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
#include<complex>
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
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y);
#define mins(x,y) x = min(x,y);
#define adds(x,y) x = (x+(y))%mod;
#define dels(x,y) x = (x-(y)+mod)%mod;
#define muls(x,y) x = ((ll)x*(y))%mod;
#define pb push_back
#define sz(x) (int)(x).size()
#define snuke srand((unsigned)clock()+(unsigned)time(NULL))
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 200005, INF = 1000000000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

// Binary Indexed Tree
typedef int TT;
struct bit{
	vector<TT> d; int sz;
	bit(){}
	bit(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		d.resize(sz+1); init(mx);
	}
	void init(int mx, bool fil=false){
		sz = 1; while(sz < mx) sz <<= 1;
		if(fil){ rrep(i,sz) d[i] = i&-i;} else { rrep(i,sz) d[i] = 0;}
	}
	void add(int i, TT x=1){ for(;i<=sz;i+=i&-i) d[i] += x;}
	void add2(int i, int j, TT x=1){ add(i,x); add(j,-x);}
	TT sum(int i){
		TT x = 0; for(;i;i-=i&-i) x += d[i];
		return x;
	}
	TT sum2(int i, int j){ return sum(j)-sum(i);}
	int kth(int k){
		if(k > d[sz]) return -1;
		int i = sz>>1, p = 0;
		while(i){
			if(d[p+i] < k) p += i, k -= d[p];
			i >>= 1;
		}
		return p+1;
	}
};
//

int x[MX];
int vc[MX], vb[MX], k;
vi to[MX];
int h[MX];

void dfs(int v, int p){
	vc[v] = ++k;
	rep(i,to[v].size()){
		int u = to[v][i];
		if(u == p) continue;
		h[u] = -h[v];
		dfs(u,v);
	}
	vb[v] = ++k;
}

int main(){
	int n, m;
	scanf("%d%d",&n,&m);
	rrep(i,n) scanf("%d",&x[i]);
	
	int a, b;
	rep(i,n-1){
		scanf("%d%d",&a,&b);
		to[a].pb(b);
		to[b].pb(a);
	}
	
	h[1] = 1;
	dfs(1,-1);
	
	bit d(MX*2);
	
	//rrep(i,n) printf("%d ",vc[i]); puts("");
	//rrep(i,n) printf("%d ",vb[i]); puts("");
	//rrep(i,n) printf("%d ",h[i]); puts("");
	
	rep(i,m){
		scanf("%d",&a);
		if(a == 1){
			scanf("%d%d",&a,&b);
			d.add2(vc[a],vb[a],b*h[a]);
		} else {
			scanf("%d",&a);
			printf("%d\n",x[a]+d.sum(vc[a])*h[a]);
		}
	}
	
	return 0;
}