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
const int MAX = 100;
const int MAX2 = 7000;
const Int BASE = 1000000007;

const int MOD = 1000000007;

int main()
{


	int n,k;
	cin >> n >> k;
	if (n / 2 > k)
	{
		cout << -1 << endl;
		return 0;
	}
	
	if (n == 1)
	{
		if (k)
		{
			cout << -1 << endl;
		}
		else cout << 47 << endl;
		return 0;
	}

	int m = k - n / 2 + 1;

	cout << m << ' ' << 2 * m << ' ';

	FOR(i,1,n / 2)
	{
		cout << 2 * m + i * 2 << ' ' << 2 * m + i * 2 + 1 << ' ';
	}

	if (n % 2)
	{
		cout << 1000000000 << endl;
	}

	return 0;
}