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

int main() {
	int h, i, j, k;
	int t, n, m;
	long long mod = 1000000007;
	long long a[14];
	long long mem[1<<14];
	long long part[1<<14][14];
	scanf("%d", &n);
	for(i=0; i<n; i++) {
		scanf("%d", &a[i]);
	}
	int b, c, bs;
	long long answer = 0;
	for(c=1; c<=n; c++) {
		for(b=1; b<(1<<n); b++) {
			int ones = 0;
			for(i=0; i<n; i++) {
				if(b&(1<<i)) {
					ones++;
				}
			}
			if(ones == c) {
				mem[b] = 1;
				for(bs=1; bs<(1<<n); bs++) {
					int check = 1;
					for(i=0; i<n; i++) {
						if(!(b&(1<<i)) && bs&(1<<i)) {
							check = 0;
							break;
						}
					}
					if(check && b != bs) {
						long long prob = mem[bs];
						for(i=0; i<n; i++) {
							if(b&(1<<i) && !(bs&(1<<i))) {
								prob = (prob*part[bs][i])%mod;
							}
						}
						mem[b] = (mem[b]-prob+mod)%mod;
					}
				}
				for(i=0; i<n; i++) {
                    part[b][i] = 1;
					if(!(b&(1<<i))) {
						for(j=0; j<n; j++) {
							if(b&(1<<j)) {
								part[b][i] = (part[b][i]*a[j])%mod;
								part[b][i] = (part[b][i]*inv_mod(a[i]+a[j], mod))%mod;
							}
						}
					}
				}
				long long total = 1;
				for(i=0; i<n; i++) {
					if(!(b&(1<<i))) {
						total = (total*part[b][i])%mod;
					}
				}
				answer = (answer+(mem[b]*total)%mod*c)%mod;
			}
		}
	}
	printf("%lld", answer);
}