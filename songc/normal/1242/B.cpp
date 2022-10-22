#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

int N, M, ans;
vector<int> V, nV;
vector<int> G[101010];
queue<int> Q;

int f(int u){
	for (int v : V){
		auto it = lower_bound(G[u].begin(), G[u].end(), v);
		if (it == G[u].end() || *it != v){
			Q.push(v);
			ans--;
		}
		else nV.push_back(v);
	}
	V = nV;
	nV.clear();
}

int main(){
	scanf("%d %d", &N, &M);
	ans = N-1;
	for (int i=1; i<=M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		G[u].push_back(v);
		G[v].push_back(u);
	}
	for (int i=1; i<=N; i++) sort(G[i].begin(), G[i].end());
	for (int i=1; i<=N; i++) V.push_back(i);
	while (!V.empty()){
		Q.push(V.back());
		V.pop_back();
		while (!Q.empty()){
			f(Q.front());
			Q.pop();
		}
	}
	printf("%d\n", ans);
	return 0;
}