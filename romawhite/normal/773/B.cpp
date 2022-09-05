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
const int MAX = 207;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

int a[MAX][5];
int cnt[5];


int score(int n, int k)
{
	if (k * 32 <= n) return 3000;
	if (k * 16 <= n) return 2500;
	if (k * 8 <= n) return 2000;
	if (k * 4 <= n) return 1500;
	if (k * 2 <= n) return 1000;
	return 500;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	int n;
	cin >> n;

	FOR(i,0,n)
	{
		FOR(j,0,5)
		{
			cin >> a[i][j];
			if (a[i][j] != -1) ++ cnt[j];
		}
	}

	FOR(nn,n,10000)
	{
		int score1 = 0;
		int score2 = 0;

		FOR(j,0,5)
		{
			int sc;
			if (a[0][j] == -1 || a[1][j] == -1 || a[0][j] < a[1][j])
			{
				sc = score(nn , cnt[j]);
			}
			else
			{
				sc = score(nn , cnt[j] + nn - n);
			}

			if (a[0][j] != -1)
				score1 += sc - sc * a[0][j] / 250;
			if (a[1][j] != -1)
				score2 += sc - sc * a[1][j] / 250;
		}

		if (score1 > score2)
		{
			cout << nn - n << endl;
			return 0;
		}
	}

	cout << -1 << endl;


    return 0;
}