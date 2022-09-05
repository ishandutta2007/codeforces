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
#include <bitset>
#include <assert.h>
#include <complex.h>
using namespace std;

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
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
typedef pair <double, double> PDD;

const int BASE = 1000;
const double EPS = 1e-7;
const int MAX = 57;
const int INF = 1000000000;


Int dp[MAX][5007][MAX];


int main()
{
    //freopen("in.txt", "r", stdin);
    
    
    FOR(i,0,MAX)
        FOR(j,0,5007)
            FOR(k,0,MAX)
                dp[i][j][k] = 1LL * INF * INF;
    
    dp[0][0][0] = 0;
    
    int n;
    cin >> n;
    vector<PII> A(n);
    
    FOR(i,0,n)
    {
        cin >> A[i].first;
    }
    FOR(i,0,n)
    {
        cin >> A[i].second;
    }
    
    sort(ALL(A));
    reverse(ALL(A));
    
    int pos = 0;
    
    while (pos < n)
    {
        int add = 1;
        while (pos + add < n && A[pos + add].first == A[pos].first) ++ add;
        
        
        FOR(i,0,5001)
        {
            FOR(j,0,pos + 1)
            {
                if (dp[pos][i][j] == 1LL * INF * INF) continue;
                
                int sum = 0;
                
                FOR(k,0,add + 1)
                {
                    if (j >= add - k)
                    {
                        dp[pos + add][i + sum][j - (add - k) + k] = min(dp[pos + add][i + sum][j - (add - k) + k] , dp[pos][i][j] + (Int)A[pos].first * k);
                    }
                    
                    if (k < add)
                        sum += A[pos + k].second;
                }
                
            }
        }
        
        
        
        pos = pos + add;
    }
    
    
    Int res = 1LL * INF * INF;
    
    FOR(i,1,5001)
        FOR(j,0,n + 1)
        {
            if (dp[n][i][j] == 1LL * INF * INF) continue;
            res = min(res , (dp[n][i][j] * 1000 + i - 1) / i);
            
        }
    
    
    cout << res << endl;
    
    
    
    return 0;
}