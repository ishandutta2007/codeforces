#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k;
	int t, n, m, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char key[27];
		scanf("%s", key);
		int pos[26];
		for(i=0; i<26; i++) {
			pos[key[i]-'a'] = i;
		}
		char s[51];
		scanf("%s", s);
		int answer = 0;
		for(i=1; s[i]; i++) {
			answer += abs(pos[s[i-1]-'a']-pos[s[i]-'a']);
		}
		printf("%d\n", answer);
	}
}