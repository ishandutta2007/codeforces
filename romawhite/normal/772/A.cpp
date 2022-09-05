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
const int MAX = 200000;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n, p;
int A[MAX];
int B[MAX];

int main()
{
	//freopen("in.txt", "r", stdin);

	cin >> n >> p;
	FOR (i,0,n)
	{
		scanf("%d %d", &A[i], &B[i]);
	}

	double Min = 0, Max = 1e+18;
	FOR (it,0,128)
	{
		double Mid = (Min + Max)/2;

		double sum = 0;
		bool ok = 1;
		FOR (i,0,n)
		{
			double t = 1.0*(-B[i] + 1.0*A[i]*Mid)/(p);
			if (t > 0)
				sum += t;
		}
		if (sum > Mid)
			ok = 0;
		if (ok)
			Min = Mid;
		else
			Max = Mid;
	}

	if (Min > 1e+17)
		cout << -1 << endl;
	else
		printf("%0.11f\n", Min);

    return 0;
}