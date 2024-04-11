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

const int MX = 100005, INF = 1000000000, mod = 1000000007;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

int x[MX], y[MX], z[MX];
P e[MX*2];

// Segment tree (RMQ type)
struct seg{
	vector<int> d; int sz, sz2;
	seg(){}
	seg(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		sz2 = sz<<1; d.resize(sz2); init(mx);
	}
	void init(int mx){
		sz = 1; while(sz < mx) sz <<= 1;
		sz2 = sz<<1; fill(rng(d),0);
	}
	void qu(int a, int b, int x, int i=1, int l=0, int r=INF){
		if(r == INF) r = sz;
		if(a <= l && r <= b){
			d[i] += x;
			return;
		}
		if(b <= l && r <= a) return;
		int c = l+r>>1, lc = i<<1, rc = lc+1;
		if(a < c) qu(a,b,x,lc,l,c);
		if(c < b) qu(a,b,x,rc,c,r);
		if(d[lc] > 0){
			d[i] += d[lc];
			d[rc] -= d[lc];
			d[lc] = 0;
		}
		if(d[rc] > 0){
			d[i] += d[rc];
			d[lc] -= d[rc];
			d[rc] = 0;
		}
		if(d[lc] < 0 && d[rc] < 0){
			int nxt = max(d[lc],d[rc]);
			d[lc] -= nxt;
			d[rc] -= nxt;
			d[i] += nxt;
		}
		return;
	}
	int qw(){
		int i = 1;
		while(i < sz){
			i <<= 1;
			if(d[i|1] == 0) i |= 1;
		}
		return i-sz;
	}
};
//


int main(){
	int n;
	scanf("%d",&n);
	rep(i,n) scanf("%d%d%d",&x[i],&y[i],&z[i]);
	int ei = 0;
	rep(i,n){
		e[ei++] = P(x[i],i);
		e[ei++] = P(y[i],i+n);
	}
	
	sort(e,e+ei);
	
	int ans = 0, ansi = 0;
	
	seg t(3*MX);
	
	rep(i,ei){
		int ni = e[i].se%n, ne = e[i].se/n;
		
		if(!ne){ // add
			t.qu(y[ni],z[ni]+1,1);
			if(ans < t.d[1]){
				ans = t.d[1];
				ansi = i;
			}
		} else { // del
			t.qu(y[ni],z[ni]+1,-1);
		}
	}
	printf("%d\n",ans);
	
	t.init(3*MX);
	
	rep(i,ansi+1){
		int ni = e[i].se%n, ne = e[i].se/n;
		
		if(!ne){ // add
			t.qu(y[ni],z[ni]+1,1);
		} else { // del
			t.qu(y[ni],z[ni]+1,-1);
		}
	}
	
	int ap = t.qw(), al = e[ansi].fi, now = 0;
	rep(i,n){
		if(x[i] <= al && y[i] >= al && z[i] >= ap && y[i] <= ap){
			now++;
			printf("%d%c",i+1,now==ans?'\n':' ');
		}
	}
	
	return 0;
}