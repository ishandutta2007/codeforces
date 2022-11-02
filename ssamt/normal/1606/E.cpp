#include <bits/stdc++.h>

using namespace std;
#define SIZE 500

int pow_mod(int a, int k, int mod) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2, mod);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

//p must be prime
int inv_mod(int a, int p) {
	return pow_mod(a, p-2, p);
}

//mod must be prime
int comb_mod(int n, int r, int mod) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r, mod);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i, mod))%mod;
	}
	return answer;
}

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	int x;
	scanf("%d %d", &n, &x);
	long long apow[SIZE+1][SIZE+1];
	long long comb[SIZE+1][SIZE+1];
	long long mod = 998244353;
	for(i=0; i<=SIZE; i++) {
		for(j=0; j<=SIZE; j++) {
			apow[i][j] = pow_mod(i, j, mod);
		}
	}
	for(i=1; i<=SIZE; i++) {
		comb[i][0] = 1;
		for(j=1; j<i; j++) {
			comb[i][j] = (comb[i-1][j]+comb[i-1][j-1])%mod;
		}
		comb[i][i] = 1;
	}
	long long answer[SIZE+1][SIZE+1];
	for(i=0; i<=n; i++) {
		for(j=0; j<=x; j++) {
			answer[i][j] = -1;
		}
	}
	function<int(int, int)> cur = [&](int tn, int tx) {
		if(tn == 0) {
			return 1;
		} else if (tn == 1) {
			return 0;
		}
		if(tx == 1) {
			return 1;
		}
		if(tx < tn) {
			answer[tn][tx] = apow[tx][tn];
			return (int)answer[tn][tx];
		}
		if(answer[tn][tx] != -1) {
			return (int)answer[tn][tx];
		}
		int i;
		answer[tn][tx] = 0;
		for(i=0; i<=tn; i++) {
			answer[tn][tx] += ((cur(i, tx-(tn-1))*apow[tn-1][tn-i])%mod*comb[tn][i])%mod;
		}
		answer[tn][tx] %= mod;
		return (int)answer[tn][tx];
	};
	printf("%d\n", cur(n, x));
}