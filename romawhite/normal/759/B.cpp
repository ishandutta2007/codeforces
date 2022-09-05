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
const int MAX = 200007;
const int MAX2 = 200007;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

int dp[MAX];

int main()
{
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
    
    int n;
    cin >> n;
    VI A;
    
    dp[0] = 0;
    FOR(i,0,n)
    {
        int t;
        scanf("%d", &t);
        dp[i + 1] = dp[i] + 20;
        int id = lower_bound(ALL(A) , t - 89) - A.begin();
        dp[i + 1] = min(dp[i + 1] , dp[id] + 50);
        id = lower_bound(ALL(A) , t - 1439) - A.begin();
        dp[i + 1] = min(dp[i + 1] , dp[id] + 120);
        printf("%d\n", dp[i + 1] - dp[i]);
        A.push_back(t);
    }
    
    
    return 0;
}