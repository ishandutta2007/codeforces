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
#include <fstream>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))

#define ALL(V) V.begin(),V.end()
#define SZ(V) (int)V.size()
#define PB push_back
#define MP make_pair

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int,int> PII;

const double Pi = acos(-1.0);
const int INF = 1000000000;
const int MAX = 107;
const int MAX2 = 2000000;
const int BASE = 10;
const int ST = 1000003;
const int CNT = 100;

const int MOD = 1000000007;

int R[MAX][MAX];

int main()
{
	//freopen("out.txt" , "w" , stdout);
	//freopen("in.txt", "r", stdin);
	//freopen("puzzle.in", "r", stdin);
	//freopen("puzzle.out", "w", stdout);

	int n , m , q;
	cin >> n >> m >> q;
	vector<PII> A;
	FOR(i,0,q)
	{
		int t;
		scanf("%d" , &t);
		if (t <= 2)
		{
			int r;
			scanf("%d" , &r);
			--r;
			A.push_back(MP(t , r));
		}
		else
		{
			int x , y, val;
			scanf("%d%d%d" , &x , &y , &val);
			--x;--y;
			RFOR(j,A.size() , 0)
			{
				if (A[j].first == 1 && x == A[j].second)
				{
					y = (y + 1) % m;
				}
				if (A[j].first == 2 && y == A[j].second)
				{
					x = (x + 1) % n;
				}
			}


			R[x][y] = val;
		}
	}

	FOR(i,0,n)
	{
		FOR(j,0,m)
		{
			cout << R[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}