#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
#include <stack>
#include <deque>
#include <cmath>
#include <memory.h>
#include <cstdlib>
#include <cstdio>
#include <cctype>
#include <algorithm>
#include <utility>
#include <time.h>
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define RFOR(i, b, a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979
#define x0 ikjnrmthklmnt
#define y0 lkrjhkltr
#define y1 ewrgrg

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<Int, Int> PLL;
typedef pair<double, double> PDD;
typedef complex<double> base;

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 200007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;


int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int d , n , m;
	cin >> d >> n >> m;
	vector<PII> A;

	A.push_back(MP(0,0));

	FOR(i,0,m)
	{
		int x , y;
		scanf("%d%d" , &x , &y);
		A.push_back(MP(x , y));
	}
	sort(ALL(A));

	vector<PII> B;
	FOR(i,0,m + 1)
	{
		B.push_back(MP(A[i].second, i));
	}
	sort(ALL(B));
	set<int> S;
	S.insert(-1);
	S.insert(m + 1);

	Int res = 0;

	A.push_back(MP(d , 0));
	FOR(i,0,A.size() - 1)
	{
		if (A[i + 1].first - A[i].first > n)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	FOR(i,0,B.size())
	{
		int id = B[i].second;
		Int p = B[i].first;
		set<int>::iterator it = S.lower_bound(id);
		int R = *it;
		--it;
		int L = *it;
		Int val = n;

		val = min(val , (Int)A[R].first - A[id].first);
		//cout << val << endl;
		if (L != -1)
		{
			val -= max(0, n - (A[id].first - A[L].first));
		}
		if (val < 0) val = 0;
		//cout << id << ' ' << val << ' ' << p << ' ' << A[id].first << endl;
		res += val * p;
		S.insert(id);
	}

	cout << res << endl;

    return 0;
}