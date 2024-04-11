#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <math.h>
#include <vector>

int main() {
	int h, i, j, k;
	int t, n;
	scanf("%d", &t);
	char s[1001];
	int one[26];
	int two[26][26];
	int three[26][26][26];
	int f1, f2, f3;
	for(h=0; h<t; h++) {
		scanf("%d", &n);
		scanf("%s", s);
		memset(one, 0, sizeof(int)*26);
		for(i=0; i<n; i++) {
			one[s[i]-'a'] = 1;
		}
		for(i=0; i<26; i++) {
			if(!one[i]) {
				goto OUT1;
			}
		}
OUT1:
		if(i < 26) {
			printf("%c\n", i+'a');
			continue;
		}
		memset(two, 0, sizeof(int)*26*26);
		for(i=0; i<n-1; i++) {
			two[s[i]-'a'][s[i+1]-'a'] = 1;
		}
		for(i=0; i<26; i++) {
			for(j=0; j<26; j++) {
				if(!two[i][j]) {
					goto OUT2;
				}
			}
		}
OUT2:
		if(i < 26) {
			printf("%c%c\n", i+'a', j+'a');
			continue;
		}
		memset(three, 0, sizeof(int)*26*26*26);
		for(i=0; i<n-2; i++) {
			three[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a'] = 1;
		}
		for(i=0; i<26; i++) {
			for(j=0; j<26; j++) {
				for(k=0; k<26; k++) {
					if(!three[i][j][k]) {
						goto OUT3;
					}
				}
			}
		}
OUT3:
		if(i < 26) {
			printf("%c%c%c\n", i+'a', j+'a', k+'a');
			continue;
		}
	}
}