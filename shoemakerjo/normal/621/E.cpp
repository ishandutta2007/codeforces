#include <bits/stdc++.h>

using namespace std;
#define ll long long
ll ct[10];

const ll mod = 1000000007LL;
int n, b, k, x;

struct Matrix {
	ll mat[101][101]; 
};

Matrix matMul(Matrix a, Matrix b) {
	Matrix ans;
	int i, j, k;
	for (i = 0; i < x; i++) {
		for (j = 0; j < x; j++) {
			ans.mat[i][j] = 0LL;
			for (k = 0; k < x; k++) {
				ans.mat[i][j] = (ans.mat[i][j] + a.mat[i][k] * b.mat[k][j])%mod;
			}
		}
	}
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	Matrix scale;
	cin >> n >> b >> k >> x;
	for (int i = 0; i < 10; i++) {
		ct[i] = 0;
	}
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ct[cur]++;
		
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			scale.mat[i][j] = 0LL;
		}
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < 10; j++) {
			int nx = (10*i + j)%x;
			scale.mat[nx][i] = (scale.mat[nx][i]+ct[j])%mod;
		}
	}
	// cout << "SCALE MATRIX\n";
	// for (int i = 0; i < x; i++) {
	// 	for (int j = 0; j < x; j++) {
	// 		cout << scale.mat[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	Matrix ans;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < x; j++) {
			if (i == j) ans.mat[i][j] = 1LL;
			else ans.mat[i][j] = 0LL;
		}
	}
	if (b == 1) {
		if (k < 10) cout << ct[k] << endl;
		else cout << 0 << endl;
	}
	else {
		while (b) {
			if (b & 1) {
				ans = matMul(ans, scale);
			}
			scale = matMul(scale, scale);
			b = b/2;
		}
		// cout << "ANS MATRIX\n";
		// for (int i = 0; i < x; i++) {
		// 	for (int j = 0; j < x; j++) {
		// 		cout << ans.mat[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		int cans = 0LL;
		cans = ans.mat[k][0];
		cout << cans << endl;
	}
	
	cin >> x;

}