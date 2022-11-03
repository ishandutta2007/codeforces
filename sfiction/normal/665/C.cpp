#include <cstdio>

const int MAXN = 2E5 + 10;

char s[MAXN];

int main(){
	scanf("%s", s);
	for (int i = 1; s[i]; ++i)
		if (s[i] == s[i - 1]){
			if (s[i - 1] != 'a' && s[i + 1] != 'a')
				s[i] = 'a';
			else if (s[i - 1] != 'b' && s[i + 1] != 'b')
				s[i] = 'b';
			else
				s[i] = 'c';
		}
	puts(s);
	return 0;
}