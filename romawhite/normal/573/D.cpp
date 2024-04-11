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
#include <complex>
using namespace std;

#define FOR(i, a, b) for(int i=(a);i<(b);i++)
#define For(i, a, b) for(int i=(a);i<(b);i++)
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
const int MAX = 30007;
const int MAX2 = 200000;
const int BASE = 1000000000;
const int MOD = 1000000007;
const int CNT = 2000;

const Int INF2 = 1LL * INF * INF;

int pos[MAX];
int cnt = 0;
Int dp[MAX];
Int Add[MAX];
Int Add2[MAX];
bool eq[MAX];

int main()
{   
    //freopen("in.txt","r",stdin);
    
    int n , q;
    cin >> n >> q;
    
    vector<pair<Int,int> > A(n);
    vector<pair<Int,int> > B(n);
    
    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        A.push_back(MP(x , i));
    }
    
    FOR(i,0,n)
    {
        int x;
        scanf("%d" , &x);
        B.push_back(MP(x , i));
    }
    
    sort(ALL(A));
    reverse(ALL(A));
    sort(ALL(B));
    reverse(ALL(B));
    
    Int res = 0;
    FOR(i,0,n)
    {
        res += 1LL * A[i].first * B[i].first;
    }
    
    FOR(i,0,n - 1)
    {
        Add[i] = 1LL * (A[i].first - A[i + 1].first) * (B[i].first - B[i + 1].first);
    }
    
    FOR(i,1,n - 1)
    {
        int ps1 = i - 1;
        int ps2 = i + 1;
        //if (ps1 != i - 1 || ps2 != i + 1) continue; 
        Int old = 1LL * A[i].first * B[i].first + 1LL * A[ps1].first * B[ps1].first + 1LL * A[ps2].first * B[ps2].first;
        Int nw1 = 1LL * A[i].first * B[ps1].first + 1LL * A[ps1].first * B[ps2].first + 1LL * A[ps2].first * B[i].first;
        Int nw2 = 1LL * A[i].first * B[ps2].first + 1LL * A[ps1].first * B[i].first + 1LL * A[ps2].first * B[ps1].first;
        //cout << old << ' ' << nw1 << ' ' << nw2 << endl;
        Int nw = max(nw1 , nw2);
        Add2[i] = old - nw;
    }
    
    FOR(tt,0,q)
    {
        int a , b;
        scanf("%d %d" , &a , &b);
        --a;--b;
        cnt = 0;
        FOR(i,0,n)
        {
            if (B[i].second == a || B[i].second == b)
            {
                B[i].second ^= (a ^ b);
            }
            eq[i] = A[i].second == B[i].second;
        }
        
        FOR(i,0,n + 1)
        {
            dp[i] = INF2;
        }
        
        dp[0] = 0;
        
        
        FOR(i,0,n)
        {
            if (!eq[i])
            {
                dp[i + 1] = min(dp[i + 1] , dp[i]);
                if (i + 1 < n && eq[i + 1])
                    dp[i + 2] = min(dp[i + 2] , dp[i] + Add[i]);
                if (i + 1 < n && i - 1 >= 0 && eq[i - 1] && eq[i + 1])
                {
                    dp[i + 2] = min(dp[i + 2] , dp[i - 1] + Add2[i]);
                }
            }
            else
            {
                if (i + 1 < n)
                    dp[i + 2] = min(dp[i + 2] , dp[i] + Add[i]);
                if (i + 2 < n && eq[i + 1] && eq[i + 2])
                {
                    dp[i + 3] = min(dp[i + 3] , dp[i] + Add2[i + 1]);
                }
            }
        }
        
        //cout << res << ' ' << dp[n] << endl;
        
        printf("%I64d\n" , res - dp[n]);
    }
    
}