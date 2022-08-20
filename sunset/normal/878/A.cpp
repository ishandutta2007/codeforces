#include <bits/stdc++.h>
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define mset(x, y) memset(x, y, sizeof x)
#define mcpy(x, y) memcpy(x, y, sizeof x)
using namespace std;

typedef long long LL;
typedef pair <int, int> pii;

inline int Read()
{
	int x = 0, f = 1, c = getchar();
	for (; !isdigit(c); c = getchar())
		if (c == '-')
			f = -1;
	for (;  isdigit(c); c = getchar())
		x = x * 10 + c - '0';
	return x * f;
}

int n, x, y = 1023;
char opt[3];

int main()
{
#ifdef wxh010910
	freopen("data.in", "r", stdin);
#endif
	n = Read();
	for (int i = 1, z; i <= n; i ++)
	{
		scanf("%s", opt), z = Read();
		if (opt[0] == '&')
			x &= z, y &= z;
		else if (opt[0] == '|')
			x |= z, y |= z;
		else
			x ^= z, y ^= z;
	}
	puts("2");
	printf("& %d\n", x ^ y);
	printf("^ %d\n", x);
	return 0;
}