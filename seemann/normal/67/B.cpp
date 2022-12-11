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

int b[1001];
int wb[1001];
int cw;
vector<int> a;
int m = 0;
int main()
{
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
	//freopen("", "w", stderr);
	int n, k;
	scanf("%d%d", &n, &k);
	a.resize(n + 1);
	FOR(i, n)
	{
		scanf("%d", &b[i]);
	}
	FOR(i, n)
	{
		cw = 0;
		FOR(j, n)
			if(b[j] == i) wb[cw++] = j;

		FOR(g, cw)
		{
			int c = 0;
			int q = 0;
			for (q = 0; q < m && c < i; ++q)
			       if (a[q] >= wb[g] + k) c++;
			while (q < m && a[q] < wb[g]) q++;
			a.insert(a.begin() + q, wb[g]);
			m++;
		}

		if (m == n) break;
	}
	FOR(i, n)
		printf("%d ", a[i] + 1);
		
	return 0;
}