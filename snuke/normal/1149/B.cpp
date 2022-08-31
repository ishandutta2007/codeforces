#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define maxs(x,y) (x = max(x,y))
#define mins(x,y) (x = min(x,y))
#define limit(x,l,r) max(l,min(x,r))
#define lims(x,l,r) (x = max(l,min(x,r)))
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cout<<#x<<" = "<<x<<endl;
#define PQ(T) priority_queue<T,v(T),greater<T> >
#define bn(x) ((1<<x)-1)
#define dup(x,y) (((x)+(y)-1)/(y))
#define newline puts("")
#define v(T) vector<T>
#define vv(T) v(v(T))
using namespace std;
typedef long long int ll;
typedef unsigned uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
inline int in() { int x; scanf("%d",&x); return x;}
template<typename T>inline istream& operator>>(istream&i,v(T)&v)
{rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v)
{stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>inline ostream& operator<<(ostream&o,const v(T)&v)
{if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>inline istream& operator>>(istream&i,pair<T1,T2>&v)
{return i>>v.fi>>v.se;}
template<typename T1,typename T2>inline ostream& operator<<(ostream&o,const pair<T1,T2>&v)
{return o<<v.fi<<","<<v.se;}
template<typename T>inline ll suma(const v(T)& a) { ll res(0); for (auto&& x : a) res += x; return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("YES");}else{puts("NO");}
const int MX = 255;

int dp[MX][MX][MX];

int main() {
  int n,q;
  scanf("%d%d",&n,&q);
  string ss;
  cin>>ss;
  int m = 26;
  vvi ps(n+2,vi(m,n+1));
  drep(i,n) {
    int c = ss[i]-'a';
    ps[i] = ps[i+1];
    ps[i][c] = i+1;
  }
  vi s(3);
  vvi t(3);
  dp[0][0][0] = 0;
  rep(qi,q) {
    char c;
    scanf(" %c",&c);
    int x;
    scanf("%d",&x);
    --x;
    if (c == '+') {
      scanf(" %c",&c);
      c -= 'a';
      t[x].pb(c);
      s[x]++;
      int ns = s[x];
      if (x == 0) {
        rep(j,s[1]+1)rep(k,s[2]+1) {
          int now = ps[dp[ns-1][j][k]][c];
          if (j) mins(now, ps[dp[ns][j-1][k]][t[1][j-1]]);
          if (k) mins(now, ps[dp[ns][j][k-1]][t[2][k-1]]);
          dp[ns][j][k] = now;
        }
      }
      if (x == 1) {
        rep(i,s[0]+1)rep(k,s[2]+1) {
          int now = ps[dp[i][ns-1][k]][c];
          if (i) mins(now, ps[dp[i-1][ns][k]][t[0][i-1]]);
          if (k) mins(now, ps[dp[i][ns][k-1]][t[2][k-1]]);
          dp[i][ns][k] = now;
        }
      }
      if (x == 2) {
        rep(i,s[0]+1)rep(j,s[1]+1) {
          int now = ps[dp[i][j][ns-1]][c];
          if (i) mins(now, ps[dp[i-1][j][ns]][t[0][i-1]]);
          if (j) mins(now, ps[dp[i][j-1][ns]][t[1][j-1]]);
          dp[i][j][ns] = now;
        }
      }
    } else {
      t[x].pop_back();
      s[x]--;
    }
    // cerr<<int(c)<<endl;
    // rep(i,s[0]+1)rep(j,s[1]+1)rep(k,s[2]+1) printf("%d %d %d %d\n",i,j,k,dp[i][j][k]);
    puts(dp[s[0]][s[1]][s[2]]!=n+1?"YES":"NO");
  }
  return 0;
}