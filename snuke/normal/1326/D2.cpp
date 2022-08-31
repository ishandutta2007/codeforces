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
#define eb emplace_back
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
typedef tuple<int,int,int> T;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
typedef vector<T> vt;
inline int getInt() { int x; scanf("%d",&x); return x;}
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
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;

// Manacher
struct manacher {
  string s; vi r;
  manacher(){}
  manacher(string &s):s(s){}
  void dbl(){
    int n = sz(s);
    string t = s;
    s = string((n<<1)+1,'$');
    rep(i,n) s[i<<1|1] = t[i];
  }
  void init(){
    int n = sz(s); r.resize(n);
    for(int i=0,j=0;i<n;) {
      while(i>=j&&i+j<n&&s[i-j]==s[i+j])++j;
      r[i] = j; int k = 1;
      while(k<j&&k+r[i-k]<j)r[i+k]=r[i-k],++k;
      i+=k; j-=k;
    }
  }
  int& operator[](int i) { return r[i];}
};
//



int main() {
  int ts;
  cin>>ts;
  rep(ti,ts) {
    string s;
    cin>>s;
    int n = sz(s);
    manacher g(s);
    int mx = 0;
    while (mx*2 < n) {
      if (s[mx] != s[n-mx-1]) break;
      ++mx;
    }
    g.dbl();
    g.init();
    P best(0,0);
    rep(i,n*2+1) {
      int l = i-g[i]; l = (l-1)/2;
      int r = i+g[i]; r /= 2;
      int w = min(l+1, n-r);
      if (w > mx) continue;
      maxs(best, P(w*2+(r-l-1), i));
    }
    string ans;
    {
      int i = best.se;
      int l = i-g[i]; l = (l-1)/2;
      int r = i+g[i]; r /= 2;
      int w = min(l+1, n-r);
      ans += s.substr(0,w);
      ans += s.substr(l+1, r-l-1);
      ans += s.substr(n-w);
    }
    cout<<ans<<endl;
    // cout<<sz(ans)<<endl;
  }
  return 0;
}