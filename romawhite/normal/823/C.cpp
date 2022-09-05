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
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back

typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int MAX = 100074;

int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	Int k;
	cin >> n >> k;
	//n = 100;
	//k = 100000;

	VI B;

	vector<PII> A;

	Int sumA = 0;

	FOR(i, 0, n)
	{
		int a;
		cin >> a;
		//a = 1000000000 - 1;
		//a = rand() % 100000 + 1;
		B.push_back(a);

		sumA += a;
		--a;
		int x = 1;
		int prev = 1;
		while (x <= a)
		{
			int y = a / x;
			x = a / y + 1;

			A.push_back(MP(prev, y));
			A.push_back(MP(x, -y));
			prev = x;
		}
		A.push_back(MP(a + 1, 0));
	}

	//cout << SZ(A) << endl;

	/*int res2 = 0;
	FOR(r, 1, 1000000)
	{
	int s = 0;
	FOR(i, 0, n)
	{
	if (B[i] % r != 0)
	s += r - B[i] % r;
	}
	if (s <= k)
	res2 = r;
	}
	cout << res2 << ' ';*/


	sort(ALL(A));

	

	Int res = 0;
	Int cur = n;

	for (int i = 0; i < SZ(A);)
	{
		int add = 1;
		while (i + add < SZ(A) && A[i + add].first == A[i].first) ++add;
		FOR(j, 0, add)
		{
			cur += A[i + j].second;
		}

		

		Int maxD = (k + sumA) / cur;
		bool ok = 1;

		if (maxD < A[i].first) ok = 0;
		if (i + add < SZ(A)) maxD = min(maxD, (Int)A[i + add].first - 1);

		if (ok)
		{
			res = max(res, maxD);
		}

		i += add;
	}

	cout << res << endl;
	return 0;
}