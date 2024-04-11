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
#include <complex.h>


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
const int MAX = 300007;
const int MAXD = 20;
const int MOD = 1000000007;

const int BASE = 1000*1000*1000;

VI read(string s)
{
    VI a;
    for (int i=(int)s.length(); i>0; i-=9)
        if (i < 9)
            a.push_back (atoi (s.substr (0, i).c_str()));
        else
            a.push_back (atoi (s.substr (i-9, 9).c_str()));
    return a;
}

int div(VI & a, int b)
{
    if (b == 1)
    {
        return 0;
    }
        
    
    if (b == BASE)
    {
        int carry = a[0];
        if (SZ(a) > 0)
        {
            a.erase(a.begin());
        }
        return carry;
    }
    
    int carry = 0;
    for (int i=(int)a.size()-1; i>=0; --i) {
        long long cur = a[i] + carry * 1ll * BASE;
        a[i] = int (cur / b);
        carry = int (cur % b);
    }
    while (a.size() > 1 && a.back() == 0)
        a.pop_back();
    return carry;
}

VI A[MAX];
VI C;
int a[MAX];
VI B;

int dp[2][MAX];
int b[MAX];


int main()
{
    //freopen("in.txt" , "r" , stdin);
    //freopen("out.txt" , "w" , stdout);
    
    int n;
    cin >> n;
    FOR(i,1,n)
    {
        scanf("%d", &a[i]);
    }

    
    
    FOR(i,0,n)
    {
        scanf("%d", &b[i]);
    }
    
    string s;
    cin >> s;
    VI num = read(s);
    FOR(i,1,n)
    {
        B.push_back(div(num , a[i]));
    }
    if (SZ(num) > 1)
    {
        cout << 0 << endl;
        return 0;
    }
    B.push_back(num[0]);
    
    int sz = b[0] + 1;
    int prev = 0;
    int next = 1;
    FOR(i,0,sz)
    {
        dp[prev][i] = 1;
    }
    
    FOR(i,0,n - 1)
    {
        VI t;
        int idd = 0;
        for(int j = B[i]; j < sz; j += a[i + 1])
        {
            dp[next][idd ++] = dp[prev][j];
        }
        if (idd == 0)
        {
            cout << 0 << endl;
            return 0;
        }
        sz = idd;
        swap(prev , next);
        int x = b[i + 1];
        
        FOR(j,0,sz + b[i + 1])
        {
            dp[next][j] = 0;
            if (j) dp[next][j] = dp[next][j - 1];
            if (j < sz)
            {
                dp[next][j] += dp[prev][j];
                if (dp[next][j] >= MOD) dp[next][j] -= MOD;
            }
            if (j - x - 1 >= 0)
            {
                dp[next][j] += MOD - dp[prev][j - x - 1];
                if (dp[next][j] >= MOD) dp[next][j] -= MOD;
            }
        }
        swap(prev , next);
        sz += x;
        
    }
    
    if (B[n - 1] >= sz)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << dp[prev][B[n - 1]] << endl;
    }
        
    
    
    return 0;
}