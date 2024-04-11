//2016-06-17 12:48:54.195000
#include <bits/stdc++.h>

using namespace std;
#define x first
#define y second
#define beyond(x, y) (x<0 || y<0 || x>=N || y>=M)

typedef long long INT;
typedef pair<int, int> pii;

int dx[]={1, -1, 0, 0};
int dy[]={0, 0, 1, -1};
#define NN 1111

template <class T> inline void smax(T &a, T b) {if (a<b) a=b;}

int can[NN][NN], best[NN][NN][11];
char s[NN], t[NN];

int main() {
	
	int n, m, i, j, k, K;
	scanf("%d%d%d", &n, &m, &K);
	scanf("%s%s",s, t);
	
	memset(can, 0, sizeof(can));
	for (i=n; i>=0; i--) for (j=m; j>=0; j--) {
		if (i==n || j==m) continue;
		if (s[i]!=t[j]) continue;
		can[i][j]=can[i+1][j+1]+1;
	}

	memset(best, 0, sizeof(best));
	for (i=n; i>=0; i--) for (j=m; j>=0; j--) for (k=0; k<=K; k++) {
		if (i==n || j==m) continue;
		if (k==0) continue;
		smax(best[i][j][k], best[i+1][j][k]);
		smax(best[i][j][k], best[i][j+1][k]);
		smax(best[i][j][k], best[i+can[i][j]][j+can[i][j]][k-1]+can[i][j]);
	}
	
	printf("%d\n", best[0][0][K]);
	
	return 0; 
}