#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

const int N = 1005;

char s[N], t[N];

bool check(char c)
{
	return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
	scanf("%s%s", s + 1, t + 1);
	if (strlen(s + 1) != strlen(t + 1))
		return puts("No"), 0;
	int n = strlen(s + 1);
	for (int i = 1; i <= n; i++)
		if (check(s[i]) ^ check(t[i]))
			return puts("No"), 0;
	puts("Yes");
	return 0;
}