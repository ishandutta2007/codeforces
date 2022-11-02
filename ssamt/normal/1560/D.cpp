#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	long long exp;
	int dn[20];
	int de[20];
	int nlen, elen;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		for(i=0; n>0; i++) {
			dn[i] = n%10;
			n /= 10;
		}
		nlen = i;
		int min = 10;
		for(i=0; i<20; i++) {
			de[i] = 0;
		}
		de[0] = 1;
		for(;;) {
			for(i=19; de[i]==0; i--);
			elen = i+1;
			if(elen >= nlen+min) {
				break;
			}
			for(i=nlen-1, j=elen-1; i>=0 && j>=0;) {
				if(dn[i] == de[j]) {
					i--;
					j--;
				} else {
					i--;
				}
			}
			int count;
			if(j == -1) {
				count = (j+1)+(nlen-(elen-j-1));
			} else {
				count = (j+1)+(nlen-(elen-j-1));
			}
			if(count < min) {
				min = count;
			}
			de[19] *= 2;
			for(i=18; i>=0; i--) {
				de[i] *= 2;
				if(de[i] >= 10) {
					de[i+1] += de[i]/10;
					for(j=i+1; de[j]==10; j++) {
						de[j] = 0;
						de[j+1]++;
					}
					de[i] %= 10;
				}
			}
		}
		printf("%d\n", min);
	}
}