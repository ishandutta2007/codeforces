#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <set>

#define ll long long int
#define clr(a) memset(a, 0, sizeof(a))
#define FOR(a, b) for (int a = 0; (a) < (b); a++)

using namespace std;
const int inf = 1000000000;
const double eps = 0.000000001;

set<ll> use;
int main()
{
//	freopen("input.txt", "r", stdin);
	int n;
	cin >> n;
	FOR(i, n)
	{
		char a[2][2];
		FOR(j, 2)
			FOR(g, 2)
			{cin >> skipws >> a[j][g] >> ws;;a[j][g] -= '0';}
		ll w = a[0][0] + a[0][1] * 10 + a[1][1] * 100 + a[1][0] * 1000;
		bool ind = false;
		FOR(i, 4)
		{
			if (use.find(w) != use.end()) {ind = true;break;}
			w = w / 1000 + (w % 1000) * 10;
		}
		if (!ind) use.insert(w);
		scanf(" ** ");
	}
	cout << use.size();
	return 0;
}