#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

int N;
int D[60][60][60][60];
bool visit[60][60][60][60];
char M[60][60];
int S[60][60];

int f(int u, int d, int l, int r){
	if (d < u || r < l) return 0;
	if (S[d][r] - S[u-1][r] - S[d][l-1] + S[u-1][l-1] <= 0) return 0;
	if (visit[u][d][l][r]) return D[u][d][l][r];
	visit[u][d][l][r] = true;
	D[u][d][l][r] = max(d-u+1, r-l+1);
	for (int i=u; i<d; i++) D[u][d][l][r] = min(D[u][d][l][r], f(u, i, l, r) + f(i+1, d, l, r));
	for (int i=l; i<r; i++) D[u][d][l][r] = min(D[u][d][l][r], f(u, d, l, i) + f(u, d, i+1, r));
	return D[u][d][l][r];
}

int main(){
	scanf("%d", &N);
	for (int i=1; i<=N; i++) scanf("%s", M[i]+1);
	for (int i=1; i<=N; i++) for (int j=1; j<=N; j++){
		S[i][j] = S[i-1][j] + S[i][j-1] - S[i-1][j-1];
		if (M[i][j] == '#') S[i][j]++;
	}
	printf("%d\n", f(1, N, 1, N));
	return 0;
}