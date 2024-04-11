#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <cmath>

int main() {
	int h, i, j;
	int k, q;
	int p, c;
	int n;
	scanf("%d", &k);
	n = 1<<k;
	char s[n];
	scanf("%s", s);
	scanf("%d", &q);
	char r[n+1];
	for(i=1; i<n; i++) {
		r[i] = s[n-1-i];
	}
	int tree[n+1];
	for(i=n-1; i>0; i--) {
		if(i >= n/2) {
			if(r[i] == '?') {
				tree[i] = 2;
			} else {
				tree[i] = 1;
			}
		} else {
			if(r[i] == '?') {
				tree[i] = tree[2*i]+tree[2*i+1];
			} else {
				tree[i] = tree[2*i+1-(r[i]-'0')];
			}
		}
	}
	for(h=0; h<q; h++) {
		scanf("%d %c", &p, &c);
		p = n-p;
		r[p] = c;
		for(i=p; i>0; i/=2) {
			if(i >= n/2) {
				if(r[i] == '?') {
					tree[i] = 2;
				} else {
					tree[i] = 1;
				}
			} else {
				if(r[i] == '?') {
					tree[i] = tree[2*i]+tree[2*i+1];
				} else {
					tree[i] = tree[2*i+1-(r[i]-'0')];
				}
			}
		}
		printf("%d\n", tree[1]);
	}
}