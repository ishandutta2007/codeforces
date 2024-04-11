//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

int T, n; 
char s[11];

int main() {
	scanf("%d", &T);
	while(T--) {
		while(getchar() != '\'');
		scanf("%s", s);
		n = atoi(s);
		int _ = 0, len = strlen(s);
		int _10 = 1;
		for(int i=1;i<len;i++) _ += (_10 *= 10);
		_10 *= 10;
		while(n < 1989 + _) n += _10;
		printf("%d\n", n);
	}
	return 0;
}