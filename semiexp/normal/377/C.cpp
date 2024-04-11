#include <cstdio>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <cmath>
#include <cstring>
using namespace std;
#define MOD 1000000009
#define ADD(X, Y) ((X) = ((X) + (Y)) % MOD)

int N, S[100], M;

int dp[21][1<<20];
char op[21][5]; int team[21];
int val[1<<20];

int main()
{
	scanf("%d", &N);
	for(int i=0;i<N;i++) scanf("%d", S+i);
	scanf("%d", &M);
	for(int i=0;i<M;i++) scanf("%s%d", op[i], team+i);

	for(int i=0;i<M;i++) val[1<<i] = i;

	sort(S, S+N);
	reverse(S, S+N);

	for(int i=0;i<(1<<M);i++){
		dp[M][i] = 0;
	}

	for(int i=M-1;i>=0;i--){
		for(int j=0;j<(1<<M);j++){
			if(op[i][0] == 'p'){
				int fb = j&-j;
				if(fb == 0) dp[i][j] = 0;
				else dp[i][j] = dp[i+1][fb^j] + (team[i]==1 ? S[val[fb]] : -S[val[fb]]);
			}else{
				dp[i][j] = dp[i+1][j];
				if(team[i] == 1){
					for(int k=0;k<M;k++) if(j&(1<<k)) dp[i][j] = max(dp[i][j], dp[i+1][j^(1<<k)]);
				}else{
					for(int k=0;k<M;k++) if(j&(1<<k)) dp[i][j] = min(dp[i][j], dp[i+1][j^(1<<k)]);
				}
			}
		}
	}
	printf("%d\n", dp[0][(1<<M)-1]);

	return 0;
}