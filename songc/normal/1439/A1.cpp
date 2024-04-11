#include <bits/stdc++.h>
#define pb push_back
#define lb lower_bound
#define fi first
#define se second
#define mup(a,x) a=min(a,x)
#define Mup(a,x) a=max(a,x)
#define INF (1ll<<62)
#define MOD 998244353
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC, N, M;
int A[110][110];
vector<int> X[6];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		for (int i=0; i<6; i++) X[i].clear();
		for (int i=1; i<=N; i++) for (int j=1; j<=M; j++) scanf("%1d", &A[i][j]);
		for (int i=1; i<=N-2; i++){
			for (int j=1; j<M; j++){
				if (A[i][j]){
					X[0].pb(i);
					X[1].pb(j);
					X[2].pb(i+1);
					X[3].pb(j);
					X[4].pb(i+1);
					X[5].pb(j+1);
					A[i+1][j] ^= 1;
					A[i+1][j+1] ^= 1;
				}
			}
			if (A[i][M]){
				X[0].pb(i);
				X[1].pb(M);
				X[2].pb(i+1);
				X[3].pb(M);
				X[4].pb(i+1);
				X[5].pb(M-1);
				A[i+1][M] ^= 1;
				A[i+1][M-1] ^= 1;
			}
		}
		for (int i=1; i<M; i++){
			if (A[N-1][i]){
				X[0].pb(N-1);
				X[1].pb(i);
				X[2].pb(N-1);
				X[3].pb(i+1);
				X[4].pb(N);
				X[5].pb(i+1);
				A[N-1][i+1] ^= 1;
				A[N][i+1] ^= 1;
			}
			if (A[N][i]){
				X[0].pb(N);
				X[1].pb(i);
				X[2].pb(N-1);
				X[3].pb(i+1);
				X[4].pb(N);
				X[5].pb(i+1);
				A[N-1][i+1] ^= 1;
				A[N][i+1] ^= 1;
			}
		}
		if (A[N-1][M] && A[N][M]){
			X[0].pb(N-1);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M-1);
			X[4].pb(N);
			X[5].pb(M);

			X[0].pb(N-1);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M-1);
			X[4].pb(N-1);
			X[5].pb(M);
		}
		else if (A[N-1][M]){
			X[0].pb(N-1);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M);
			X[4].pb(N-1);
			X[5].pb(M);

			X[0].pb(N);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M);
			X[4].pb(N-1);
			X[5].pb(M);

			X[0].pb(N-1);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M-1);
			X[4].pb(N-1);
			X[5].pb(M);
		}
		else if (A[N][M]){
			X[0].pb(N-1);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M);
			X[4].pb(N-1);
			X[5].pb(M);

			X[0].pb(N);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M);
			X[4].pb(N-1);
			X[5].pb(M);

			X[0].pb(N-1);
			X[1].pb(M-1);
			X[2].pb(N);
			X[3].pb(M-1);
			X[4].pb(N);
			X[5].pb(M);
		}
		printf("%d\n", (int)X[0].size());
		for (int i=0; i<X[0].size(); i++) printf("%d %d %d %d %d %d\n", X[0][i], X[1][i], X[2][i], X[3][i], X[4][i], X[5][i]);
	}
	return 0;
}