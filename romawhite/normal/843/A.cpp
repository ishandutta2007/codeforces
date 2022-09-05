
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

const int INF = 1000000000;
const int BASE = 1000000007;
const int MAX = 100007;
const int MAX2 = 10007;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 0;

bool U[MAX];


int main()
{
	//freopen("in.txt", "r", stdin);

	int n;
	cin >> n;
	vector<PII> A(n);
	FOR(i,0,n)
	{
		scanf("%d" , &A[i].first);
		A[i].second = i;
	}
	sort(ALL(A));

	vector<VI> res;
	FOR(i,0,n)
	{
		if (U[i]) continue;
		int v = i;
		VI R;
		while (!U[v])
		{
			R.push_back(v);
			U[v] = 1;
			v = A[v].second;
		}
		res.push_back(R);
	}
	cout << SZ(res) << endl;
	FOR(i,0,SZ(res))
	{
		printf("%d" , SZ(res[i]));
		FOR(j,0,SZ(res[i]))
		{
			printf(" %d" , res[i][j] + 1);
		}
		printf("\n");
	}

	return 0;
}