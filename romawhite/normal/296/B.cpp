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
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1<<30;
const int MAX = 1<<17;
const int MOD = 1000000007;

int dp[100007][4];

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    int n;
    string s1,s2;
    cin >> n >> s1 >> s2;

    dp[0][0] = 1;
    FOR(l,0,n)
        FOR(mask , 0 , 4)
            FOR(i,0,10)
                if (s1[l] - '0' == i || s1[l] == '?')
                    FOR(j,0,10)
                        if (s2[l] - '0' == j || s2[l] == '?'){
                            if (i > j){
                                dp[l + 1][mask | 1] += dp[l][mask];
                                dp[l + 1][mask | 1] %= MOD;
                            }
                            if (i < j){
                                dp[l + 1][mask | 2] += dp[l][mask];
                                dp[l + 1][mask | 2] %= MOD;
                            }
                            if (i == j){
                                dp[l + 1][mask] += dp[l][mask];
                                dp[l + 1][mask] %= MOD;
                            }
                        }

    cout << dp[n][3] << endl;
    return 0;
}