#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define Mup(a,x) a=max(a, x)
#define mup(a,x) a=min(a, x)
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define INF (1ll<<60)
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
int P[2020], E[2020];
int U[4040404], V[4040404];
LL D[2020][2020], B[2020];

int rt(int u){
	if (P[u] < 0) return u;
	return P[u] = rt(P[u]);
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++){
		int a;
		scanf("%d", &a);
		if (i < j) U[a]=i, V[a]=j;
	}
	for (int i=1; i<=N; i++) P[i]=-1, D[i][1] = 1;
	for (int i=1; i<=N*(N-1)/2; i++){
		int u=rt(U[i]), v=rt(V[i]);
		if (u == v) {
			E[u]++;
			if (E[u] == P[u]*(P[u]+1)/2) D[u][1] = 1;
			continue;
		}
		for (int j=1; j<=-P[u]-P[v]; j++) B[j]=0;
		for (int x=1; x<=-P[u]; x++) for (int y=1; y<=-P[v]; y++) B[x+y] = (B[x+y] + D[u][x]*D[v][y]) % MOD;
		for (int j=1; j<=-P[u]-P[v]; j++) D[u][j] = B[j];
		P[u]+=P[v], E[u]+=E[v]+1, P[v] = u;
		if (P[u] == -2) D[u][1] = 1;
	}
	for (int i=1; i<=N; i++) printf("%lld ", D[rt(1)][i]);
	printf("\n");
	return 0;
}