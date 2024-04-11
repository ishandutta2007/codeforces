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

// KMP
struct KMP {
  vi a;
  KMP(){}
  KMP(string& s):a(sz(s)+1,-1) {
    for(int i=0,j=-1;i<s.size();a[++i]=++j)while(j>=0&&s[i]!=s[j])j=a[j];
  }
};
//

int main(){
  int n, k;
  string s;
  cin >> n >> k >> s;
  KMP d(s);
  string ans;
  rrep(i,n) {
    int r = i-d.a[i], t = i/r, w = i%r;
    char c = '0';
    if (w) {
      int b = t%k;
      int ab = (t-b)/k;
      if (ab > b) c = '1';
    } else {
      int b = t%k;
      int ab = (t-b)/k;
      if (ab >= b) c = '1';
    }
    ans += c;
  }
  cout << ans << endl;
  return 0;
}