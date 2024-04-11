#include <cstdio>
#include <cctype>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <numeric>
#include <random>
#include <chrono>
using namespace std;
#define File(s) freopen(s".in", "r", stdin), freopen(s".out", "w", stdout)

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mkp make_pair
#define pb push_back
#define SP putchar(' ')
#define EL putchar('\n')

mt19937 rnd(chrono :: steady_clock :: now().time_since_epoch().count());
mt19937_64 rnd64(chrono :: steady_clock :: now().time_since_epoch().count()) ;

template<class T> inline void gi(T &x){
  char ch; x = 0;int f = 1;
  while(isspace(ch = getchar()));
  if(ch == '-') ch = getchar(), f = -1;
  do x = x * 10 + ch - '0'; while(isdigit(ch = getchar()));
  x *= f;
}
template<class T> inline void wi(T x){
  static char stk[128]; int top = 0;
  if(x == 0) putchar('0');
  if(x < 0) putchar('-'), x = -x;
  while(x) stk[++top] = x % 10, x /= 10;
  while(top) putchar(stk[top--] + '0');
}
template<class T, class ...Args>
inline void gi(T &x, Args&... args) {gi(x); gi(args...);}
template<class T, class ...Args>
inline void wi(T x, Args... args) {wi(x); SP; wi(args...);}
template<class T> void upmax(T &x, T y) {x = x > y ? x : y;}
template<class T> void upmin(T &x, T y) {x = x < y ? x : y;}

int main(){
  int T;
  gi(T);
  while (T--) {
    int n;
    ll w;
    gi(n, w);
    vector<pair<int, int> > a(n);
    for (int i = 0; i < n; ++i) {
      int x; gi(x);
      a[i] = {x, i + 1};
    }
    sort(a.begin(), a.end());
    vector<int> res;
    ll tot = 0;
    for (auto it = a.rbegin(); it != a.rend(); ++it) {
      if (tot + it->first <= w)
        res.push_back(it->second), tot += it->first;
    }
    if (tot * 2LL < w) puts("-1");
    else {
      wi(res.size()), EL;
      for (int x : res) wi(x), SP;
      EL;
    }
  }
  return 0;
}