#include <bits/stdc++.h>

using namespace std;

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
	int i, j, k, l;
	int t, n, m, q;
	int in;
	int mod = 998244353;
	scanf("%d", &n);
	char s[n][3];
	for(i=0; i<n; i++) {
		scanf("%s", &s[i]);
	}
	int ques = 0, white = 0, black = 0;
	for(i=0; i<n; i++) {
		for(j=0; j<2; j++) {
			if(s[i][j] == '?') {
				ques++;
			} else if(s[i][j] == 'W') {
				white++;
			} else {
				black++;
			}
		}
	}
	int answer = 0;
	if(white <= n && black <= n) {
		answer += comb_mod(ques, n-white, mod);
	}
	int same = 0;
	for(i=0; i<n; i++) {
		if(s[i][0] != '?' && s[i][0] == s[i][1]) {
			same = 1;
		}
	}
	if(!same) {
		int dir[2] = {};
		for(i=0; i<n; i++) {
			if(s[i][0] == 'W' || s[i][1] == 'B') {
				dir[0]++;
			}
			if(s[i][0] == 'B' || s[i][1] == 'W') {
				dir[1]++;
			}
		}
		answer = (mod+answer-pow_mod(2, n-dir[0]-dir[1], mod))%mod;
		if(dir[0] == 0) {
			answer++;
		}
		if(dir[1] == 0) {
			answer++;
		}
		answer %= mod;
	}
	printf("%d\n", answer);
}