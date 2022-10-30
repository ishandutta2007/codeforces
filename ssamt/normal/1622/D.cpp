#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	long long mod = 998244353;
	scanf("%d %d", &n, &k);
	long long comb_mod[n+1][n+1];
	for(i=0; i<=n; i++) {
		comb_mod[i][0] = 1;
		for(j=1; j<i; j++) {
			comb_mod[i][j] = (comb_mod[i-1][j-1]+comb_mod[i-1][j])%mod;
		}
		comb_mod[i][i] = 1;
	}
	char s[n+1];
	scanf("%s", s);
	int one = 0;
	for(i=0; i<n; i++) {
		if(s[i] == '1') {
			one++;
		}
	}
	long long answer = 0;
	if(one >= k && k > 0) {
		int p1 = 0, p2, p3;
		int count = 0;
		for(p2=0; p2<n; p2++) {
			if(s[p2] == '1') {
				count++;
			}
			if(count > k) {
				break;
			}
		}
		while(true) {
			for(p3=p1; p3<n && s[p3]=='0'; p3++);
			//printf("%d %d %d\n", p1, p2, p3);
			answer = (answer+comb_mod[p2-p1][k])%mod;
			if(p2 != n) {
				answer = (answer-comb_mod[p2-p3-1][k-1]+mod)%mod;
			}
			p1 = p3+1;
			if(p2 == n) {
				break;
			}
			p2++;
			for(; p2<n && s[p2]=='0'; p2++);
		}
	} else {
		answer = 1;
	}
	printf("%lld\n", answer);
}