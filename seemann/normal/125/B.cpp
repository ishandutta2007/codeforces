#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <utility>
#include <set>
#include <map>
#include <vector>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for(int a = 0; a < (b); a++)
#define iter(a) typeof(a.begin())
#define foreach(a, it) for(typeof(a.begin()) it = a.begin(); it != a.end(); it++)

using namespace std;

const long double EPS = 1e-8;
const int INF = 1000000001;
char s[3000];
int main()
{
//	freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);

	clr(s);
	int lv = 0;
	scanf(" %s", &s);
	int i = 0;
	int n = strlen(s);
	while (i < n)
	{
		i++;
		FOR(j, 2 * lv - 2)
		{
			putc(' ', stdout);
		}
		if (s[i] != '/')
		{
			if (lv != 0)
			{
				putc(' ', stdout);
				putc(' ', stdout);
			}
			printf("<%c>", s[i]);
			lv++;
			i += 2;
		}
		else
		{
			i++;
			printf("</%c>", s[i]);
			i += 2;
			lv--;
		}
		printf("\n");
	}

	return 0;
}