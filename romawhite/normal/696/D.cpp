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
const int MAXV = 1200;
const int MAXE = 100000;
const int ADD = 1000000;
const int MOD = 1000000007;

string s[MAX];

vector<string> S;

int a[MAX];

int cost[MAX];

bool isSuffix(string & a , string & b)
{
	if (SZ(a) < SZ(b)) return 0;
	FOR(i,0,SZ(b))
	{
		if (a[SZ(a) - SZ(b) + i] != b[i])
			return 0;
	}
	return 1;
}

bool G[MAX][MAX];

vector<vector<Int> > mult(vector<vector<Int> > A , vector<vector<Int> > B)
{
	int n = SZ(A);
	vector<vector<Int> > C(n , vector<Int>(n , -1LL * INF * INF));
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			FOR(k,0,n)
			{
				if (A[i][k] < 0) continue;
				if (B[k][j] < 0) continue;

				C[i][j] = max(C[i][j] , A[i][k] + B[k][j]);
			}
		}
	}
	return C;
}

vector<vector<Int> > bpow(Int k)
{
	int n = SZ(S);
	vector<vector<Int> > res(n , vector<Int>(n , 0));

	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if (i != j)
			{
				res[i][j] = -1LL * INF * INF;
			}
		}
	}

	vector<vector<Int> > A(n , vector<Int>(n , -1LL * INF * INF));
	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			if (!G[i][j]) continue;
			A[i][j] = cost[j];
		}
	}

	/*FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			cout << A[i][j] << ' ';
		}
		cout << endl;
	}

	FOR(i,0,n)
	{
		FOR(j,0,n)
		{
			cout << res[i][j] << ' ';
		}
		cout << endl;
	}
	cout << endl;*/

	while (k)
	{
		if (k & 1)
		{
			res = mult(res , A);
		}
		A = mult(A , A);
		k /= 2;

		/*FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				cout << A[i][j] << ' ';
			}
			cout << endl;
		}

		FOR(i,0,n)
		{
			FOR(j,0,n)
			{
				cout << res[i][j] << ' ';
			}
			cout << endl;
		}
		cout << endl;*/

	}
	return res;


}

int main()
{
    //freopen("in.txt",  "r", stdin);

	int n;
	Int l;
	cin >> n >> l;

	FOR(i,0,n)
	{
		cin >> a[i];
	}

	S.push_back("");

	FOR(i,0,n)
	{

		cin >> s[i];

		string t = "";
		FOR(j,0,SZ(s[i]))
		{
			t += s[i][j];
			S.push_back(t);
		}

	}

	sort(ALL(S));
	S.resize(unique(ALL(S)) - S.begin());


	FOR(i,0,SZ(S))
	{
		FOR(j,0,n)
		{
			if (isSuffix(S[i] , s[j]))
			{
				cost[i] += a[j];
			}
		}

		FOR(j,0,26)
		{
			string t = S[i];
			t += (char)('a' + j);
			FOR(k,0,SZ(S))
			{
				if (isSuffix(t , S[k]))
				{
					G[i][k] = 1;
				}
			}

		}

	}


	vector<vector<Int> > A = bpow(l);

	Int res = 0;
	FOR(i,0,SZ(S))
	{
		res = max(res , A[0][i]);
	}

	cout << res << endl;

    return 0;
}