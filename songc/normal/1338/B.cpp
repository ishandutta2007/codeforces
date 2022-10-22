#include <bits/stdc++.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define fi first
#define se second
#define INF (1ll<<60)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, mn=1, mx;
vector<int> adj[101010];
int A[101010];

int chk(int u, int p){
	int t = 0;
	if (adj[u].size() == 1) return 1;
	for (int v : adj[u]){
		if (v == p) continue;
		int r = chk(v, u);
		if (t && t!=r) mn=3;
		else if (!t) t = r;
	}
	return -t;
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<N; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].pb(v);
		adj[v].pb(u);
	}
	mx = N-1;
	int u=0;
	for (int i=1; i<=N; i++){
		if (adj[i].size() == 1) continue;
		u=i;
		for (int v : adj[i]){
			if (adj[v].size() == 1){
				if (A[i]) mx--;
				A[i] = 1;
			}
		}
	}
	chk(u, 0);
	printf("%d %d\n", mn, mx);
	return 0;
}