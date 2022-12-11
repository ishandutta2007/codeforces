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

char s[100001];


set<string> use;
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	scanf("%s", &s);
	int n = strlen(s);
	int a = 0;
	int b = 0;
	int c = 0;
	FOR(i, n)
	{
		if (s[i] == '0')
			a++;
		if (s[i] == '1')
			b++;
		if (s[i] == '?')
			c++;
	}
	bool ind = false;
	if (s[n - 1] == '?')
	{
		s[n - 1] = '0';
		a++;
		c--;
		ind = true;
	}

	FOR(i, c + 1)
	{
		int wa = a + i;
		int wb = n - wa;
		if (wa > wb)
			use.insert("00");
		else
			if (wa < wb - 1)
				use.insert("11");
			else
				if (s[n - 1] == '0')
					use.insert("10");
				else
					use.insert("01");

	}
	if (ind)
	{
		s[n - 1] = '1';
		a--;
		b++;
		FOR(i, c + 1)
	{
		int wa = a + i;
		int wb = n - wa;
		if (wa > wb)
			use.insert("00");
		else
			if (wa < wb - 1)
				use.insert("11");
			else
				if (s[n - 1] == '0')
					use.insert("10");
				else
					use.insert("01");

	}
	}
	foreach(use, it)
		cout << *it << '\n';


	return 0;
}