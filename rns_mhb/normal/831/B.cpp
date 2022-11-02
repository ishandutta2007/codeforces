#include <bits/stdc++.h>
using namespace std;

int c[500];
char a[100], b[100], s[11100];

char ch(char x) {
	int d = 0;
	if ('0' <= x && x <= '9') return x;
	if ('A'<= x && x <= 'Z') d += 'Z' - 'z';
	char out = c[x - d - 'a'] + 'a' + d;
	return out;
}

int main() {
	scanf("%s%s", a, b);
	for (int i = 0; i < 26; i ++) c[a[i] - 'a'] = b[i] - 'a';
	scanf("%s", s);
	int len = strlen(s);
	for (int i = 0; i < len; i ++) printf("%c", ch(s[i]));
}