//#pragma comment(linker,"/STACK:16777216") /*16Mb*/
//#pragma comment(linker,"/STACK:33554432") /*32Mb*/
#include<sstream>
#include<iostream>
#include<numeric>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include <time.h>
#include<cmath>
#include<memory>
#include<memory.h>
#include<string>
#include<vector>
#include<cctype>
#include<list>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;

typedef unsigned long long      ULL;
typedef long long               LL;

#define PB                      push_back
#define MP                      make_pair
#define X                       first
#define Y                       second
#define FOR(i, a, b)            for(int i = (a); i < (b); ++i)
#define RFOR(i, a, b)           for(int i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b)             memset(a, b, sizeof(a))
#define SZ(a)                   int((a).size())
#define ALL(a)                  (a).begin(), (a).end()
#define RALL(a)                 (a).rbegin(), (a).rend()
#define INF                     (1000000000)
#define FILL                    CLEAR

const int MOD = 1000000007;

LL dp[305][305];
LL a[305][305];

int main()
{
    FOR(i,0,305)
        FOR(j,0,305)
            a[i][j] = dp[i][j] = 1ll * INF * INF;

    int n,m,K;
    cin >> n>> m >> K;
    FOR(i,0,m){
        int l,r,c;
        cin >> l >> r >> c;
        FOR(j,l,r + 1)
            a[j][r] = min(a[j][r] , 1ll * c);
    }
    
    
    dp[0][0] = 0;

    FOR(i,1,n + 1)
        FOR(j,0,i + 1){
            dp[i][j] = dp[i - 1][j];
            FOR(t,0,i)
                if (i - t <= j)
                    dp[i][j] = min(dp[i][j] , dp[t][j - (i - t)] + a[t + 1][i]);
    }
    LL res = 1LL * INF * INF;
    FOR(i,K,n + 1){
        res = min(res , dp[n][i]);
    }


    if (res == 1LL * INF * INF)
        res = -1;
    cout << res << endl;
    return 0;
};