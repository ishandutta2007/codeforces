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
const int MAX = 1100000;
const int ADD = 500107;

struct RMQ
{
	int n;
	int * T;
	int * P;
	RMQ()
	{}
	RMQ(int len)
	{
		n = len;
		T = new int[n * 4];
		P = new int[n * 4];
		FOR (i,0,n*4)
		{
			T[i] = INF;
			P[i] = 0;
		}
	}
	void init(int i, int l, int r)
	{
		if (l == r)
		{
			T[i] = l;
		}
		else
		{
			int m = (l+r)/2;
			init(i*2, l, m);
			init(i*2+1, m+1, r);
			T[i] = min(T[i*2], T[i*2+1]);
		}
	}
	void push(int i, int l, int r)
	{
		if (l != r && P[i] != 0)
		{
			T[i*2] += P[i];
			P[i*2] += P[i];
			T[i*2+1] += P[i];
			P[i*2+1] += P[i];
			P[i] = 0;
		}
	}
	void add(int l, int r, int d, int i, int tl, int tr)
	{
		if (l > r)
			return;
		push(i, tl, tr);
		if (l == tl && r == tr)
		{
			P[i] += d;
			T[i] += d;
		}
		else
		{
			int m = (tl+tr)/2;
			if (r <= m)
				add(l, r, d, i*2, tl, m);
			else
			if (l > m)
				add(l, r, d, i*2+1, m+1, tr);
			else
			{
				add(l, m, d, i*2, tl, m);
				add(m+1, r, d, i*2+1, m+1, tr);
			}
			T[i] = min(T[i*2], T[i*2+1]);
		}
	}
	int get(int l, int r, int i, int tl, int tr)
	{
		push(i, tl, tr);
		if (l == tl && r == tr)
		{
			return T[i];
		}
		int m = (tl+tr)/2;
		if (r <= m)
			return get(l, r, i*2, tl, m);
		if (l > m)
			return get(l, r, i*2+1, m+1, tr);
		return min(get(l, m, i*2, tl, m), get(m+1, r, i*2+1, m+1, tr));
	}
};

int n;
int A[MAX];
int curVal, cntLeft;
map<int, int> Cnt;
RMQ Q;

void add(int x)
{
	Cnt[x] ++;
	if (x <= curVal)
		++ cntLeft;
	int cntLeft2 = cntLeft - Cnt[curVal];
	if (cntLeft2 + curVal-1 >= 0)
	{
		curVal --;
		cntLeft = cntLeft2;
	}

	Q.add(0, x+ADD-1, 1, 1, 0, Q.n-1);
}

int getMax(int x)
{
	return Q.get(x+ADD, Q.n-1, 1, 0, Q.n-1);
}

int main()
{
	//freopen("in.txt", "r", stdin);

	cin >> n;
	FOR (i,0,n)
	{
		scanf("%d", &A[i]);
	}

	Q = RMQ(MAX);
	Q.init(1, 0, Q.n-1);

	curVal = 0, cntLeft = 0;
	FOR (i,0,n)
	{
		add(A[i]);

		int res = getMax(curVal)-ADD;
		printf("%d\n", res);
	}






    return 0;
}