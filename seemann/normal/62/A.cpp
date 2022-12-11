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
	int al, ar, bl, br;
	cin >> al >> ar >> bl >> br;
	bool ind1 = true;
	if (br < al - 1) ind1 = false;
	if (br > (al + 1) * 2) ind1 = false;
	bool ind2 = true;
	if (bl < ar - 1) ind2 = false;
	if (bl > (ar + 1) * 2) ind2 = false;
	if (ind1 ||ind2) printf("YES");
		else printf("NO");

	return 0;
}