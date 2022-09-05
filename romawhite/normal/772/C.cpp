#define _CRT_SECURE_NO_WARNINGS
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
const int MAX = 200007;
const int MAX2 = 7777;
const int MAXE = 100000;
const int ADD = 1000000;
const int CNT = 800;

const int MOD = 1000000007;

VI A[MAX];

int gcd(int a , int b)
{
	if (!b) return a;
	return gcd(b , a % b);
}

VI G[MAX];

int dp[MAX];
int p[MAX];

int n , m;

VI P;
int phi(int n)
{
	int r = n;
	FOR(i,0,SZ(P))
	{
		if (n % P[i] == 0)
		{
			r /= P[i];
			r *= P[i] - 1;
		}
	}
	return r;
}

Int bpow(Int a, int k, int mod)
{
	Int res = 1 % mod;
	while (k)
	{
		if (k & 1)
		{
			res *= a;
			res %= mod;
		}
		a *= a;
		a %= mod;
		k /= 2;
	}
	return res;
}

int go(int a , int b, int m)
{
	int g = gcd(a , m);
	a /= g;
	b /= g;
	m /= g;

	int ph = phi(m);

	Int x = 1LL * b * bpow(a , ph - 1 , m) % m;

	return x;
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);


	cin >> n >> m;

	int mm = m;
	FOR(i,2,MAX)
	{
		if (mm % i == 0)
		{
			P.push_back(i);
			while (mm % i == 0) mm /= i;
		}
	}

	set<int> S;
	FOR(i,0,n)
	{
		int x;
		scanf("%d" , &x);
		S.insert(x);
	}


	VI B;

	FOR(i,1,m + 1)
	{
		if (m % i == 0)
		{
			B.push_back(i);
		}
	}

	FOR(i,0,m)
	{
		if (S.find(i) != S.end()) continue;

		int g = gcd(i, m);

		int id = lower_bound(ALL(B) , g) - B.begin();
		A[id].push_back(i);
	}

	int cnt = SZ(B);

	FOR(i,0,SZ(B))
	{
		FOR(j,i + 1 , SZ(B))
		{
			if (B[j] % B[i] == 0)
			{
				G[i].push_back(j);
			}
		}
	}

	RFOR(i,SZ(B), 0)
	{
		p[i] = -1;
		FOR(j,0,SZ(G[i]))
		{
			int to = G[i][j];
			if (dp[to] > dp[i])
			{
				dp[i] = dp[to];
				p[i] = to;
			}
		}
		dp[i] += SZ(A[i]);
	}

	int cur = 1;
	int v = 0;

	VI res;

	while (v != -1)
	{
		FOR(i,0,SZ(A[v]))
		{
			res.push_back(go(cur , A[v][i] , m));
			cur = A[v][i];
		}
		v = p[v];
	}

	Int c = 1;

	cout << SZ(res) << endl;
	FOR(i,0,SZ(res))
	{
		cout << res[i] << ' ';
		/*c *= res[i];
		c %= m;
		cout << c << ' ';*/
	}
	cout << endl;



    return 0;
}