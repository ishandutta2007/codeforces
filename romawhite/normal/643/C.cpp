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
const int MAX = 200007;
const int MAX2 = 52;
const int BASE = 1000000000;

struct line
{
	double k, b;
	line(){}
	double getX(line t)
	{
		return (t.b - b) / (k - t.k);
	}
};

int n, k;
int A[MAX];
double S[MAX];
double T[MAX];
double R[MAX2][MAX];
//double D[MAX][MAX2];

bool check(line a, line b, line c)
{
	double x1 = a.getX(b);
	double x2 = b.getX(c);
	if (x2 < x1)
		return 1;
	return 0;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif


    //while (1)
   // {

    cin >> n >> k;
    	//n = rand() % 200 + 1;
    	//k = rand() % min(n, 50) + 1;
    FOR (i,1,n+1)
    {
    	scanf("%d", &A[i]);
    	//A[i] = rand() % 100 + 100000;
    }

    FOR (i,1,n+1)
    {
    	S[i] = S[i-1] + A[i];
    	T[i] = T[i-1] + 1.0/A[i];
    }

    /*FOR (i,0,k+1)
    	FOR (j,0,n+1)
    		R[i][j] = 0;*/
    R[1][0] = -(1e+47);
    FOR (i,2,k+1)
    {
    	vector<line> Q;
    	vector<double> X;
    	X.PB(-(1e+47));
    	FOR (j,0,n+1)
    	{
    		if (j >= i)
    		{
    			double x = T[j];
    			int pos = upper_bound(ALL(X), x) - X.begin() - 1;
    			double y = Q[pos].k * x + Q[pos].b;
    			R[i][j] = y;
    		}
    		else
    		{
    			//cout << i << ' ' << j << endl;
    			R[i][j] = -(1e+47);
    		}
    		// add
    		line t;
    		t.k = S[j];
    		t.b = -T[j] * S[j] + R[i-1][j];
    		while (SZ(Q) >= 2 && check(Q[SZ(Q)-2], Q[SZ(Q)-1], t))
    		{
    			Q.pop_back();
    			X.pop_back();
    		}
    		Q.PB(t);
    		if (SZ(Q) > 1)
    			X.PB(Q[SZ(Q)-2].getX(t));
    	}
    }

    double res = 0;
    FOR (i,1,n+1)
    	res += S[i] / A[i];

    //cout << res << ' ' << R[k][n] << endl;
    //cout <<< k << ' ' << n << endl;
    res -= R[k][n];

    printf("%0.11f\n", res);



/*
    FOR (i,1,n+2)
    	FOR (j,0,k+1)
    		D[i][j] = INF;
    D[1][0] = 0;
    FOR (i,1,n+1)
    	FOR (j,0,k)
    	{
    		double sum = 0, add = 0;
    		FOR (t,i,n+1)
			{
				sum += A[t];
				add += sum / A[t];

				D[t+1][j+1] = min(D[t+1][j+1], D[i][j] + add);
			}

    	}
    double res2 = D[n+1][k];
    double d = abs(res2 - res);
    cout << res << ' ' << res2 << endl;
    if (d > 1e-4)
    {
    	printf("%0.11f\n", d);
    	return 0;
    }

    }

*/




    return 0;
}