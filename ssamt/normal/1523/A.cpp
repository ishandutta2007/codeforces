#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <cmath>

int main() {
	int h, i, j, k;
	int t, n, m;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &m);
		char s[n+1];
		scanf("%s", s);
		for(i=0; i<n; i++) {
			if(s[i] == '0') {
				for(j=i; s[j]=='0' && j<n; j++);
				if(i == 0 && j == n) {
					;
				} else if(i == 0) {
					if(j <= m) {
						for(k=i; k<j; k++) {
							s[k] = '1';
						}
					} else {
						for(k=j-m; k<j; k++) {
							s[k] = '1';
						}
					}
				} else if(j == n) {
					if(n-i <= m) {
						for(k=i; k<j; k++) {
							s[k] = '1';
						}
					} else {
						for(k=i; k<i+m; k++) {
							s[k] = '1';
						}
					}
				} else if((j-i)%2 == 0) {
					if((j-i)/2 <= m) {
						for(k=i; k<j; k++) {
							s[k] = '1';
						}
					} else {
						for(k=i; k<i+m; k++) {
							s[k] = '1';
						}
						for(k=j-m; k<j; k++) {
							s[k] = '1';
						}
					}
				} else {
					if((j-i)/2 <= m) {
						for(k=i; k<i+(j-i)/2; k++) {
							s[k] = '1';
						}
						for(k=j-(j-i)/2; k<j; k++) {
							s[k] = '1';
						}
					} else {
						for(k=i; k<i+m; k++) {
							s[k] = '1';
						}
						for(k=j-m; k<j; k++) {
							s[k] = '1';
						}
					}
				}
				i = j;
			}
		}
		printf("%s\n", s);
	}
}