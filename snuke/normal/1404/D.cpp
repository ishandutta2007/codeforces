#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
#define rrng(a) a.rbegin(),a.rend()
#define isin(x,l,r) ((l) <= (x) && (x) < (r))
#define pb push_back
#define eb emplace_back
#define sz(x) (int)(x).size()
#define pcnt __builtin_popcountll
#define uni(x) x.erase(unique(rng(x)),x.end())
#define snuke srand((unsigned)clock()+(unsigned)time(NULL));
#define show(x) cerr<<#x<<" = "<<x<<endl;
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
int getInt(){int x;scanf("%d",&x);return x;}
template<typename T>istream& operator>>(istream&i,v(T)&v){rep(j,sz(v))i>>v[j];return i;}
template<typename T>string join(const v(T)&v){stringstream s;rep(i,sz(v))s<<' '<<v[i];return s.str().substr(1);}
template<typename T>ostream& operator<<(ostream&o,const v(T)&v){if(sz(v))o<<join(v);return o;}
template<typename T1,typename T2>istream& operator>>(istream&i,pair<T1,T2>&v){return i>>v.fi>>v.se;}
template<typename T1,typename T2>ostream& operator<<(ostream&o,const pair<T1,T2>&v){return o<<v.fi<<","<<v.se;}
template<typename T>bool mins(T& x,const T&y){if(x>y){x=y;return true;}else return false;}
template<typename T>bool maxs(T& x,const T&y){if(x<y){x=y;return true;}else return false;}
template<typename T>ll suma(const v(T)&a){ll res(0);for(auto&&x:a)res+=x;return res;}
const double eps = 1e-10;
const ll LINF = 1001002003004005006ll;
const int INF = 1001001001;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
const int MX = 200005;



int main() {
  int n;
  cin>>n;
  int n2 = n*2;
  if (n%2 == 0) {
    vi ans(n2);
    rep(i,n2) ans[i] = i%n+1;
    cout<<"First"<<endl;
    cout<<ans<<endl;
    return 0;
  }
  cout<<"Second"<<endl;
  vi a(n2);
  cin>>a;
  vvi ps(n);
  rep(i,n2) ps[a[i]-1].pb(i);
  vi to(n2);
  vi pa(n2);
  rep(i,n2) {
    int j = (i+n)%n2;
    pa[i] = j;
  }
  rep(i,n) {
    int a = ps[i][0];
    int b = ps[i][1];
    to[a] = b;
    to[b] = a;
  }
  vi used(n2);
  ll tot = 0;
  vi cho(n2);
  vi odd;
  rep(i,n2) {
    if (used[i]) continue;
    int v = i, cnt = 0;
    vi vs;
    while (!used[v]) {
      cho[v] = 1;
      tot += v+1; ++cnt;
      
      vs.pb(v);
      used[v] = 1;
      v = to[v];

      vs.pb(v);
      used[v] = 1;
      v = pa[v];
    }
    // cerr<<vs<<endl;
    if (cnt&1) odd = vs;
  }
  // cerr<<cho<<endl;
  // cerr<<odd<<endl;
  if (tot%n2) {
    for (int i : odd) {
      cho[i] ^= 1;
    }
  }

  vi ans;
  rep(i,n2) if (cho[i]) ans.pb(i+1);
  cout<<ans<<endl;
  return 0;
}