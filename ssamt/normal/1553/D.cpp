#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int main() {
	int h, i, j, k;
	int q, n;
	int start;
	char s[100000+1];
	char t[100000+1];
	int slen, tlen;
	int found;
	scanf("%d", &q);
	for(h=0; h<q; h++) {
		scanf("%s", s);
		scanf("%s", t);
		for(i=0; s[i]; i++);
		slen = i;
		for(i=0; t[i]; i++);
		tlen = i;
		found = 0;
		for(start=0; start<2; start++) {
			i = start;
			j = 0;
			while(i<slen && j<tlen) {
				if(s[i] == t[j]) {
					i++;
					j++;
				} else {
					i += 2;
				}
			}
			if(j == tlen && (i-slen)%2 == 0) {
				found = 1;
				break;
			}
		}
		if(found) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}