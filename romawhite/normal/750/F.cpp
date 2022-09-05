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
typedef pair<int, int> PII;

const int INF = 1000000000;
const int MAX = 100007;
const int MAX2 = 1000000;
const int MAXD = 20;
const int BASE = 1000000007;
const int MOD = 1000000007;

VI A[MAX];
bool ok = 0;
int res = -1;

int cnt = 16;

VI get(int x)
{
    if (SZ(A[x]))
    {
        return A[x];
    }
    cout << "? " << x + 1 << endl;
    int l;
    -- cnt;
    cin >> l;
    FOR(i,0,l)
    {
        int a;
        cin >> a;
        -- a;
        A[x].push_back(a);
    }
    if (l == 2)
        {
            ok = 1;
            res = x;
        }
    return A[x];
}

int main()
{
    //freopen("in.txt" , "r" , stdin);
    
    int t;
    cin >> t;
    FOR(tt,0,t)
    {
        int h;
        cin >> h;
        int n = (1 << h) - 1;
        FOR(i,0,n)
        {
            A[i].clear();
        }
        cnt = 16;
        ok = 0;
        res = -1;
    
    
        if (n <= 16)
        {
            FOR(i,0,n)
                get(i);
            FOR(i,0,n)
            {
                if (SZ(A[i]) == 2)
                {
                    cout << "! " << i + 1 << endl;
                }
            }
            continue;
        }
    
        int v = 0;
        get(v);
        VI C;
        C.push_back(v);
        if (SZ(A[v]) == 3)
        {
            int v1 = v;
            while (SZ(A[v1]) == 3)
            {
                int nxt = -1;
                FOR(i,0,SZ(A[v1]))
                {
                    int to = A[v1][i];
                    if (!SZ(A[to]))
                    {
                        nxt = to;
                        break;
                    }
                }
                v1 = nxt;
                get(v1);
                C.push_back(v1);
            }
        
            v1 = v;
            while (SZ(A[v1]) == 3)
            {
            int nxt = -1;
            FOR(i,0,SZ(A[v1]))
                {
                int to = A[v1][i];
                if (!SZ(A[to]))
                    {
                    nxt = to;
                    break;
                    }
                }
            v1 = nxt;
            get(v1);
                C.insert(C.begin(), v1);
            }
        
        }
    
        v = C[SZ(C) / 2];
        int hh = SZ(C) / 2 + 1;
    
        while (hh < h - 3)
        {
            while (SZ(C) > hh)
                C.pop_back();
            int v1 = v;
            while (SZ(A[v1]) == 3 || SZ(C) == 1)
            {
            int nxt = -1;
            FOR(i,0,SZ(A[v1]))
                {
                int to = A[v1][i];
                if (!SZ(A[to]))
                    {
                    nxt = to;
                    break;
                    }
                }
            v1 = nxt;
            get(v1);
            C.push_back(v1);
            }
            v = C[SZ(C) / 2];
            hh = SZ(C) / 2 + 1;

        }
    
        queue<int> Q;
        FOR(i,0,SZ(A[v]))
        {
            int to = A[v][i];
            if (SZ(A[to]) == 0)
                Q.push(to);
        }
        while (cnt && SZ(Q))
        {
            int vv = Q.front();
            Q.pop();
            get(vv);
            FOR(i,0,SZ(A[vv]))
            {
                int to = A[vv][i];
                if (SZ(A[to]) == 0)
                    Q.push(to);
            }
        }
    
        if (ok)
        {
            cout << "! " << res + 1 << endl;
        }
        else
        {
            cout << "! " << Q.front() + 1 << endl;
        }
            
    
    }
    
    
    return 0;
}