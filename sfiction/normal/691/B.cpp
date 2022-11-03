#include <cstdio>
#include <cstring>

char a[128];
char s[2000];

int main(){
	memset(a, -1, sizeof(a));
	a['b'] = 'd';
	a['d'] = 'b';
	a['p'] = 'q';
	a['q'] = 'p';
	a['A'] = 'A';
	a['H'] = 'H';
	a['I'] = 'I';
	a['M'] = 'M';
	a['O'] = 'O';
	a['o'] = 'o';
	a['T'] = 'T';
	a['U'] = 'U';
	a['V'] = 'V';
	a['v'] = 'v';
	a['W'] = 'W';
	a['w'] = 'w';
	a['X'] = 'X';
	a['x'] = 'x';
	a['Y'] = 'Y';
	scanf("%s", s);
	int n = strlen(s);
	bool flag = true;
	for (int i = 0, j = n - 1; i <= j; ++i, --j)
		flag &= a[s[i]] == s[j];
	puts(flag ? "TAK" : "NIE");
	return 0;
}