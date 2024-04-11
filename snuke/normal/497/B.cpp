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

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int a[2][MX];

int main(){
  int n;
  scanf("%d",&n);
  rep(i,n) {
    int x;
    scanf("%d",&x);
    a[x-1][i+1]++;
  }
  rep(i,2)rep(j,n) a[i][j+1] += a[i][j];
  vector<P> p;
  rrep(i,n) {
    int x = 0;
    vi w;
    bool ok = true;
    while (x < n) {
      int nx = n+1;
      rep(j,2) {
        int l = x-1, r = n, c;
        while (l+1<r) {
          c = (l+r)>>1;
          if (a[j][c+1]-a[j][x] < i) l = c; else r = c;
        }
        if (a[j][r+1]-a[j][x] == i) nx = min(nx,r+1);
      }
      if (nx == n+1) ok = false;
      if (a[0][nx]-a[0][x] == i) w.pb(0);
      else w.pb(1);
      x = nx;
    }
    if (!ok) continue;
    //rep(j,w.size()) printf("%d ",w[j]); puts("");
    int s = 0;
    vi cnt(2);
    rep(j,w.size()) {
      ok = false;
      cnt[w[j]]++;
      if (cnt[w[j]] > s) {
        s = cnt[w[j]];
        ok = true;
      }
    }
    if (ok) p.pb(P(s,i));
  }
  printf("%d\n",sz(p));
  sort(rng(p));
  rep(i,p.size()) printf("%d %d\n",p[i].fi,p[i].se);
  return 0;
}