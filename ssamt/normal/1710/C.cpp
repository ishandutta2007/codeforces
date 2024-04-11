#include <bits/stdc++.h>

using namespace std;

int mod = 998244353;

int pow_mod(int a, int k) {
	if(k == 0) {
		return 1;
	}
	int sub = pow_mod(a, k/2);
	if(k%2 == 0) {
		return ((long long)sub*sub)%mod;
	} else {
		return (((long long)sub*sub)%mod*a)%mod;
	}
}

int inv_mod(int a) {
	return pow_mod(a, mod-2);
}

int comb_mod(int n, int r) {
	int i;
	int answer = 1;
	if(2*r > n) {
		return comb_mod(n, n-r);
	}
	for(i=n-r+1; i<=n; i++) {
		answer = ((long long)answer*i)%mod;
	}
	for(i=1; i<=r; i++) {
		answer = ((long long)answer*inv_mod(i))%mod;
	}
	return answer;
}

class Mod {
	public:
		long long val;
		
		Mod() {
			this->val = 0;
		}
		
		Mod(int val) {
			this->val = val;
		}
		
		Mod(int num, int den) {
			this->val = ((long long)num*inv_mod(den))%mod;
		}
		
		Mod operator+(Mod a) {
			return Mod((val+a.val)%mod);
		}
		
		Mod operator+=(Mod a) {
			val = (val+a.val)%mod;
		}
		
		Mod operator-(Mod a) {
			return Mod((mod+val-a.val)%mod);
		}
		
		Mod operator-=(Mod a) {
			val = (mod+val-a.val)%mod;
		}
		
		Mod operator*(Mod a) {
			return Mod((val*a.val)%mod);
		}
		
		Mod operator*=(Mod a) {
			val = (val*a.val)%mod;
		}
		
		Mod operator/(Mod a) {
			return Mod((val*inv_mod(a.val))%mod);
		}
		
		Mod operator/=(Mod a) {
			val = (val*inv_mod(a.val))%mod;
		}
};

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	char s[200000];
	scanf("%s", s);
	for(i=0; s[i]; i++);
	n = i;
	Mod d[n+1][1<<3][1<<3]; //down, done
	d[0][0][0] = 1;
	for(i=0; i<n; i++) {
		for(j=0; j<(1<<3); j++) {
			for(k=0; k<(1<<3); k++) {
				for(l=0; l<(1<<3); l++) {
					if(s[i] == '1' || (l|j) == j) {
						if(l == 0) {
							if(s[i] == '1') {
								d[i+1][7][k] += d[i][j][k];
							} else {
								d[i+1][j][k] += d[i][j][k];
							}
						} else if(l == 7) {
							d[i+1][j][k] += d[i][j][k];
						} else {
							int o;
							if(l == 1 || l == 6) {
								o = 0;
							}
							if(l == 2 || l == 5) {
								o = 1;
							}
							if(l == 4 || l == 3) {
								o = 2;
							}
							int down = j;
							if(s[i] == '1') {
								down |= 7-l;
							}
							int done = k|(1<<o);
							d[i+1][down][done] += d[i][j][k];
						}
					}
				}
				//printf("%d ", d[i][j][k]);
			}
			//printf("\n");
		}
		//printf("\n");
	}
	/*for(j=0; j<8; j++) {
		for(k=0; k<8; k++) {
				printf("%d ", d[n][j][k]);
		}
			printf("\n");
	}
			printf("\n");*/
	Mod answer;
	for(i=0; i<(1<<3); i++) {
		answer += d[n][i][7];
	}
	printf("%d\n", answer.val);
}