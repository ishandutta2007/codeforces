#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 1'000'000'007 
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;
int N, M;
int A[101010], B[101010], P[101010];
LL ans;

struct Edge{int u, v, w;};
vector<Edge> V;

int rt(int u){
	if (P[u] == u) return u;
	return P[u] = rt(P[u]);
}

int main(){
	scanf("%d %d", &M, &N);
	for (int i=1; i<=M; i++) scanf("%d", &A[i]);
	for (int i=1; i<=N; i++) scanf("%d", &B[i]);
	for (int i=1; i<=M; i++){
		int k, a;
		scanf("%d", &k);
		while (k--){
			scanf("%d", &a);
			ans += A[i]+B[a];
			V.pb((Edge){i, M+a, A[i]+B[a]});
		}
	}
	for (int i=1; i<=M+N; i++) P[i]=i;
	sort(all(V), [&](Edge a, Edge b){return a.w > b.w;});
	for (Edge t : V){
		if (rt(t.u) == rt(t.v)) continue;
		ans -= t.w;
		P[rt(t.u)] = rt(t.v);
	}
	printf("%lld\n", ans);
	return 0;
}