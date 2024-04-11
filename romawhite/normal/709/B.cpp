#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
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
const int MAXV = 120;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int solve(VI a, int s)
{
	bool q1 = 1;
	bool q2 = 1;
	FOR(i,0,SZ(a))
	{
		if (a[i] > s)
			q1 = 0;
		if (a[i] < s)
			q2 = 0;
	}
	if (q1) return s - a[0];
	if (q2) return a.back() - s;
	return min(s - a[0] , a.back() - s) + a.back() - a[0];
}
int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n , s;
	cin >> n >> s;

	if (n == 1)
	{
		cout << 0 << endl;
		return 0;
	}

	VI A(n);
	FOR(i,0,n)
	{
		cin >> A[i];
	}

	sort(ALL(A));

	VI B;
	FOR(i,1,SZ(A))
		B.push_back(A[i]);
	A.pop_back();

	int res = min(solve(A , s) , solve(B , s));
	cout << res << endl;


    return 0;
}