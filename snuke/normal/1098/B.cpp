#include <bits/stdc++.h>
#define fi first
#define se second
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
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
const int MX = 200005;
typedef v(string) vs;

int best;
int solve(vs& s, string a, string b, bool rec=false) {
  int h = sz(s);
  int w = sz(s[0]);
  int res = 0;
  rep(i,h) {
    int now = INF;
    int bti = 0;
    rep(ti,2) {
      int cnt = 0;
      rep(j,w) cnt += (s[i][j] != a[j&1]);
      if (cnt < now) {
        now = cnt;
        bti = ti;
      }
      swap(a[0],a[1]);
    }
    if (rec) {
      if (bti) swap(a[0],a[1]);
      rep(j,w) s[i][j] = a[j&1];
    }
    res += now;
    swap(a,b);
  }
  return res;
}

int main() {
  int h,w;
  scanf("%d%d",&h,&w);
  vs s(h);
  cin>>s;

  best = INF;

  int bri = -1; string ba, bb;
  auto test = [&](int ri, string a, string b) {
    int res = solve(s, a, b);
    if (res < best) {
      best = res;
      bri = ri;
      ba = a;
      bb = b;
    }
  };

  rep(ri,2) {
    test(ri, "AG", "CT");
    test(ri, "AC", "GT");
    test(ri, "AT", "CG");
    test(ri, "CG", "AT");
    test(ri, "CT", "AG");
    test(ri, "GT", "AC");
    vs t(w, string(h, ' '));
    rep(i,h)rep(j,w) t[j][i] = s[i][j];
    swap(s,t);
    swap(h,w);
  }

  if (bri) {
    vs t(w, string(h, ' '));
    rep(i,h)rep(j,w) t[j][i] = s[i][j];
    swap(s,t);
    swap(h,w);
  }

  solve(s, ba, bb, true);

  if (bri) {
    vs t(w, string(h, ' '));
    rep(i,h)rep(j,w) t[j][i] = s[i][j];
    swap(s,t);
    swap(h,w);
  }

  rep(i,h) {
    printf("%s\n",s[i].c_str());
  }

  return 0;
}