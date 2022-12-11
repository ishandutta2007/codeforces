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

const long double EPS = 1e-9;
const int INF = 1000000001;

int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n;
	int R, r;
	cin >> n >> R >> r;
	if (r > R)
	{
		cout << "NO";
		return 0;
	}
	if (2 * r > R) 
	{
		if (n <= 1)
			cout << "YES";
		else
			cout << "NO";
		return 0;
	}
	long double a =	asin((long double)r/(long double)(R - r));
	if (2 * acos(0.0) / a - n > -EPS)
		cout << "YES";
	else
		cout << "NO";
	return 0;
}