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
const int MAX = 300007;
const int MAX2 = 10000;
const int MAX3 = 100000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int a[MAX];

int dp[2][MAX];

int main()
{   
    //freopen("in.txt","r",stdin);
    
    int n , k;
    cin >> n >> k; 
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }
    sort(a, a + n);
    int len = n / k;
    
    int prev = 0;
    int next = 1;
    dp[prev][0] = 0;
    FOR(i,1,n + 1)
        dp[prev][i] = 2 * INF;
    FOR(it,0,k)
    {
        FOR(i, len * (it + 1) , min((len + 1) * (it + 1) , n) + 1)
            dp[next][i] = 2 * INF;
        FOR(i, len * it , (len + 1) * it + 1)
        {
            if (i >= MAX) break;
            if (dp[prev][i] == 2 * INF) continue;
            if (i + len <= n)
                dp[next][i + len] = min(dp[next][i + len], dp[prev][i] + a[i + len - 1] - a[i]);
            if (i + len + 1 <= n)
                dp[next][i + len + 1] = min(dp[next][i + len + 1], dp[prev][i] + a[i + len] - a[i]);
        }
        /*FOR(i,0,n + 1)
        {
            cout << dp[prev][i] << ' ';
        }
        cout << endl;*/
        swap(prev , next);
    }
    
    cout << dp[prev][n] << endl;
    
}