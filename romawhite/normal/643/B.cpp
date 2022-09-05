#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
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
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)
#define FILL(A,value) memset(A,value,sizeof(A))

#define ALL(V) V.begin(), V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair
#define Pi 3.14159265358979

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 107;
const int MAX2 = 207;
const int BASE = 1000000000;
const int CNT = 500;
const int MOD = 1000000007;


int main()
{
    //freopen("in.txt", "r", stdin);

	int n , k;
	cin >> n >> k;
	int a , b , c , d;
	cin >> a >> b >> c >> d;
	--a;--b;--c;--d;

	if (n == 4)
	{
		cout << -1 << endl;
		return 0;
	}

	if (k < n + 1)
	{
		cout << -1 << endl;
		return 0;
	}

	VI A;
	FOR(i,0,n)
	{
		if (i == a || i == b || i == c || i == d) continue;
		A.push_back(i);
	}

	cout << a + 1 << ' ' << c + 1 << ' ';
	FOR(i,0,A.size())
	{
		cout << A[i] + 1 << ' ';
	}
	cout << d + 1 << ' ' << b + 1 << endl;
	cout << c + 1 << ' ' << a + 1 << ' ';
	FOR(i,0,A.size())
	{
		cout << A[i] + 1 << ' ';
	}
	cout << b + 1 << ' ' << d + 1 << endl;


    return 0;
}