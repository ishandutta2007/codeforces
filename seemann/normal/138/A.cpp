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
const int MAXN = 10001;

string s[MAXN];
string ss;

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k;
	cin >> n >> k;
	FOR(i, 4 * n)
	{
		cin >> ss;
		int j = ss.length() - 1;
		int c = 0;
		while (j >= 0 && c < k)
		{
			if (ss[j] == 'a' || ss[j] == 'e' || ss[j] == 'i' || ss[j] == 'o' || ss[j] == 'u')
				c++;
			j--;
		}
		j++;
		s[i] = ss.substr(j, ss.length() - j);
		if (c < k)
			s[i] = (char)(i % 4 + 1) + s[i];
	}
	string ans;
	string lans;
	FOR(i, n)
	{
		if (s[4 * i] == s[4 * i + 1] && s[4 * i + 2] == s[4 * i + 3] && s[4 * i] == s[4 * i + 2])
			ans = "aaaa";
		else
		{
			if (s[4 * i] == s[4 * i + 1] && s[4 * i + 2] == s[4 * i + 3])
				ans = "aabb";
			else
				if (s[4 * i] == s[4 * i + 2] && s[4 * i + 1] == s[4 * i + 3])
					ans = "abab";
				else
					if (s[4 * i] == s[4 * i + 3] && s[4 * i + 2] == s[4 * i + 1])
						ans = "abba";
					else
						ans = "NO";
		}
		if (i == 0)
		{
			lans = ans;
			continue;
		}
		if (lans == "NO")
			break;
		if (ans == "NO")
			lans = "NO";
		if (lans == "aaaa")
			lans = ans;
		if (ans == "aaaa")
			continue;
		if (ans != lans)
			lans = "NO";
	}
	cout << lans;
	return 0;
}