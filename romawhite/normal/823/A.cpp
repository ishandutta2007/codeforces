#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <memory.h>
#include <sstream>
#include <algorithm>
#include <math.h>

using namespace std;

#define FOR(i,a,b) for(int (i)=(a);(i)<(b);++(i))
#define RFOR(i,b,a) for(int (i)=(b)-1;(i)>=(a);--(i))
#define SZ(a) (int)a.size()
#define MP make_pair
#define PB push_back

typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	int k;
	cin >> n >> k;

	int D;

	FOR(d, 1, n + 1)
	{
		int r = d / 2;
		int cnt = 1LL * k * r + 1;
		if (d % 2 == 1) ++cnt;
		if (cnt >= n)
		{
			D = d;
			break;
		}
	}

	int cc = n - k - 1;
	vector<PII> E;
	int cur = 1;
	FOR(i, 0, k)
	{
		int r = D / 2;
		if (i == 0 && D % 2 == 1) ++r;
		int v = 1;
		FOR(j, 0, r - 1)
		{
			if (cc)
			{
				++cur;
				E.push_back(MP(v, cur));
				v = cur;
				--cc;
			}
		}
		++cur;
		E.push_back(MP(v, cur));
		v = cur;
	}

	cout << D << endl;
	FOR(i, 0, SZ(E))
	{
		printf("%d %d\n", E[i].first, E[i].second);
	}



	return 0;
}