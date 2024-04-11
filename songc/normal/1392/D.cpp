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

int TC, N;
int D[4][4][202020];
char A[202020];

int main(){
	scanf("%d", &TC);
	while (TC--){
		scanf("%d", &N);
		scanf("%s", A+1);
		for (int i=0; i<4; i++) for (int j=0; j<4; j++) for (int k=1; k<=N; k++) D[i][j][k]=MOD;
		if (A[1] == 'L' && A[2] == 'L') D[3][3][2]=2, D[2][0][2]=1, D[0][2][2]=1, D[1][1][2]=0;
		if (A[1] == 'L' && A[2] == 'R') D[3][3][2]=1, D[2][0][2]=2, D[0][2][2]=0, D[1][1][2]=1;
		if (A[1] == 'R' && A[2] == 'L') D[3][3][2]=1, D[2][0][2]=0, D[0][2][2]=2, D[1][1][2]=1;
		if (A[1] == 'R' && A[2] == 'R') D[3][3][2]=0, D[2][0][2]=1, D[0][2][2]=1, D[1][1][2]=2;
		for (int i=2; i<N; i++){
			for (int j=0; j<4; j++){
				if (A[i+1]=='L'){
					mup(D[j][1][i+1], D[j][0][i]);
					mup(D[j][2][i+1], D[j][0][i]+1);

					mup(D[j][2][i+1], D[j][1][i]+1);

					mup(D[j][0][i+1], D[j][2][i]);
					mup(D[j][3][i+1], D[j][2][i]+1);

					mup(D[j][0][i+1], D[j][3][i]);
				}
				else{
					mup(D[j][1][i+1], D[j][0][i]+1);
					mup(D[j][2][i+1], D[j][0][i]);

					mup(D[j][2][i+1], D[j][1][i]);

					mup(D[j][0][i+1], D[j][2][i]+1);
					mup(D[j][3][i+1], D[j][2][i]);

					mup(D[j][0][i+1], D[j][3][i]+1);
				}
			}
		}
		int ans=MOD;
		mup(ans, D[0][0][N]); 
		mup(ans, D[0][2][N]); 
		mup(ans, D[0][3][N]);
		mup(ans, D[1][2][N]);
		mup(ans, D[1][3][N]);
		mup(ans, D[2][0][N]);
		mup(ans, D[2][1][N]);
		mup(ans, D[2][2][N]);
		mup(ans, D[3][0][N]);
		mup(ans, D[3][1][N]);
		printf("%d\n", ans);
	}
	return 0;
}