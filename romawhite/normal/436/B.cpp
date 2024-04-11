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
#include <functional>
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
const double Pi = acos(-1.0);

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MOD = 1000000007;

string s[2005];
char buf[2005];

int res[2005];

int main()
{
	int n,m,k;
	cin >> n >> m >> k;

	FOR(i,0,n)
	{
		scanf("%s" , buf);
		s[i] = buf;
	}

	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			if (s[i][j] == 'U')
			{
				if (i % 2 == 0)
					++res[j];
			}
			if (s[i][j] == 'R')
			{
				if (i + j < m)
				{
					res[i + j]++;
				}
			}
			if (s[i][j] == 'L')
			{
				if (j - i >= 0)
				{
					res[j - i]++;
				}
			}
		}
	}
	FOR(i,0,m)
	{
		cout << res[i] << ' ';
	}
    return 0;
}