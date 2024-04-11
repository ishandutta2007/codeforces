#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, m, q;
	int in;
	scanf("%d %d", &n, &q);
	char s[n+1];
	scanf("%s", s);
	int answer = 0;
	for(i=0; i<n-2; i++) {
		if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
			answer++;
		}
	}
	for(ql=0; ql<q; ql++) {
		int pos;
		char c;
		scanf("%d %c", &pos, &c);
		pos--;
		for(i=pos-2; i<=pos; i++) {
			if(0<=i && (i+2)<n) {
				if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
					answer--;
				}
			}
		}
		s[pos] = c;
		for(i=pos-2; i<=pos; i++) {
			if(0<=i && (i+2)<n) {
				if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'c') {
					answer++;
				}
			}
		}
		printf("%d\n", answer);
	}
}