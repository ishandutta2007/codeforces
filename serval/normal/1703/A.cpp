#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;

char s[25];

int solve()
{
	scanf("%s", s + 1);
	s[1] |= 32;
	s[2] |= 32;
	s[3] |= 32;
	return strcmp(s + 1, "yes") == 0;
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T--)
		printf("%s\n", solve() ? "YES" : "NO");
	return 0;
}