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
		for (int i=1; i<M-1; i++){
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
		int cnt = A[N-1][M-1]+A[N-1][M]+A[N][M-1]+A[N][M];
		if (cnt == 4){
			X[0].pb(N);
			X[1].pb(M);
			A[N][M] ^= 1;
			X[2].pb(N-1);
			X[3].pb(M);
			A[N-1][M] ^= 1;
			X[4].pb(N);
			X[5].pb(M-1);
			A[N][M-1] ^= 1;
			cnt = 1;
		}
		if (cnt == 1){
			for (int x=0; x<2; x++) for (int y=0; y<2; y++) if (A[N-x][M-y]){
				if (cnt != 1) break;
				X[0].pb(N-x);
				X[1].pb(M-y);
				A[N-x][M-y] ^= 1;
				X[2].pb(N-(1-x));
				X[3].pb(M-y);
				A[N-(1-x)][M-y] ^= 1;
				X[4].pb(N-x);
				X[5].pb(M-(1-y));
				A[N-x][M-(1-y)] ^= 1;
				cnt++;
			}
		}
		if (cnt == 2){
			int a=0, b=0;
			for (int x=0; x<2; x++) for (int y=0; y<2; y++) if (A[N-x][M-y]){
				if (X[0].size() != X[2].size()) break;
				X[0].pb(N-x);
				X[1].pb(M-y);
				a=x, b=y;
			}
			for (int x=0; x<2; x++) for (int y=0; y<2; y++) if (!A[N-x][M-y]){
				if (cnt == 2){
					X[2].pb(N-x);
					X[3].pb(M-y);
					A[N-x][M-y] ^= 1;
					cnt++;
				}
				else{
					X[4].pb(N-x);
					X[5].pb(M-y);
					A[N-x][M-y] ^= 1;
				}
			}
			A[N-a][M-b] ^= 1;
		}
		if (cnt == 3){
			for (int x=0; x<2; x++) for (int y=0; y<2; y++) if (A[N-x][M-y]){
				if (cnt == 3){
					X[0].pb(N-x);
					X[1].pb(M-y);
					A[N-x][M-y] ^= 1;
					cnt++;
				}
				else if (cnt == 4){
					X[2].pb(N-x);
					X[3].pb(M-y);
					A[N-x][M-y] ^= 1;
					cnt++;
				}
				else if (cnt == 5){
					X[4].pb(N-x);
					X[5].pb(M-y);
					A[N-x][M-y] ^= 1;
					cnt++;
				}
			}
		}
		printf("%d\n", (int)X[0].size());
		for (int i=0; i<X[0].size(); i++) printf("%d %d %d %d %d %d\n", X[0][i], X[1][i], X[2][i], X[3][i], X[4][i], X[5][i]);
	}
	return 0;
}