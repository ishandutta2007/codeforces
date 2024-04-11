#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int u, v;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		scanf("%d", &n);
		char s[n][4];
		int answer = 0;
		int two[26][26];
		for(i=0; i<26; i++) {
			for(j=0; j<26; j++) {
				two[i][j] = -1;
			}
		}
		int three[26][26][26];
		for(i=0; i<26; i++) {
			for(j=0; j<26; j++) {
				for(k=0; k<26; k++) {
					three[i][j][k] = -1;
				}
			}
		}
		int len[n];
		for(i=0; i<n; i++) {
			scanf("%s", s[i]);
			for(j=0; s[i][j]; j++);
			len[i] = j;
			if(len[i] == 1) {
				answer = 1;
			} else if(len[i] == 2) {
				two[s[i][0]-'a'][s[i][1]-'a'] = i;
			} else {
				three[s[i][0]-'a'][s[i][1]-'a'][s[i][2]-'a'] = i;
			}
		}
		for(i=0; i<n; i++) {
			if(len[i] == 2) {
				if(two[s[i][1]-'a'][s[i][0]-'a'] > i) {
					answer = 1;
				}
				for(j=0; j<26; j++) {
					if(three[j][s[i][1]-'a'][s[i][0]-'a'] > i) {
						answer = 1;
					}
				}
				if(s[i][0] == s[i][1]) {
					answer = 1;
				}
			} else if(len[i] == 3) {
				if(two[s[i][1]-'a'][s[i][0]-'a'] > i) {
					answer = 1;
				}
				if(three[s[i][2]-'a'][s[i][1]-'a'][s[i][0]-'a'] > i) {
					answer = 1;
				}
				if(s[i][0] == s[i][2]) {
					answer = 1;
				}
			}
		}
		if(answer) {
			printf("YES\n");
	    } else {
	    	printf("NO\n");
		}
	}
}