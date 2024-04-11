#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

int main() {
	int h, i, j, k;
	int t1, n;
	char s[1000];
	char t[1000];
	int a, b;
	int idx;
	int found;
	scanf("%d", &t1);
	for(h=0; h<t1; h++) {
		scanf("%s", s);
		scanf("%s", t);
		for(a=0; s[a]; a++);
		for(b=0; t[b]; b++);
		for(i=0; i<a; i++) {
			for(j=0; j<b; j++) {
				found = 1;
				for(k=0, idx=i; k<b; k++) {
					if(!(0<=idx && idx<a) || s[idx] != t[k]) {
						found = 0;
						break;
					}
					if(k >= j) {
						idx--;
					} else {
						idx++;
					}
				}
				if(found) {
					goto OUT;
				}
			}
		}
OUT:
		if(found) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}