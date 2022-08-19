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
#include <bitset>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define gep(i,g,j) for(int i = g.head[j]; i != -1; i = g.e[i].next)
#define each(it,c) for(__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
#define rng(a) a.begin(),a.end()
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcount
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define df(x) int x = in()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}
template<typename T>istream& operator>>(istream&i,vector<T>&v){for(T&x:v)i>>x;return i;}
template<typename T>string join(vector<T>&v){stringstream s;for(T&x:v)s<<' '<<x;return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,vector<T>&v){o<<join(v);return o;}

const int MX = 100005, INF = 1001001001;
const ll LINF = 1e18;
const double eps = 1e-10;



int main() {
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(l,n)rep(r,n) if (l<=r) {
    int a = 0, b = 0;
    for (int i = l; i <= r; ++i) {
      if (s[i] == 'U') a++;
      if (s[i] == 'D') a--;
      if (s[i] == 'L') b++;
      if (s[i] == 'R') b--;
    }
    if (!a && !b) ++ans;
  }
  cout<<ans<<endl;
  return 0;
}