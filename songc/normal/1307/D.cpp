#include <bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N, M, K, ans;
int S[202020];
int D1[202020], D2[202020], T[202020];
queue<int> Q;
vector<int> adj[202020];

void upd(int k, int v){while(k<=N){T[k]=max(T[k], v), k+=k&-k;}}
int read(int k){int mx=-1234567890; while(k){mx=max(T[k], mx), k^=k&-k;} return mx;}

int main(){
	scanf("%d %d %d", &N, &M, &K);
	for (int i=1; i<=K; i++) scanf("%d", &S[i]);
	for (int i=1; i<=M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	Q.push(1);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int v : adj[u]){
			if (D1[v] || v == 1) continue;
			D1[v] = D1[u] + 1;
			Q.push(v);
		}
	}

	Q.push(N);
	while (!Q.empty()){
		int u = Q.front();
		Q.pop();
		for (int v : adj[u]){
			if (D2[v] || v == N) continue;
			D2[v] = D2[u] + 1;
			Q.push(v);
		}
	}

	int L=0, H=N;
	while (L<=H){
		int mid=(L+H)/2;
		for (int i=1; i<=N; i++) T[i] = -1234567890;
		bool tf = false;
		for (int i=1; i<=K; i++){
			if (read(D1[S[i]]+1) + D2[S[i]] >= mid) tf = true;
			upd(max(mid-D2[S[i]], 0)+1, D1[S[i]]);
		}
		if (tf) ans = mid, L=mid+1;
		else H=mid-1;
	}
	ans++;
	printf("%d\n", min(ans, D1[N]));
	return 0;
}