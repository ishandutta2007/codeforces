#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define pb push_back
typedef double DO;
typedef long long INT;
typedef vector<int> VI;
typedef pair<int, int> pii;

const int NN = 1e5+10, MM = 2e5+20;
int F[NN], sz[NN];
VI adj[NN];

int arr[NN], an=1, fa[NN];
int p[NN][20], deep[NN];
void dfs(int u, int fa=0){
  arr[an++]=u;
  p[u][0]=fa;
  deep[u]=deep[fa]+1;
  for(int i=1; i<20; i++) p[u][i]=p[p[u][i-1]][i-1];
  for(auto v:adj[u]){
    dfs(v, u);
  }
}

int k_th(int u, int k){
  for(int i=0; i<20; i++){
    if(k&(1<<i)) u=p[u][i];
  }
  return u;
}

int lca(int a, int b){
  if(deep[a]>deep[b]) swap(a, b);
  b=k_th(b, deep[b]-deep[a]);
  if(a==b) return a;
  for(int i=20; i--; ){
    if(p[a][0]==p[b][0]) break;
    if(p[a][i]!=p[b][i]) a=p[a][i], b=p[b][i];
  }
  return p[a][0];
}


void predfs(int u) {
  sz[u]=0;
//  sz[u]=1;
  for(auto v:adj[u]) {
    predfs(v);
    sz[u]=max(sz[u], sz[v]+1);
//    sz[u]+=sz[v];
  }
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  int n;
  scanf("%d", &n);
  for(int i=2, j; i<=n; i++) {
    scanf("%d", &j); j++;
    adj[j].pb(i);
  }
  
  predfs(1);
  for(int i=1; i<=n; i++) {
    sort(adj[i].begin(), adj[i].end(), [&](int i, int j){return sz[j]>sz[i];});
  }
  
  dfs(1);
  for(int i=1; i<=n; i++) {
    F[arr[i]]=arr[i-1];
    printf("%d ", arr[i]-1);
  }
  puts("");
  
  VI ans;
  for(int i=2; i<=n; i++) {
    int u=lca(p[arr[i]][0], F[arr[i]]);
    int d=deep[F[arr[i]]]-deep[u];
    while(d--) ans.pb(arr[i]-1);
  }
  
  printf("%d\n", ans.size());
  for(auto r:ans) cout<<r<<' ';cout<<endl;
  
  return 0;
}