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
const int MAX = 2000000;
const int MAX2 = 3500000;
const int BASE = 1000000000;
const int CNT = 20000;

struct RMQ
{
	int n;
	int T[MAX * 4];
	RMQ(){}
	void init(int len)
	{
		n = len;
		FOR (i,0,n*4)
			T[i] = 0;
	}
	void add(int j, int d, int i, int l, int r)
	{
		if (l == r)
			T[i] += d;
		else
		{
			int m = (l+r)/2;
			if (j <= m)
				add(j, d, i*2, l, m);
			else
				add(j, d, i*2+1, m+1, r);
			T[i] = T[i*2] + T[i*2+1];
		}
	}
	int get(int l, int r, int i, int tl, int tr)
	{
		if (l == tl && r == tr)
			return T[i];
		int m = (tl+tr)/2;
		if (r <= m)
			return get(l, r, i*2, tl, m);
		if (l > m)
			return get(l, r, i*2+1, m+1, tr);
		int a = get(l, m, i*2, tl, m);
		int b = get(m+1, r, i*2+1, m+1, tr);
		return a + b;
	}

};

struct node
{
	int id;
	int a, t, x;
	node(){}
};

int n;
node Q[MAX];
VI I[MAX];
int R[MAX];
VI X;
VI T;
RMQ D;

int main()
{
    #ifndef ONLINE_JUDGE
      freopen("in.txt", "r", stdin);
    #endif

    cin >> n;
    FOR (i,0,n)
    {
    	int a, t, x;
    	scanf("%d %d %d", &a, &t, &x);
    	Q[i].a = a;
    	Q[i].t = t;
    	Q[i].x = x;
    	X.PB(x);
    	T.PB(t);
    }
    sort(ALL(X));
    sort(ALL(T));
    FOR (i,0,n)
    	Q[i].x = lower_bound(ALL(X), Q[i].x) - X.begin();
    FOR (i,0,n)
    	Q[i].t = lower_bound(ALL(T), Q[i].t) - T.begin();

    FOR (i,0,n)
    	I[Q[i].x].PB(i);
    D.init(SZ(T));
    FOR (i,0,SZ(X))
    {
    	FOR (j,0,SZ(I[i]))
		{
    		int id = I[i][j];
    		if (Q[id].a == 1)
    		{
    			D.add(Q[id].t, 1, 1, 0, D.n-1);
    		}
    		else
    		if (Q[id].a == 2)
    		{
    			D.add(Q[id].t, -1, 1, 0, D.n-1);
    		}
    		else
    		{
    			int sum = D.get(0, Q[id].t, 1, 0, D.n-1);
    			R[id] = sum;
    		}
		}
    	FOR (j,0,SZ(I[i]))
		{
    		int id = I[i][j];
    		if (Q[id].a == 1)
    		{
    			D.add(Q[id].t, -1, 1, 0, D.n-1);
    		}
    		else
    		if (Q[id].a == 2)
    		{
    			D.add(Q[id].t, 1, 1, 0, D.n-1);
    		}
		}
    }
    FOR (i,0,n)
    	if (Q[i].a == 3)
    		printf("%d\n", R[i]);







    return 0;
}