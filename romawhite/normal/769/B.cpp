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
const int MAX = 1024;
const int MAX2 = 7000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int n;
int A[MAX];

int main()
{

	cin >> n;
	VI P;
	VI Z;
	FOR (i,0,n)
	{
		cin >> A[i];
		if (A[i] > 0)
			P.PB(i);
		else
			Z.PB(i);
	}

	if (A[0] == 0)
	{
		cout << -1 << endl;
		return 0;
	}

	vector<PII> R;
	FOR (i,1,SZ(P))
	{
		-- A[P[i-1]];
		R.PB(MP(P[i-1], P[i]));
	}

	FOR (i,0,SZ(Z))
	{
		int id = -1;
		FOR (j,0,SZ(P))
			if (A[P[j]] > 0)
				id = P[j];
		if (id == -1)
		{
			cout << -1 << endl;
			return 0;
		}
		-- A[id];
		R.PB(MP(id, Z[i]));
	}

	cout << SZ(R) << endl;
	FOR (i,0,SZ(R))
		printf("%d %d\n", R[i].first+1, R[i].second+1);



	return 0;
}