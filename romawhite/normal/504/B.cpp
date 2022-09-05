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
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 200007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

struct Fenwick
{
    int t[MAX];


    Fenwick()
    {
        FILL(t, 0);
    }

    int sum (int r)
    {
        int result = 0;
        for (; r >= 0; r = (r & (r+1)) - 1)
            result += t[r];
        return result;
    }

    void inc (int i, int delta)
    {
        for (; i < MAX; i = (i | (i+1)))
            t[i] += delta;
    }

    int fnd(int x)
    {
        int L = 0;
        int R = MAX - 1;
        while (R - L > 1)
        {
            int M = (L + R) / 2;
            if (M - sum(M) >= x)
            {
                R = M;
            }
            else
            {
                L = M;
            }
        }
        if (L - sum(L) >= x)
        {
            R = L;
        }
        return R;
    }
};

Fenwick fa,fb,fc;

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        //freopen("out.txt" , "w" , stdout);
    #endif

    int n;
    cin >> n;
    vector<int> a(n), b(n);

    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }
    FOR(i,0,n)
    {
        scanf("%d" , &b[i]);
    }

    vector<int> A;
    vector<int> B;

    FOR(i,0,n)
    {
        A.push_back(a[i] - fa.sum(a[i]));
        fa.inc(a[i] , 1);
    }
    FOR(i,0,n)
    {
        B.push_back(b[i] - fb.sum(b[i]));
        fb.inc(b[i] , 1);
    }

    vector<int> C(n);

    int md = 1;
    int ad = 0;
    RFOR(i,n,0)
    {
        C[i] = A[i] + B[i] + ad;
        ad = 0;
        if (C[i] >= md)
        {
            ad = 1;
            C[i] -= md;
        }
        md++;
    }

    vector<int> c;
    FOR(i,0,C.size())
    {
        c.push_back(fc.fnd(C[i]));
        fc.inc(c[i] , 1);
    }

    FOR(i,0,n)
    {
        printf("%d " , c[i]);
    }



    return 0;
}