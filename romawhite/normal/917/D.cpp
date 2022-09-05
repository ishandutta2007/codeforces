

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
#include <bitset>
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
const int MAX = 107;
const int MAXX = 1000000;
const int ADD = 1000000;
const int MOD = 1000000007;
const int CNT = 800;

Int dp[MAX][MAX][MAX];
int n;
VI G[MAX];

int SZ[MAX];

void dfs(int v , int p)
{
    SZ[v] = 1;
    
    dp[v][1][0] = 1;
    
    FOR(i,0,SZ(G[v]))
    {
        int to = G[v][i];
        if (to == p) continue;
        
        dfs(to , v);
        
        RFOR(s1 , SZ[v] + 1 , 0)
            RFOR(k1 , SZ[v] + 1 , 0)
            {
                if (dp[v][s1][k1] == 0) continue;
                FOR(s2,0,SZ[to] + 1)
                    FOR(k2,0,SZ[to] + 1)
                    {
                        dp[v][s1 + s2][k1 + k2] += dp[v][s1][k1] * dp[to][s2][k2];
                        dp[v][s1 + s2][k1 + k2] %= MOD;
                    }
                dp[v][s1][k1] = 0;
            }
                
        SZ[v] += SZ[to];
    }
        
    FOR(i,1,SZ[v] + 1)
        FOR(j,0,SZ[v] + 1)
        {
            dp[v][0][j + 1] += dp[v][i][j] * i;
            dp[v][0][j + 1] %= MOD;
        }
}
    
Int res[MAX];

Int C[MAX][MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("distance.in",  "r", stdin);
    //freopen("distance.out", "w", stdout);
    //freopen("out.txt" , "w" , stdout);
    
    FOR(i,0,MAX)
    {
        C[i][0] = C[i][i] = 1;
        FOR(j,1,i)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    
    cin >> n;
    //n = 100;
    
    FOR(i,0,n - 1)
    {
        int a , b;
        cin >> a >> b;

        
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    
    dfs(0, -1);
    
    FOR(i,0,n)
    {
        res[i] = dp[0][0][i + 1];
    }
    
    res[0] /= n;
    
    FOR(i,1,n)
    {
        FOR(j,0,i - 1)
        {
            res[i] *= n;
            res[i] %= MOD;
        }
    }
    
    /*FOR(i,0,n)
    {
        cout << res[i] << ' ';
    }
    cout << endl;*/
    
    
    FOR(i,0,n)
    {
        FOR(j,0,i)
        {
            res[i] = (res[i] - res[j] * C[n - 1 - j][n - 1 - i] % MOD + MOD) % MOD;
        }
    }
    
    /*FOR(i,0,n)
    {
        cout << res[i] << ' ';
    }
    cout << endl;*/
    
    RFOR(i,n, 0)
    {
        cout << res[i] << ' ';
    }
    cout << endl;
    
    
    
    
    
    
    return 0;
}