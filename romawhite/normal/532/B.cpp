#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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

typedef long long Int;
typedef unsigned long long UInt;
typedef vector<int> VI;
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 2000;
const int BASE = 1000000000;

int n;
int a[MAX];
vector<int> g[MAX];

Int dp[MAX][2];
Int d[2];

Int res = 0;

void dfs(int v)
{
    dp[v][0] = 0;
    dp[v][1] = -INF;
    FOR(i,0,g[v].size())
    {
        dfs(g[v][i]);
        int to = g[v][i];
        d[0] = max(dp[v][0] + dp[to][0] , dp[v][1] + dp[to][1]);
        d[1] = max(dp[v][0] + dp[to][1] , dp[v][1] + dp[to][0]);
        dp[v][0] = d[0];
        dp[v][1] = d[1];
    }

    dp[v][1] = max(dp[v][1] , dp[v][0] + a[v]);

    //cout << v << ' ' << dp[v][0] << ' ' << dp[v][1] << endl;

    res = max(res , dp[v][0]);
    res = max(res , dp[v][1]);
}

int main()
{
    //freopen("in.txt","r",stdin);

    cin >> n;

    FOR(i,0,n)
    {
        int p;
        scanf("%d%d" , &p, &a[i]);
        if (p != -1)
        {
            --p;
            g[p].push_back(i);
        }
    }

    dfs(0);

    cout << res << endl;

    return 0;
}