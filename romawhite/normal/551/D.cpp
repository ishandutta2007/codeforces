#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/stack:32777216")
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
const int MAX = 100007;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

Int bpow(Int a, Int k, int m)
{
    Int res = 1;
    while (k)
    {
        if (k & 1)
        {
            res *= a;
            res %= m;
        }
        a *= a;
        a %= m;
        k /= 2;
    }
    return res;
}

vector<vector<Int> > mult(vector<vector<Int> > a, vector<vector<Int> > b, int m)
{
    vector<vector<Int> > c(2, vector<Int> (2,0));
    FOR(i,0,2)
        FOR(j,0,2)
            FOR(k,0,2)
            {
                c[i][j] += a[i][k] * b[k][j] % m;
                c[i][j] %= m;
            }
    return c;
}

vector<vector<Int> > mpow(vector<vector<Int> > a, Int k, int m)
{
    vector<vector<Int> > res(2, vector<Int>(2,0));
    res[0][0] = res[1][1] = 1;
    while (k)
    {
        if (k & 1)
        {
            res = mult(res , a, m);
        }
        a = mult(a , a, m);
        k /= 2;
    }
    return res;
}

int main()
{
    //freopen("in.txt" , "r", stdin);

    Int n,k,l,m;
    cin >> n >> k >> l >> m;
    Int kk = k;
    FOR(i,0,l) kk /= 2;
    if (kk > 0)
    {
        cout << 0 << endl;
        return 0;
    }

    vector<vector<Int> > a(2, vector<Int>(2,0));
    a[0][0] = a[0][1] = a[1][0] = 1;

    a = mpow(a, n + 1, m);

    Int fib = a[0][0];

    Int res = 1;
    int c0 = 0;
    int c1 = 0;
    FOR(i,0,l)
    {
        if (k & (1LL << i))
        {
            ++c1;
        }
        else
        {
            ++c0;
        }
    }
    res = bpow(fib, c0, m);
    Int d = bpow(2, n, m);
    d -= fib;
    d += m;
    d %= m;
    res *= bpow(d, c1, m);
    res %= m;

    //cout << fib << endl;
    cout << res << endl;

    return 0;
}