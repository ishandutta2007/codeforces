#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <cctype>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define rrep(i,n) for (int i = 1; i <= n; ++i)
#define drep(i,n) for (int i = n-1; i >= 0; --i)
#define df(x) int x = in()
#define sz(x) int(x.size())
#define fi first
#define se second
#define rng(x) x.begin(),x.end()
#define pb push_back
#define dame {puts("No"); return 0;}
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
using namespace std;
inline int in() { int x; scanf("%d",&x); return x;}
typedef long long ll;
typedef pair<int,int> P;
typedef vector<P> vp;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<vi> vvi;

const int MX = 5005;
const int INF = 1001001001;

int n, m;
vvi to, dst;
vp p[MX];

ll f(int a, int b, ll c) {
  vector<vp> s(n);
  rep(i,n) if (dst[a][i] != INF) for (P np : p[i]) s[dst[a][i]].pb(np);
  priority_queue<P> q;
  rep(i,n) {
    for (P x : s[i]) {
      b -= x.se; c -= (ll)x.fi*x.se;
      q.push(x);
      while (b < 0) {
        P d = q.top(); q.pop();
        if (d.se <= -b) {
          b += d.se;
          c += (ll)d.fi*d.se;
        } else {
          d.se += b;
          c += ll(-b)*d.fi;
          b = 0;
          q.push(d);
        }
      }
    }
    if (b == 0 && c >= 0) return i;
  }
  return -1;
}

int main() {
  n = in(); m = in();
  to = vvi(n);
  rep(i,m) {
    df(a);
    df(b);
    --a; --b;
    to[a].pb(b);
    to[b].pb(a);
  }
  df(w);
  rep(i,w) {
    df(a);
    df(b);
    df(c);
    --a;
    p[a].pb(P(c,b));
  }
  rep(i,n) {
    vi dist(n,INF);
    queue<int> q;
    q.push(i); dist[i] = 0;
    while (sz(q)) {
      int v = q.front(); q.pop();
      for (int u : to[v]) {
        if (dist[u] == INF) {
          dist[u] = dist[v]+1;
          q.push(u);
        }
      }
    }
    dst.pb(dist);
  }
  df(q);
  rep(qi,q) {
    df(a);
    df(b);
    df(c);
    --a;
    printf("%d\n", f(a,b,c));
  }
	return 0;
}