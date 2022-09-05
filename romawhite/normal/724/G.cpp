#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:64000000")
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
const int MAX = 100007;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

vector<pair<int, Int> > G[MAX];
bool U[MAX];

vector<Int> A;
vector<Int> C;

Int B[MAX];

Int pw[MAX];

void AddC(Int x)
{
	FOR(i,0,SZ(C))
	{
		if ((x ^ C[i]) < x)
			x ^= C[i];
	}
	if (x != 0)
	{
		C.push_back(x);
		sort(ALL(C));
		reverse(ALL(C));
	}
}

void dfs(int v, Int val)
{
	U[v] = 1;
	A.push_back(val);
	B[v] = val;
	FOR(i,0,SZ(G[v]))
	{
		int to = G[v][i].first;
		if (U[to])
		{
			AddC(val ^ B[to] ^ G[v][i].second);
		}
		else
		{
			dfs(to, val ^ G[v][i].second);
		}
	}
}

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);

	pw[0] = 1;
	FOR(i,1,MAX)
	{
		pw[i] = pw[i - 1] * 2 % MOD;
	}

    int n , m;
    cin >> n >> m;
    FOR(i,0,m)
    {
    	int u , v;
    	Int t;
    	scanf("%d%d%I64d" , &u , &v , &t);
    	-- u; -- v;
    	G[u].push_back(MP(v , t));
    	G[v].push_back(MP(u , t));
    }

    Int res = 0;

    FOR(i,0,n)
    {
    	if (!U[i])
    	{
    		A.clear();
    		C.clear();
    		dfs(i, 0);



    		FOR(bit,0,62)
    		{
    			Int c1 = 0;
    			Int c0 = 0;
    			FOR(j,0,SZ(C))
    			{
    				if (C[j] & (1LL << bit))
    					c1 ++;
    				else
    					c0 ++;
    			}
    			Int a1 = 0;
    			Int a0 = 0;
    			FOR(j,0,SZ(A))
    			{
    				if (A[j] & (1LL << bit))
    					a1 ++;
    				else
    					a0 ++;
    			}

    			if (c1 == 0)
    			{
    				res += pw[c0] * a1 % MOD * a0 % MOD * pw[bit] % MOD;
    				res %= MOD;
    			}
    			else
    			{
    				res += pw[c0 + c1 - 1] * (1LL * SZ(A) * (SZ(A) - 1) / 2 % MOD) % MOD * pw[bit] % MOD;
    				res %= MOD;
    			}

    		}

    	}
    }

    cout << res << endl;

    return 0;
}