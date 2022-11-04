#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back
using namespace std;
typedef double DO;
typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> pii;

const int inf=0x3f3f3f3f, mod=1000000007;
const LL INF=0x3f3f3f3f3f3f3f3fLL;
const DO pi=acosl(-1.), eps=1e-9;

int power(int a, int b, int m=mod, int ans=1) {
  for(; b; b>>=1, a=(LL)a*a%m) if (b&1) ans=(LL)ans*a%m;
  return ans;
}

const int NN = 2e5+10;
VI adj[NN];
int da[NN], db[NN];
int n, m, a, b;

void er(int src, int* dis, int hate) {
  for(int i=1; i<=n; i++) dis[i]=inf;
  queue<int> q;
  q.push(src);
  dis[src]=0;
  while(!q.empty()) {
    int u=q.front(); q.pop();
    for(auto v:adj[u]) if(v != hate && dis[v] == inf) {
      dis[v]=0;
      q.push(v);
    }
  }
  dis[hate]=0;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int T;
  cin>>T;
  while(T--) {
    scanf("%d %d %d %d", &n, &m, &a, &b);
    for(int i=0, u, v; i<m; i++) {
      scanf("%d %d", &u, &v);
      adj[u].pb(v);
      adj[v].pb(u);
    }
    er(a, da, b);
    er(b, db, a);
//    for(int i=1; i<=n; i++) cout<<da[i]<<' ';puts("");
//    for(int i=1; i<=n; i++) cout<<db[i]<<' ';puts("");exit(0);
    
    int ca=0, cb=0, ok;
    for(int i=1; i<=n; i++) if(i!=a && i!=b) {
      if(da[i] == inf) ca++;
      if(db[i] == inf) cb++;
    }
//    for(int i=1; i<=n; i++) if(i != a && i != b) {
//      if(da[i]+da[b] == db[i]) {
//        ok=1;
//        for(auto r:adj[i]) {
//          if(da[r] == da[i]-1 && db[r] != db[i]-1) {ok=0; break;}
//          if(db[r] == db[i]-1 && da[r] != da[i]-1) {ok=0; break;}
//        }
//        ca+=ok;
//      }
//      
//      if(db[i]+db[a] == da[i]) {
//        ok=1;
//        for(auto r:adj[i]) {
//          if(da[r] == da[i]-1 && db[r] != db[i]-1) {ok=0; break;}
//          if(db[r] == db[i]-1 && da[r] != da[i]-1) {ok=0; break;}
//        }
//        cb+=ok;
//      }
//    }
    printf("%I64d\n", (LL)ca*cb);
    for(int i=1; i<=n; i++) adj[i].clear();
  }
  
  return 0;
}