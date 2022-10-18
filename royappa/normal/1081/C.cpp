#include <bits/stdc++.h>

using namespace std;
typedef long long LL;

const int MOD = 998244353;
int n, m, k;
int A[2001][2001];

int main()
{
	cin >> n >> m >> k;
	A[0][0] = m; // m ways to put the first brick
	for (int d = 1; d <= k; d++) {
		A[0][d] = 0;
	}
	// Place one more brick
	for (int i = 1; i < n; i++) {
		A[i][0] = A[i-1][0];
		for (int d = 1; d <= k; d++) {
			LL x = (m-1), y = A[i-1][d-1];
			LL z = (x*y) % MOD;
			A[i][d] = (A[i-1][d] + z) % MOD;
		}
	}
	cout << A[n-1][k] << endl;
}