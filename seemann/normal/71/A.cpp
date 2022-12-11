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

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	cin >> n;
	FOR(i, n)
	{
		char s[110];
		scanf(" %s", &s);
		int m = strlen(s);
		if (m <= 10)
			printf("%s\n", s);
		else
		{
			printf("%c", s[0]);
			printf("%d", m - 2);
			printf("%c\n", s[m - 1]);
		}

	}
	return 0;
}