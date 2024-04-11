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
const int MAX = 500000;
const int MAX2 = 7000;
const int BASE = 1000000000;

int n, m, s, d;
int A[MAX];
int P[MAX];
int R[MAX];

int main()
{

	scanf("%d %d %d %d", &n, &m, &s, &d);

	FOR (i,0,n)
	{
		scanf("%d", &A[i]);
	}
	sort(A, A+n);

	vector<PII> Q;
	Q.PB(MP(0, A[0]-1));
	FOR (i,1,n)
		if (A[i] != A[i-1]+1)
			Q.PB(MP(A[i-1]+1, A[i]-1));
	Q.PB(MP(A[n-1]+1, m));

	FILL(P, -1);
	int pos = 0, id = -1;
	FOR (i,0,SZ(Q))
	{
		if (Q[i].first <= pos)
		{
			R[i] = 1;
			P[i] = id;
		}
		if (R[i] && Q[i].second-Q[i].first >= s)
		{
			pos = Q[i].second + d;
			id = i;
		}
	}
	if (R[SZ(Q)-1] == 0)
	{
		printf("IMPOSSIBLE\n");
		return 0;
	}
	VI I;
	int x = SZ(Q)-1;
	while (x != -1)
	{
		I.PB(x);
		x = P[x];
	}
	reverse(ALL(I));

	FOR (i,0,SZ(I))
	{
		if (Q[I[i]].first != Q[I[i]].second)
			printf("RUN %d\n", Q[I[i]].second-Q[I[i]].first);
		if (i != SZ(I)-1)
			printf("JUMP %d\n", Q[I[i+1]].first-Q[I[i]].second);
	}






    return 0;
}