#include <bits/stdc++.h>

using namespace std;

char s[1111111];
int main() {
	
	int i, len, p, b, fst, ed;
	
	scanf("%s", s);
	len=strlen(s);
	
	for (i=0; i<len; i++) {
		if (s[i]!='.' && s[i]!='0') {
			fst=i; break;
		}
	}
	
	p=len;
	for (i=0; i<len; i++) {
		if (s[i]=='.') p=i;
	}
	
	if (fst<p) b=p-fst-1;
	else b=p-fst;
	
	printf("%c", s[fst]);
	
	for (i=len-1; i>=0; i--) {
		if (s[i]!='0' && s[i]!='.') {
			ed=i; break;
		}
	}
	
	if (ed>=fst+1) {
		printf(".");
		for (i=fst+1; i<=ed; i++) {
			if (s[i]!='.') printf("%c", s[i]);
		}
	}
	if (b) printf("E%d", b);
	puts("");
	
	return 0; 
}