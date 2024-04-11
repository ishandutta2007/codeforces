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
const int MAXK = 200001;

char s[MAXK];
int ns[26][MAXK];
char s1[MAXK];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k;
	scanf("%d%d", &n, &k);	
	scanf("%s", &s);
	FOR(i, 26)
	{
		int wi = 0;
		while (wi < k && s[wi] != 'a' + i ) wi++;
		int p1 = wi++;
		while (wi < k && s[wi] != 'a' + i ) wi++;
		int p2 = wi;

		if (p1 >= k)
		{
			FOR(j, MAXK)
				ns[i][j] = -1;
			continue;
		}

		if (p2 >= k)
		{
			FOR(j, MAXK)
				ns[i][j] = abs(p1 - j);
			continue;
		}

		FOR(j, MAXK)
		{
			ns[i][j] = min(abs(p1 - j), abs(p2 - j));
			if (j == p2)
			{
				p1 = p2;
				wi = p1 + 1;
				while (wi < k && s[wi] != 'a' + i ) wi++;
				p2 = wi;
				if (p2 >= k)
					p2 = 2 * MAXK + 1;
			}
		}

	}
	/*FOR(i, 26)
	{
		FOR(j, k * 3)
			cerr << ns[i][j] << ' ';
		cerr << '\n';
	}*/

	FOR(i, n)
	{
		scanf("%s", &s1);
		int m = strlen(s1);
		ll ans = 0;
		FOR(j, m)
		{
			int l = s1[j] - 'a';
			if (ns[l][j] == -1) ans += m;
				else ans += ns[l][j];
		}

		printf("%I64d\n", ans);
	}

	return 0;
}