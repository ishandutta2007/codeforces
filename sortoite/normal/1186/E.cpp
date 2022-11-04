#include<bits/stdc++.h>



using namespace std;



typedef long long INT;





#define NN 2111

INT mat[NN][NN];

char s[NN][NN];

int sum[NN][NN];

int Q, n, m;



INT calc(int x, int y) {

	if(x == 0 || y == 0)  return 0;

	if(x >= 2 * n) {

		int t = x / (2 * n);

		INT sum = (INT) t * y * n;

		INT val = calc(x%(2*n), y);

		if(__builtin_popcount(t) & 1) {

			return sum + (INT) (x%(2*n))*y - val;

		}

		return sum + val;

	}

	if(y >= 2 * m) {

		int t = y / (2 * m);

		INT sum = (INT) t * x * m;

		INT val = calc(x, y%(2*m));

		if(__builtin_popcount(t) & 1) {

			return sum + (INT) (y%(2*m))*x - val;

		}

		return sum + val;

	}

	return mat[x][y];

}



int main(){

#ifndef ONLINE_JUDGE

	freopen("in.in","r",stdin);

	freopen("out.out","w",stdout);

#endif

	cin >> n >> m >> Q;

	for(int i=1; i<=n; i++) scanf("%s", s[i] + 1);

	

	for(int i=1; i<=n; i++)

		for(int j=1; j<=m; j++) mat[i][j] = s[i][j] - '0';

		

	for(int i=1; i<=2*n; i++)

		for(int j=1; j<=2*m; j++) {

			if(i <= n and j <= m) mat[i][j] = mat[i][j];

			if(i > n and j > m) mat[i][j] = mat[i-n][j-m];

			if(i > n and j <= m) mat[i][j] = mat[i-n][j] ^ 1;

			if(i <= n and j > m) mat[i][j] = mat[i][j-m] ^ 1;

		}

	for(int i=1; i<=2*n; i++) for(int j=1; j<=2*m; j++) {

		if(i == 1) mat[i][j] = mat[i][j-1] + mat[i][j];

		else if(j == 1) mat[i][j] = mat[i-1][j] + mat[i][j];

		else mat[i][j] = mat[i-1][j] + mat[i][j-1] - mat[i-1][j-1] + mat[i][j];

	}

	

	while(Q--) {

		int xl, xr, yl, yr;

		scanf("%d %d %d %d", &xl, &yl, &xr, &yr);

		INT ans = 0;

		ans += calc(xr, yr) + calc(xl-1, yl-1) - calc(xl-1, yr) - calc(xr, yl-1);

		printf("%I64d\n", ans);

	}

	

	return 0;

}