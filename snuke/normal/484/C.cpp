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

const int MX = 1000005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int dx[] = {-1,0,1,0}, dy[] = {0,-1,0,1}; //<^>v

char in[MX];
string s;
int n, r, d;
vi b;

void f(int x, vi& c) {
  c.resize(r+x-1);
  if (x == 1) {
    c = b;
    return;
  }
  rep(i,c.size()) c[i] = i;
  vi a, t;
  f(x>>1,a);
  //rep(i,a.size()) printf("%d ",a[i]); puts("");
  int ci = 0, l = a.size(), y = x>>1;
  rep(i,l) c[i] = a[i];
  t = c;
  rep(i,l) c[y+i] = t[y+a[i]];
  if (x&1) {
    t = c;
    rep(i,r) c[y*2+i] = t[y*2+b[i]];
  }
}

int main(){
  int q;
  scanf("%s%d",in,&q);
  s = in;
  n = s.size();
  rep(qi,q) {
    scanf("%d%d",&r,&d);
    vi c;
    b.resize(r);
    int bi = 0;
    rep(i,d) {
      for (int j = i; j < r; j += d) b[bi++] = j;
    }
    f(n-r+1,c);
    string t = s;
    rep(i,n) s[i] = t[c[i]];
    printf("%s\n",s.c_str());
  }
  return 0;
}