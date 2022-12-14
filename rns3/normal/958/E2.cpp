#include <bits/stdc++.h>

using namespace std;



const int INF = 1e9;



#define N 505050

#define M 5050



int a[N], n, m;



int f[2][M];



int main() {

	//freopen("r.in", "r", stdin);

	scanf("%d %d", &m, &n);

	for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);

	sort(a + 1, a + n + 1);

	for (int i = 1; i < n; i ++) a[i] = a[i+1] - a[i];

	n --;



	for (int j = 1; j <= m; j ++) f[0][j] = INF;

	for (int j = 2; j <= m; j ++) f[1][j] = INF;

	f[1][1] = a[1];

	int* A = f[0];

	int* B = f[1];

	for (int i = 2; i <= n; i ++) {

		for (int j = m - 1; j >= 0; j --) {

			A[j+1] = min(B[j+1], a[i] + A[j]);

		}

		swap(A, B);

	}

	printf("%d\n", f[n&1][m]);



	return 0;

}