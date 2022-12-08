#include <bits/stdc++.h>

using namespace std;
#define ll long long

const int mod = 1000000007;
const int d = 101; //dimension of matrix

struct Matrix {
	ll mat[d][d];
};

ll mult(ll a, ll b) { //long multiplcation to stay within bounds
	return (a*b)%mod;
}

Matrix matMult(Matrix a, Matrix b) {
	Matrix ans;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			ans.mat[i][j] = 0LL;
			for (int k = 0; k < d; k++) {
				ans.mat[i][j] = (ans.mat[i][j] + 
					mult(a.mat[i][k], b.mat[k][j]))%mod;
			}
		}
	}
	return ans;
}

Matrix matPow(Matrix base, ll p) {
	Matrix ans;
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			if (i == j) ans.mat[i][j] = 1LL;
			else ans.mat[i][j] = 0LL;
		}
	}
	while (p)  {
		if (p & 1) {
			ans = matMult(ans, base);
		}
		base = matMult(base, base);
		p/=2;
	}
	return ans;
}

int main() {

	int n, x;
	cin  >> n >> x;

	int ct[101];
	fill(ct, ct+101, 0);
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		ct[cur]++;
	}

	ll dp[101]; //the top row
	//offset it by one
	dp[0] = 1LL;
	ll tsum = 1LL; //1 b/c one node at distance zero
	for (int i = 1; i <= 100; i++) {
		dp[i] = 0LL;
		for (int j= 0; j <= i; j++) {
			dp[i] = (dp[i] + mult(dp[i-j], ct[j]))%mod;
			//take ct[j] from all i-j
		}
		tsum = (tsum + dp[i])%mod;
	}


	ll A[101]; //this is the A matrix
	for (int i= 0; i < 100; i++) {
		A[i] = dp[i+1];
	}
	A[100] = tsum;


	if (x <= 100) {
		ll ans = 0LL;
		for (int i=0; i <= x; i++) {
			ans = (ans+dp[i])%mod;
		}
		cout << ans << endl;
		cin >> ans;
		return 0;
	}

	//this should only run if x is at least 100
	Matrix conv; //dp conversion state
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			if (i == j+1) {
				conv.mat[i][j] = 1LL;
			}
			else conv.mat[i][j] = 0LL;
		}
	}
	for (int i = 0; i < d; i++) {
		conv.mat[i][99] = conv.mat[i][100] = ct[100-i];
	}
	conv.mat[100][100] = 1;
	conv.mat[100][99] = 0; //i think my indexing is off

	conv = matPow(conv, x-100);
	ll ans = 0LL;
	for (int i = 0; i <= 100; i++) {
		ans = (ans + mult(A[i], conv.mat[i][100]))%mod;

	}
	cout << ans << endl;
	cin >> ans;
	
	
}