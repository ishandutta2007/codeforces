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
const int MAXN = 100002;


char s[MAXN];

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k;
	cin >> n >> k;
	scanf(" %s", &s);
	int i = 0;
	int cnt = 0;
	while (i < n - 1 && cnt < k)
	{
		if (s[i] == '4' && s[i + 1] == '7')
		{
			if (i % 2 == 0)
			{
				if (i == n - 2 || s[i + 2] != '7')
				{
					s[i + 1] = '4';
					cnt++;
				}
				else
				{
					if ((k - cnt) % 2 == 1)
						s[i + 1] = '4';
					cnt = k;
				}
			}
			else
			{
				if (i == 0 || s[i - 1] != '4')
				{
					s[i] = '7';
					cnt++;
				}
				else
				{
					if ((k - cnt) % 2 == 1)
						s[i] = '7';
					cnt = k;
				}
			}
		}
		i++;
	}
	printf("%s", s);
	return 0;
}