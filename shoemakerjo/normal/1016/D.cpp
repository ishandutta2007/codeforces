#include <bits/stdc++.h>

using namespace std;

#define maxn 103
#define ll long long
//deal in long longs just in case

int n, m;
ll a[maxn];
ll b[maxn];

ll ans[maxn][maxn];

//10^4 squares (can look at all for each cell)

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >>  m;
	int runxor = 0;
	int rowxor = 0, colxor = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		runxor ^= a[i];
		rowxor ^= a[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> b[i];
		runxor ^= b[i];
		colxor ^= b[i];
	}
	if (runxor != 0 || rowxor != colxor) {
		cout << "NO" << endl;
		return 0;
	}
	for (int i = 0; i < n-1; i++) {
		for (int j = 0; j < m-1; j++) {
			ans[i][j] = 0;
			ans[n-1][j] = b[j];
		}
		ans[i][m-1] =  a[i];
	}
	rowxor ^= a[n-1]; //what is currently there
	colxor ^= b[m-1];

	int lastguy = rowxor ^ b[m-1];
	// cout << "lastguy:   " << lastguy << endl;
	if (lastguy != (colxor ^ a[n-1])) {
		cout << "NO" << endl;
		return 0;
	}
	cout << "YES" << endl;
	ans[n-1][m-1] = lastguy;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << " ";
		}
		cout << endl;
	}

}