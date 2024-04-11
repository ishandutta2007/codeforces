#include <cstdio>
#include <algorithm>
#include <stack>
#include <queue>
#include <deque>
#include <vector>
#include <string>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <iostream>
#include <sstream>
#include <cctype>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < n; ++i)
#define rrep(i,n) for(int i = 1; i <= n; ++i)
#define drep(i,n) for(int i = n-1; i >= 0; --i)
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

const int MX = 200005, D = 400, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

vector<P> e[MX];
P q[MX];
vector<P> p;
int ans[MX];

// Union find
struct uf{
	vector<int> d;
  vi hist;
	uf(){}
	uf(int mx):d(mx,-1){}
	int root(int x){
		if(d[x] < 0) return x;
    return root(d[x]);
	}
	void unite(int x, int y){
		x = root(x); y = root(y);
		if(x == y) return;
    if(d[x] > d[y]) swap(x,y);
    if(d[x] == d[y]) {
      hist.pb(x);
      d[x]--;
    }
    hist.pb(y);
		d[y] = x;
	}
  void rev() {
    drep(i,(int)hist.size()) {
      d[hist[i]] = -1;
    }
    hist.clear();
  }
};
//


int main(){
  int n, m;
  scanf("%d%d",&n,&m);
  rep(i,m) {
    int a, b, c;
    scanf("%d%d%d",&a,&b,&c);
    c--;
    a--; b--;
    e[c].pb(P(a,b));
  }
  int qs;
  scanf("%d",&qs);
  rep(i,qs) {
    int a, b;
    scanf("%d%d",&a,&b);
    a--; b--;
    if (a > b) swap(a,b);
    q[i] = P(a,b);
  }
  uf t(n+5);
  rep(c,m) {
    if (sz(e[c]) == 0) continue;
    for(P a : e[c]) {
      t.unite(a.fi,a.se);
    }
    if (sz(e[c]) < D) {
      vi v;
      for(P a : e[c]) {
        v.pb(a.fi);
        v.pb(a.se);
      }
      sort(rng(v));
      v.erase(unique(rng(v)),v.end());
      rep(i,v.size())rep(j,i) {
        if (t.root(v[i]) == t.root(v[j])) p.pb(P(v[j],v[i]));
      }
    } else {
      rep(qi,qs) {
        ans[qi] += (t.root(q[qi].fi) == t.root(q[qi].se));
      }
    }
    t.rev();
  }
  sort(rng(p));
  //rep(i,p.size()) printf("%d,%d ",p[i].fi,p[i].se);puts("");
  //rep(i,qs) printf("%d,%d ",q[i].fi,q[i].se);puts("");
  rep(qi,qs) {
    int res = ans[qi];
    auto it = equal_range(rng(p),q[qi]);
    res += it.se-it.fi;
    printf("%d\n",res);
  }
  return 0;
}