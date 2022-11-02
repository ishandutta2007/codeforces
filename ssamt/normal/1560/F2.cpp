#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k, l;
	int t, n, k1;
	int bin[10];
	scanf("%d", &t);
	long long answer = INT_MAX;
	int d[10];
	int nlen;
	int found;
	for(h=0; h<t; h++) {
		scanf("%d %d", &n, &k1);
		for(i=0; i<10; i++) {
			d[i] = 0;
		}
		for(i=0; n>0; i++) {
			d[i] = n%10;
			n /= 10;
		}
		nlen = i;
		for(i=0; i<10; i++) {
			bin[i] = 0;
		}
		answer = INT_MAX;
		for(i=0; i<1024; i++) {
			bin[0]++;
			for(j=0; bin[j] == 2; j++) {
				bin[j] = 0;
				bin[j+1]++;
			}
			int sum = 0;
			for(j=0; j<10; j++) {
				sum += bin[j];
			}
			if(sum == k1) {
				int test[11] = {};
				int max, min;
				int lar[10];
				for(j=0; j<10; j++) {
					lar[j] = -1;
					for(k=j+1; k<10; k++) {
						if(bin[k] == 1) {
							lar[j] = k;
							break;
						}
					}
				}
				for(max=9; bin[max]==0; max--);
				for(min=0; bin[min]==0; min++);
				found = 1;
				for(j=nlen-1; j>=0; j--) {
					if(bin[d[j]] == 1) {
						test[j] = d[j];
						//printf("test[%d]=%d\n", j, d[j]);
					} else if(d[j] <= max) {
						test[j] = lar[d[j]];
						for(l=j-1; l>=0; l--) {
							test[l] = min;
						}
						break;
						//printf("test[%d]=%d\n", j, lar[d[j]]);
					} else {
						for(k=j+1; k<nlen && d[k]==max; k++);
						if(k == nlen) {
							found = 0;
							break;
						} else {
							test[k] = lar[d[k]];
							for(l=k-1; l>=0; l--) {
								test[l] = min;
							}
						}
						break;
					}
				}
				if(found) {
					long long num = 0;
					for(j=10; j>=0; j--) {
						num *= 10;
						num += test[j];
					}
					//printf("%lld %lld\n", num, answer);
					if(num < answer) {
						answer = num;
						//printf("answer: %lld\n", answer);
					}
				}
			}
		}
		printf("%d\n", answer);
	}
}