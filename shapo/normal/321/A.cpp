#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#define maxn 150

typedef long long ll;

char s[maxn];
int lens;
int addx, addy;
int a, b;

int main()
{
	scanf("%d%d", &a, &b);
	scanf(" %s", s);
	lens = strlen(s);
	addx = addy = 0;
	for (int i = 0; i < lens; ++i)
	{
		if (s[i] == 'U')
			++addy;
		if (s[i] == 'D')
			--addy;
		if (s[i] == 'L')
			--addx;
		if (s[i] == 'R')
			++addx;
	}
	int curx = 0, cury = 0;
	for (int i = 0; i < lens; ++i)
	{
		int dx = a - curx, dy = b - cury;
		if (s[i] == 'U')
			++cury;
		if (s[i] == 'D')
			--cury;
		if (s[i] == 'L')
			--curx;
		if (s[i] == 'R')
			++curx;
		if (dx == 0 && dy == 0)
		{
			printf("Yes\n");
			return 0;
		}
		if (addx != 0 || addy != 0)
		{
			int dk = (addx != 0) ? (dx / addx) : (dy / addy);
			if (dk > 0 && (ll)dk * addx == (ll)dx && (ll)dk * addy == (ll)dy)
			{
				printf("Yes\n");
				return 0;
			}
		}
	}
	printf("No\n");
	return 0;
}