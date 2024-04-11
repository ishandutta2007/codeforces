#include <bits/stdc++.h>

using namespace std;

char s[100100];

int main() {
	scanf("%s", s);
	int len = strlen(s);
	int k = len - 1;
	for(int i = 0; i < len; i ++) if(s[i] == '0') {
		k = i; break;
	}
	for(int i = 0; i < len; i ++) if(i != k) putchar(s[i]); puts("");
	return 0;
}