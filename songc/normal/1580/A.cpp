#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
#define lb lower_bound
#define MOD 1000000007
#define INF (1ll<<62)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int TC;
int N, M;
int A[550][550];

int f(int x1, int y1, int x2, int y2){return A[x2][y2] - A[x1-1][y2] - A[x2][y1-1] + A[x1-1][y1-1];}

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d %d", &N, &M);
		for (int i=1; i<=N; i++){
			for (int j=1; j<=M; j++){
				scanf("%1d", &A[i][j]);
				A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];		
			}
		}
		int ans = MOD;
		for (int i=5; i<=N; i++) for (int j=1; j<=i-4; j++){
			int mn = MOD;
			for (int k=4; k<=M; k++){
				mn = min(mn, 2*(i-j-1) - f(j+1, k-3, i-1, k-3) - f(j+1, 1, i-1, k-3) + f(j, 1, j, k-3) + f(i, 1, i, k-3) - 2*(k-3));
				ans = min(ans, mn + f(j+1, 1, i-1, k-1) + 2*k-2 - f(j, 1, j, k-1) - f(i, 1, i, k-1) - f(j+1, k, i-1, k));
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}