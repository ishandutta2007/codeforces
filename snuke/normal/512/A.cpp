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
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
inline int in() { int x; scanf("%d", &x); return x; }
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;

const int MX = 105, INF = 1000010000;
const ll LINF = 1000000000000000000ll;
const double eps = 1e-10;
const int di[] = {-1,0,1,0}, dj[] = {0,-1,0,1}; //^<v>
int n;
string s[MX];

int g[26][26];

int main(){
  cin >> n;
  rep(i,n) cin >> s[i];
  rep(j,n)rep(i,j) {
    int k = 0;
    while (k < s[i].size() && k < s[j].size()) {
      if (s[i][k] != s[j][k]) {
        g[s[i][k]-'a'][s[j][k]-'a'] = 1;
        break;
      }
      k++;
    }
    if (k < s[i].size() && k < s[j].size()) {
    } else {
      if (s[i].size() > s[j].size()) {
        puts("Impossible");
        return 0;
      }
    }
  }
  rep(k,26)rep(i,26)rep(j,26) g[i][j] |= g[i][k]&g[k][j];
  rep(i,26)rep(j,26) if (g[i][j] && g[j][i]) {
    puts("Impossible");
    return 0;
  }
  vi d;
  rep(i,26) d.pb(i);
  rep(ti,26*26){
    rep(j,26)rep(i,j) {
      if (g[d[j]][d[i]]) swap(d[i],d[j]);
    }
  }
  string s;
  rep(i,26) s += 'a'+d[i];
  cout << s << endl;
  return 0;
}