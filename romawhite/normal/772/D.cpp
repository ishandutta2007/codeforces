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
const int MAX = 1000007;
const int MAX2 = 7000;
const int BASE = 1000000000;

const int MOD = 1000000007;

int cnt[MAX];

Int S1[MAX];
Int S2[MAX];
Int C[MAX];

int popcnt[64];

Int F[MAX];
Int G[MAX];

Int pw[MAX];

int pw10[MAX];

int main()
{
    //freopen("in.txt", "r", stdin);

    pw10[0] = 1;
    FOR(i,1,6)
    {
    	pw10[i] = pw10[i - 1] * 10;
    }

    pw[0] = 1;
    FOR(i,1,MAX)
    {
    	pw[i] = pw[i - 1] * 2 % MOD;
    }


    FOR(i,1,64)
    {
    	popcnt[i] = popcnt[i / 2] + i % 2;
    }

    int n;
    cin >> n;

    FOR(i,0,n)
    {
    	int x;
    	scanf("%d" , &x);
    	cnt[x] ++;
    }

    RFOR(i,1000000,0)
    {
    	VI a;
    	int ii = i;
    	FOR(it,0,6)
    	{
    		a.push_back(ii % 10);
    		ii /= 10;
    	}

    	FOR(mask,1,64)
    	{
    		int nx = i;
    		bool ok = 1;
    		FOR(j,0,6)
    		{
    			if (mask & (1 << j))
    			{
					if (a[j] == 9)
					{
						ok = 0;
						break;
					}
					nx += pw10[j];
    			}
    		}
    		if (!ok)
    			continue;
    		if (popcnt[mask] % 2 == 1)
    		{
    			S1[i] += S1[nx];
    			S2[i] += S2[nx];
    			C[i] += C[nx];
    		}
    		else
    		{
    			S1[i] -= S1[nx];
    			S2[i] -= S2[nx];
    			C[i] -= C[nx];
    		}
    	}

    	S1[i] += 1LL * cnt[i] * i;
    	S2[i] += 1LL * cnt[i] * i * i;
    	C[i] += cnt[i];

    	S1[i] %= MOD;
    	S2[i] %= MOD;
    	if (S1[i] < 0) S1[i] += MOD;
    	if (S2[i] < 0) S2[i] += MOD;
    }

    FOR(i,0,1000000)
    {
    	if (C[i] == 0)
    		continue;
    	if (C[i] == 1)
    	{
    		F[i] = S2[i];
    		continue;
    	}

    	F[i] = (S1[i] * S1[i] % MOD + S2[i]) * pw[C[i] - 2] % MOD;
    }


    RFOR(i,1000000,0)
    {
    	VI a;
		int ii = i;
		FOR(it,0,6)
		{
			a.push_back(ii % 10);
			ii /= 10;
		}

    	FOR(mask,0,64)
		{
			int nx = i;
			bool ok = 1;
			FOR(j,0,6)
			{
				if (mask & (1 << j))
				{
					if (a[j] == 9)
					{
						ok = 0;
						break;
					}
					nx += pw10[j];
				}
			}
			if (!ok)
				continue;
			if (popcnt[mask] % 2 == 0)
			{
				G[i] += F[nx];
			}
			else
			{
				G[i] -= F[nx];
			}
		}

    	G[i] %= MOD;
    	if (G[i] < 0) G[i] += MOD;
    }

    Int res = 0;
    FOR(i,0,1000000)
    {
    	res ^= (G[i] * i);
    }

    cout << res << endl;

    return 0;
}