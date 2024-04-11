#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <utility>
#include <ctime>
#include <cmath>

using namespace std;

#define ll long long
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); ++a)
#define iter(a) typeof(a.begin())
#define foreach(it, a) for(typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define sqr(a) (a)*(a)
#define PI 2.0*acos(0.0)

const int INF = 1000000001;
const double EPS = 1e-8;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	string s;
	cin >> s;
	int ans = 0;
	int i = 0;
	int cur = 0;
	char last = 0;
	while (i < s.length())
	{
		if (cur == 0)
		{
			cur++;
			last = s[i];
			i++;
		}
		else
		{
			if (s[i] == last && cur <= 4)
			{
				cur++;
				i++;
			}
			else
			{
				ans++;
				last = s[i];
				cur = 1;
				i++;
			}
		}
	}	
	if (cur != 0)
		ans++;
	cout << ans;
	return 0;
}