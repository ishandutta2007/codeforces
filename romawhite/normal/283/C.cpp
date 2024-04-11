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
using namespace std;
 
#define next fgdfvd
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
typedef unsigned long long UInt;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int MOD = 1000000007;

LL a[305];
int g[305];
bool ok = 1;
bool used[305];
int d[305];
LL t;
bool q[305];
int aa[305];

void dfs(int v){
    used[v] = 1;
    if (g[v] != -1){
        if (used[g[v]])
            ok = 0;
        else{
            d[g[v]] = d[v] + 1;
            dfs(g[v]);
            a[v] += a[g[v]];
        }
    }
}

int dp[100007];

int main()
{
   /* #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    FILL(g , -1);

    int n , m;
    cin >> n >> m >> t;
    FOR(i,0,n)
        cin >> a[i] , aa[i] = a[i];

    FOR(i,0,m){
        int a,b;
        cin >> a >> b;
        --a;--b;
        g[b] = a;
        q[a] = 1;
    }


    FOR(i,0,n)
        if (!q[i])
            dfs(i);

    FOR(i,0,n)
        if (g[i] != -1 && !used[i]){
            cout << 0 << endl;
            return 0;
        }

        FOR(i,0,n)
        t -= d[i] * aa[i];

    if (!ok || t < 0){
        cout << 0 << endl;
        return 0;
    }

    dp[0] = 1;

    FOR(i,0,n)
        FOR(j,a[i],t + 1)
            dp[j] = (dp[j] + dp[j - a[i]]) % MOD;
    cout << dp[t] << endl;

    return 0;
}