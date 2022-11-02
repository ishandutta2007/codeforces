#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[101];
		char t[4];
		scanf("%s", s);
		scanf("%s", t);
		int count[26] = {};
		for(i=0; s[i]; i++) {
			count[s[i]-'a']++;
		}
		if(!strcmp(t, "abc") && count[0]) {
			for(i=0; i<26; i++) {
				int c = i;
				if(c == 1) {
					c = 2;
				} else if(c == 2) {
					c = 1;
				}
				for(j=0; j<count[c]; j++) {
					printf("%c", c+'a');
				}
			}
		} else {
			for(i=0; i<26; i++) {
				for(j=0; j<count[i]; j++) {
					printf("%c", i+'a');
				}
			}
		}
		printf("\n");
	}
}