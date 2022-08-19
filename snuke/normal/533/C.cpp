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
#define x first
#define y second
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

P f(P a, P b) {
  int x = b.x-a.x, y = b.y-a.y;
  P r = a;
  if (x > y) {
    r.y = max(0,a.y-(x-y));
  } else {
    r.x = max(0,a.x-(y-x));
  }
  return r;
}

int distb(P a, P b) {
  if (b.x < a.x || b.y < a.y) return -1;
  return max(b.x-a.x,b.y-a.y);
}

int dista(P a, P b) {
  if (b.x < a.x || b.y < a.y) return -1;
  return (b.x-a.x)+(b.y-a.y);
}

int main(){
  P a, b;
  cin >> a.x >> a.y >> b.x >> b.y;
  P c = f(a,b);
  int db = distb(c,b);
  int da = dista(c,a);
  if (db == -1) {
    puts("Vasiliy");
    return 0;
  }
  if (da <= db) {
    puts("Polycarp");
  } else {
    puts("Vasiliy");
  }
  return 0;
}