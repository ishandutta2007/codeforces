#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

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
	long long h, i, j, k;
	long long t, n;
	long long a, b;
	scanf("%lld", &n);
	int m[n+1][n+1];
	int ad[n+1][n];
	int len[n+1] = {};
	int dir[n+1][n+1];
	int queue[n];
	int pass[n+1];
	int s, e;
	int v;
	long long answer = 0;
	long long add;
	int mod = 1000000007;
	long long prob[n][n];
	for(i=0; i<n; i++) {
		prob[i][0] = 0;
		prob[0][i] = 1;
	}
	int inv2 = inv_mod(2, mod);
	for(i=1; i<n; i++) {
		for(j=1; j<n; j++) {
			prob[i][j] = ((prob[i-1][j]+prob[i][j-1])*inv2)%mod;
		}
	}
	for(i=0; i<=n; i++) {
		for(j=0; j<=n; j++) {
			m[i][j] = 0;
			dir[i][j] = 0;
		}
	}
	for(i=1; i<n; i++) {
		scanf("%lld %lld", &a, &b);
		m[a][b] = 1;
		m[b][a] = 1;
		ad[a][len[a]] = b;
		len[a]++;
		ad[b][len[b]] = a;
		len[b]++;
	}
	for(i=1; i<=n; i++) {
		for(j=0; j<=n; j++) {
			pass[j] = 0;
		}
		s = 0;
		e = 1;
		queue[0] = i;
		pass[i] = 1;
		while(s < n) {
			for(j=0; j<len[queue[s]]; j++) {
				if(!pass[ad[queue[s]][j]]) {
					queue[e] = ad[queue[s]][j];
					pass[ad[queue[s]][j]] = 1;
					e++;
					dir[ad[queue[s]][j]][i] = queue[s];
				}
			}
			s++;
		}
	}
	for(i=1; i<=n; i++) {
		for(j=i+1; j<=n; j++) {
			int path[n+1];
			for(k=1; k<=n; k++) {
				path[k] = 0;
			}
			int plen;
			for(v=i, k=0; v!=j; v=dir[v][j], k++) {
				path[v] = k;
			}
			plen = k;
			path[j] = plen;
			for(k=1; k<=n; k++) {
				if(path[k]) {
					for(h=0; h<=n; h++) {
						pass[h] = 0;
					}
					s = 0;
					e = 1;
					queue[0] = k;
					pass[k] = 1;
					while(s < e) {
						for(h=0; h<len[queue[s]]; h++) {
							if(!pass[ad[queue[s]][h]] && dir[queue[s]][i] != ad[queue[s]][h] && dir[queue[s]][j] != ad[queue[s]][h]) {
								queue[e] = ad[queue[s]][h];
								pass[ad[queue[s]][h]] = 1;
								e++;
							}
						}
						s++;
					}
					add = e;
					add = (add*prob[plen-path[k]][path[k]])%mod;
					add = (add*inv_mod(n, mod))%mod;
					answer = (answer+add)%mod;
				}
			}
		}
	}
	printf("%lld", answer);
}