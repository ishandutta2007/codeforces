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
inline int in() { int x; scanf("%d",&x); return x;}
inline void priv(vi& a) { rep(i,sz(a)) printf("%d%c",a[i],i==sz(a)-1?'\n':' ');}

const int MX = 100005, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>

int n, m, c;
string s[55], u[55];
string t[105];

void check(int si, int sj) {
  rep(i,n)rep(j,n) {
    if (s[i][j] == '.') {
      t[c+(i-si)][c+(j-sj)] = '.';
    }
  }
}

void g(int si, int sj) {
  rep(i,n)rep(j,n) {
    if (t[c+(i-si)][c+(j-sj)] == 'x') u[i][j] = 'x';
  }
}
bool f() {
  rep(i,n) u[i] = string(n,'.');
  rep(i,n)rep(j,n) {
    if (s[i][j] == 'o') {
      g(i,j);
    }
  }
  rep(i,n)rep(j,n) {
    if (s[i][j] == 'o') u[i][j] = 'o';
  }
  rep(i,n) if (s[i] != u[i]) return false;
  return true;
}

int main(){
  cin >> n;
  rep(i,n) cin >> s[i];
  m = n*2-1; c = n-1;
  rep(i,m) t[i] = string(m,'x');
  t[c][c] = 'o';
  rep(i,n)rep(j,n) {
    if (s[i][j] == 'o') {
      check(i,j);
    }
  }
  if (!f()) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  rep(i,m) cout << t[i] << endl;
  return 0;
}