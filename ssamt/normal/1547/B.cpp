#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <vector>

int cmp(const void* num1, const void* num2) {
	char a = *(char*)num1;
	char b = *(char*)num2;
	if(a > b) {
		return 1;
	} else if(a < b) {
		return -1;
	} else {
		return 0;
	}
}

int main() {
	int h, i, j, k;
	int t, n;
	char s[27];
	char copy[27];
	int pos;
	scanf("%d", &t);
	for(h=0; h<t; h++) {
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		for(i=0; i<n; i++) {
			copy[i] = s[i];
		}
		qsort(copy, n, sizeof(char), cmp);
		int check2 = 1;
		for(i=0; i<n; i++) {
			if(copy[i] != 'a'+i) {
				check2 = 0;
				break;
			}
		}
		if(check2) {
			int found = 0;
			for(i=0; i<n; i++) {
				for(j=i+1; j<n; j++) {
					if(s[i] == s[j]) {
						found = 1;
						break;
					}
				}
			}
			if(!found) {
				int check = 1;
				for(i=0; i<n; i++) {
					if(s[i] == 'a') {
						pos = i;
						break;
					}
				}
				for(i=pos; i>0; i--) {
					if(s[i-1] < s[i]) {
						check = 0;
						break;
					}
				}
				for(i=pos; i<n-1; i++) {
					if(s[i] > s[i+1]) {
						check = 0;
						break;
					}
				}
				if(check) {
					printf("YES\n");
				} else {
					printf("NO\n");
				}
			} else {
				printf("NO\n");
			}
		} else {
			printf("NO\n");
		}
	}
}