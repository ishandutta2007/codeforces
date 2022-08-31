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
#include <numeric>
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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;

int m;
ll c[2], d[2];

int main(){
  ll h, a, x, y;
  scanf("%d",&m);
  rep(k,2) {
    scanf("%I64d%I64d%I64d%I64d",&h,&a,&x,&y);
    int cnt = 0;
    rep(i,m*3) {
      if (h == a) {
        if (cnt == 0) {
          d[k] = i;
          cnt++;
        } else {
          c[k] = i-d[k];
          cnt++;
          break;
        }
      }
      h = (h*x+y)%m;
    }
    if (cnt == 0) {
      puts("-1");
      return 0;
    }
    if (cnt == 1) c[k] = -1;
  }
  if (c[0] == -1 || c[1] == -1) {
    if (c[1] == -1) {
      swap(c[0],c[1]);
      swap(d[0],d[1]);
    }
    if (c[1] == -1) {
      if (d[0] == d[1]) cout<<d[0]<<endl;
      else cout<<-1<<endl;
    } else {
      if (d[1] > d[0] || (d[0]-d[1])%c[1]) {
        cout<<-1<<endl;
      } else cout<<d[0]<<endl;
    }
    return 0;
  }
  ll r = (d[1]-d[0]+c[1]*d[0])%c[1];
  ll ans = -1;
  for (int i = 0; i < m*3; ++i) {
    if (d[0] == d[1]) {
      ans = d[0];
      break;
    }
    if (d[0] < d[1]) {
      d[0] += c[0];
    } else {
      d[1] += c[1];
    }
  }
  cout<<ans<<endl;
  return 0;
}