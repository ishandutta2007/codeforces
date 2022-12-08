#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll N;
int M;

const int mod = 1000000007;
const int di = 100; //dimensions of matrix

struct Matrix {
	ll mat[di][di];
};

Matrix matMult(Matrix a, Matrix b) {
	Matrix ans;
	for (int i = 0; i < di; i++) {
		for (int j = 0; j < di; j++) {
			ans.mat[i][j] = 0LL;
			for (int k = 0; k < di; k++) {
				ans.mat[i][j] = (ans.mat[i][j] + 
					a.mat[i][k]*b.mat[k][j])%mod;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, ll p) {
	Matrix ans;
	for (int i = 0; i < di; i++) { //identity
		for (int j = 0; j < di; j++) {
			if (i == j) ans.mat[i][j] = 1LL;
			else ans.mat[i][j] = 0LL;
		}
	}
	while (p) {
		if (p & 1) {
			ans = matMult(ans, base);
		}
		base = matMult(base, base);
		p = p/2;
	}
	return ans;
}

ll odp[105];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> M;
	Matrix ans;
	//always do multiplication like:
	//ans = matMult(ans, second)
	Matrix tform;
	for (int i = 0; i < di; i++) {
		for (int j = 0; j < di; j++) {
			tform.mat[i][j] = 0;
		}
	}
	for (int i = 0; i < M-1; i++) {
		tform.mat[i][i+1] = 1;
	}
	tform.mat[M-1][M-1] = 1;
	tform.mat[M-1][0] = 1;

	tform = matPow(tform, N);

	ll res = 0LL;
	for (int i = 0; i < M; i++) {
		res = (res + tform.mat[0][i])%mod;
	}
	cout << res << endl;

}