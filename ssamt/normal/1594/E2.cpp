#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <queue>
#include <string>
#include <map>

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

long long ipow(int base, int pow)
{
	int i;
	long long answer = 1;
	for(i=0; i<pow; i++)
		answer *= base;
	return answer;
}

int e1(int k, int mod) {
	long long pow = pow_mod(2, k, mod-1);
	pow = (mod+pow-2)%mod;
	long long answer = pow_mod(4, pow, mod);
	return answer;
}

int main() {
	int h, i, j, l;
	int t, n, m, k;
	char s[10];
	long long mod = 1000000007;
	scanf("%d", &k);
	scanf("%d", &n);
	priority_queue<long long> a;
	long long in;
	map<long long, int> color;
	map<long long, vector<int> > tree;
	int ec[k+1];
	for(i=1; i<=k; i++) {
		ec[i] = e1(i, mod);
	}
	for(i=0; i<n; i++) {
		scanf("%lld %s", &in, s);
		a.push(in);
		if(s[0] == 'w') {
			color[in] = 0;
		} else if(s[0] == 'g') {
			color[in] = 1;
		} else if(s[0] == 'r') {
			color[in] = 2;
		} else if(s[0] == 'y') {
			color[in] = 3;
		} else if(s[0] == 'b') {
			color[in] = 4;
		} else if(s[0] == 'o') {
			color[in] = 5;
		}
	}
	long long idx, last = 0;
	while(!a.empty()) {
		idx = a.top();
		a.pop();
		if(idx != last) {
			vector<int> e(6);
			for(i=0; i<6; i++) {
				e[i] = 0;
				if(!color.count(idx) || (color.count(idx) && color[idx] == i)) {
					if(ipow(2, k-1) <= idx) {
						e[i] = 1;
					} else {
						for(j=0; j<6; j++) {
							if(i%3 != j%3) {
								for(l=0; l<6; l++) {
									if(i%3 != l%3) {
										int mul[2];
										if(tree.count(2*idx)) {
											mul[0] = tree[2*idx][j];
										} else {
											for(h=63; !((2*idx)&((long long)1<<h)); h--);
											mul[0] = ec[k-h];
										}
										if(tree.count(2*idx+1)) {
											mul[1] = tree[2*idx+1][l];
										} else {
											for(h=63; !((2*idx+1)&((long long)1<<h)); h--);
											mul[1] = ec[k-h];
										}
										//printf("mul:%d %d\n", mul[0], mul[1]);
										e[i] = (e[i]+(long long)mul[0]*mul[1])%mod;
									}
								}
							}
						}
					}
				}
			}
			/*printf("%lld\n", idx);
			for(i=0; i<6; i++) {
				printf("%d ", e[i]);
			}
			printf("\n");*/
			tree[idx] = e;
			if(idx == 1) {
				long long answer = 0;
				for(i=0; i<6; i++) {
					answer += e[i];
				}
				printf("%lld\n", answer%mod);
				return 0;
			}
			a.push(idx/2);
			last = idx;
		}
	}
}