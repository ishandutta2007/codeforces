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

bool valid[(1 << 24) + 7];
int dp[(1 << 24) + 7];
int s[(1 << 24) + 7];

int main()
{
   /* #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif*/

    int n;
    cin >> n;
    int a[25];
    FOR(i,0,n)
        cin >> a[i];
        //a[i] = rand();

    int k;
    cin >> k;
    int b[3];
    FOR(i,0,k)
        cin >> b[i];

    FOR(mask , 0, 1 << n){
        s[mask] = 0;
        FOR(i,0,n)
            if (mask & (1 << i)){
                s[mask] = s[mask ^ (1 << i)] + a[i];
                if (s[mask] > MOD)
                    s[mask] = MOD;
                break;
            }
        bool q = 1;
        FOR(i,0,k)
            if (s[mask] == b[i])
                q = 0;
        valid[mask] = q;
    }

    if (valid[0]) dp[0] = 1;

    FOR(mask , 1, 1 << n)
        if (valid[mask]){
            FOR(i,0,n)
                if (mask & (1 << i)){
                    dp[mask] += dp[mask ^ (1 << i)];
                    if (dp[mask] >= MOD) dp[mask] -= MOD;
                }
        }
    
    cout << dp[(1 << n) - 1] << endl;

    return 0;
}