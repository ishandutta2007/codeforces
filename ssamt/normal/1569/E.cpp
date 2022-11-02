#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

long long ipow(int base, int pow)
{
	int i;
	long long answer = 1;
	for(i=0; i<pow; i++)
		answer *= base;
	return answer;
}

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

int ilog(int b, int n) {
	int j, k;
	for(j=1, k=0; j<=n; j*=b, k++);
	return k-1;
}

int main() {
	int i, j, l;
	int t, n, m;
	long long mod = 998244353;
	long long k, a, h;
	scanf("%lld %lld %lld", &k, &a, &h);
	int pow2[k+1];
	pow2[0] = 1;
	for(i=1; i<=k; i++) {
		pow2[i] = 2*pow2[i-1];
	}
	int powk = ipow(2, k), powk1 = ipow(2, k-1);
	h = (h*inv_mod(a, mod))%mod;
	int start[k+1];
	int end[k+1];
	long long mul[k+1];
	int sum[k+1];
	start[0] = 1;
	end[0] = powk;
	mul[0] = 1;
	for(i=1; i<=k; i++) {
		start[i] = (1+(ipow(2, k)-ipow(2, k-i+1)+1))/2*ipow(2, i-1);
		end[i] = (ipow(2, k-i+1)+ipow(2, k))/2*ipow(2, i-1);
		if(i == 1) {
			mul[i] = a;
		} else {
			mul[i] = (mul[i-1]*mul[i-1])%mod;
		}
	}
	for(i=0; i<=k; i++) {
		sum[i] = start[i];
	}
	vector<vector<int> > pos;
	int total = 0;
	for(i=1; i<=k; i++) {
		total += sum[i];
	}
	while(1) {
		if(start[0] <= pow2[k]*(pow2[k]+1)/2-total && pow2[k]*(pow2[k]+1)/2-total <= end[0]) {
			sum[0] = pow2[k]*(pow2[k]+1)/2-total;
			long long res = 0;
			for(i=0; i<=k; i++) {
				res = (res+(sum[i]*mul[i])%mod)%mod;
			}
			if(res == h) {
				vector<int> e;
				for(i=0; i<=k; i++) {
					e.push_back(sum[i]);
				}
				pos.push_back(e);
			}
		}
		total++;
		sum[1]++;
		for(i=1; i<=k; i++) {
			if(sum[i] == end[i]+1) {
				if(i == k) {
					goto OUT1;
				} else {
					total -= sum[i]-start[i];
					sum[i] = start[i];
					total++;
					sum[i+1]++;
				}
			} else {
				break;
			}
		}
	}
OUT1:
	int found = 0;
	int answer[ipow(2, k)];
	for(j=0; j<pos.size(); j++) {
		int win[ipow(2, k-1)] = {};
		while(1) {
			int p[ipow(2, k-1)];
			int tree[ipow(2, k)];
			for(i=ipow(2, k)-1; i>0; i--) {
				if(i >= ipow(2, k-1)) {
					tree[i] = i-ipow(2, k-1);
				} else {
					tree[i] = tree[2*i+win[i]];
				}
			}
			for(i=ipow(2, k)-1; i>0; i--) {
				p[tree[i]] = ilog(2, i);
			}
			int check = 1;
			for(i=0; i<k; i++) {
				int minsum = 0, maxsum = 0;
				for(l=0; l<pow2[k-1]; l++) {
					if(p[l] == i) {
						minsum += 2*l+1;
						maxsum += 2*l+2;
					}
				}
				if(pos[j][i] < minsum || maxsum < pos[j][i]) {
					check = 0;
					break;
				}
			}
			if(check) {
				for(i=0; i<k; i++) {
					int minsum = 0, maxsum = 0;
					for(l=0; l<pow2[k-1]; l++) {
						if(p[l] == i) {
							minsum += 2*l+1;
							maxsum += 2*l+2;
						}
					}
					int count = 0;
					for(l=0; l<pow2[k-1]; l++) {
						if(p[l] == i) {
							if(count < pos[j][i]-minsum) {
								answer[2*l] = pow2[k-1]+1;
								if(i == 0) {
									answer[2*l+1] = 1;
								} else {
									answer[2*l+1] = pow2[i-1]+1;
								}
							} else {
								answer[2*l+1] = pow2[k-1]+1;
								if(i == 0) {
									answer[2*l] = 1;
								} else {
									answer[2*l] = pow2[i-1]+1;
								}
							}
							count++;
						}
					}
				}
				found = 1;
				goto OUT2;
			}
			win[1]++;
			for(i=1; i<pow2[k-1]; i++) {
				if(win[i] == 2) {
					if(i == pow2[k-1]-1) {
						goto OUT3;
					} else {
						win[i] = 0;
						win[i+1]++;
					}
				}
			}
		}
OUT3:;
	}
OUT2:
	if(found) {
		for(i=0; i<ipow(2, k); i++) {
			printf("%d ", answer[i]);
		}
		printf("\n");
	} else {
		printf("-1\n");
	}
}