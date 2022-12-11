#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); a++)

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

ll b[256];

int main()
{
//	freopen("", "r", stdin);
//	freopen("", "w", stdout);
	string s;
	cin >> s;
	ll a = 0;
	clr(b);
	FOR(i, s.length())
		b[(int)s[i]]++;
	FOR(i, 256)
		a += b[i] * b[i];
	cout << a;
	return 0;
}