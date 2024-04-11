#include <bits/stdc++.h>
#define x first
#define y second
#define pb push_back

using namespace std;
template<typename T, typename U> inline void smin(T &a, const U &b) {if (a>b) a=b;}
template<typename T, typename U> inline void smax(T &a, const U &b) {if (a<b) a=b;}

inline int power(int a, int b, int m, int ans=1) {
  for(; b; b>>=1, a=1LL*a*a%m) if (b&1) ans=1LL*ans*a%m;
  return ans;
}

const int NN = 1e5+10;
int col[NN][3];
vector<int> adj[NN];
int deg[NN];

long long tot[6];
int ans[6][NN];

vector<int> arr;

void dfs(int u, int fa=0) {
	arr.pb(u);
	for(auto v:adj[u]) if(fa!=v) dfs(v, u);
}


int main() {
#ifndef ONLINE_JUDGE
  freopen("in.in", "r", stdin);
  freopen("out.out", "w", stdout);
#endif
  
  int n;
  scanf("%d", &n);
  for(int j=0; j<3; j++) for(int i=1; i<=n; i++) scanf("%d", &col[i][j]);
  for(int i=1, u, v; i<n; i++) {
  	scanf("%d %d", &u, &v);
  	adj[u].pb(v); adj[v].pb(u);
  	deg[u]++;
  	deg[v]++;
  }
  for(int i=1; i<=n; i++) if(deg[i]>2) {
  	puts("-1");
  	return 0;
  }
  
  int root;
  
  for(int i=1; i<=n; i++) if(deg[i] == 1) {
  	root=i;
  	break;
  }
  
  dfs(root);
  
  
  int p[]={0,1,2,0,0};
  
  for(int i=0; i<6; i++) {
  	for(int j=0; j<n; j++) {
  		ans[i][arr[j]]=p[j%3];
  		tot[i]+=col[arr[j]][p[j%3]];
  	}
  	next_permutation(p, p+3); 
  }
  
  long long tmp=1000000000000000000ll;
  int id;
  
  for(int i=0; i<6; i++) {
  	if(tmp>tot[i]) {
  		id=i;
  		tmp=tot[i];
  	}
  }
  
  cout<<tmp<<endl;
  for(int i=1; i<=n; i++) printf("%d ", ans[id][i]+1);
  puts("");
  
  return 0;
}