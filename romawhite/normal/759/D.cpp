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
#include <assert.h>
#include <time.h>


#include <fstream>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
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
typedef pair<Int, Int> PII;

const int INF = 1000000000;
const int MAX = 5007;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int dp[MAX][MAX];
int nxt[MAX][27];
int C[MAX][MAX];

int main()
{
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
    
    FOR(i,0,MAX)
    {
        C[i][0] = C[i][i] = 1;
        FOR(j,1,i)
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % MOD;
    }
    
    int n;
    cin >> n;
    //n = 5000;
    
    string s;
    cin >> s;
    //s = "";
    //FOR(i,0,n)
    //    s += (char)('a' + rand() % 26);
    
    FOR(j,0,26)
    {
        nxt[n][j] = n;
    }
    
    RFOR(i,n,0)
    {
        FOR(j,0,26)
        {
            nxt[i][j] = nxt[i + 1][j];
        }
        nxt[i][s[i] - 'a'] = i;
    }   
    
    dp[0][0] = 1;
    
    FOR(i,0,n)
    {
        int del = -1;
        if (i) del = s[i - 1] - 'a';
        FOR(k,0,26)
        {
            if (del == k) continue;
            int pos = nxt[i][k] + 1;
            if (pos == n + 1) continue;
            FOR(j,0,i + 1)
            {
                if (dp[i][j] == 0) continue;
                dp[pos][j + 1] += dp[i][j];
                if (dp[pos][j + 1] >= MOD) dp[pos][j + 1] -= MOD;
            }
        }
    }
    
    Int res = 0;
    
    FOR(len , 1 , n + 1)
    {
        int sum = 0;
        FOR(i,0,n + 1)
        {
            sum += dp[i][len];
            sum %= MOD;
        }
        
        res += 1LL * sum * C[n - 1][len - 1] % MOD;
        res %= MOD;
    }
    
    cout << res << endl;
    
    
    
    return 0;
}