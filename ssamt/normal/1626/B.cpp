#include <bits/stdc++.h>

using namespace std;

int main() {
	int cl, ql;
	int i, j, k, l;
	int t, n, q;
	int in;
	scanf("%d", &t);
	for(cl=0; cl<t; cl++) {
		char s[200000];
		scanf("%s", s);
		for(i=0; s[i]; i++);
		n = i;
		int find = 0;
		for(i=n-2; i>=0; i--) {
			if(s[i]-'0'+s[i+1]-'0' >= 10) {
				find = 1;
				break;
			}
		}
		if(find) {
			int sum = s[i]-'0'+s[i+1]-'0';
			s[i] = sum/10+'0';
			s[i+1] = sum%10+'0';
			printf("%s\n", s);
		} else {
			printf("%c", s[0]+s[1]-'0');
			for(i=2; i<n; i++) {
				printf("%c", s[i]);
			}
			printf("\n");
		}
	}
}