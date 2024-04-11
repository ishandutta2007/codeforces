#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

int N, M;
bool adj[20][20], IS[303030];
LL D[303030];

int main(){
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++){
		int u, v;
		scanf("%d %d", &u, &v);
		adj[u-1][v-1] = adj[v-1][u-1] = true;
	}
	for (int i=1; i<(1<<N); i++){
		IS[i] = true;
		for (int j=0; j<N; j++) for (int k=j+1; k<N; k++) {
			if (adj[j][k] && (i & (1<<j)) && (i & (1<<k))) IS[i] = false;
		}
	}
	D[0] = 1;
	for (int i=1; i<(1<<N); i++){
		for (int j=i; j; j=i&(j-1)) if (IS[j]){
			if (__builtin_popcount(j) & 1){
				D[i] = D[i] + D[i^j];
				if (D[i] >= MOD) D[i] -= MOD;
			}
			else {
				D[i] = D[i] - D[i^j];
				if (D[i] < 0) D[i] += MOD;
			}
		}
	}
	printf("%lld\n", D[(1<<N)-1] * M % MOD * ((MOD+1)/2) % MOD);
	return 0;
}