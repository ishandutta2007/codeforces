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
const int MAX = 100007;
const int MAX2 = 10007;
const int BASE = 1000000000;
const int MOD = 1000000007;

struct Matrix
{
    vector<vector<int> > a;

    Matrix(int n)
    {
        vector<int> b(n,0);
        a.resize(n);
        FOR(i,0,n)
        {
            a[i] = b;
        }
    }

    void E()
    {
        FOR(i,0,a.size())
        {
            FOR(j,0,a.size())
            {
                a[i][j] = 0;
            }
        }
        FOR(i,0,a.size())
        {
            a[i][i] = 1;
        }
    }
};

Matrix mult(Matrix & a, Matrix & b)
{
    int n = a.a.size();
    Matrix c(n);

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            FOR(k,0,n)
            {
                c.a[i][j] += (1LL * a.a[i][k] * b.a[k][j]) % MOD;
                c.a[i][j] %= MOD;
            }
        }
    }
    return c;
}

Matrix bpow(Matrix a, int k)
{
    Matrix res(a.a.size());
    res.E();
    while (k)
    {
        if (k & 1)
        {
            res = mult(res, a);
        }
        a = mult(a, a);
        k /= 2;
    }
    return res;
}

int dp[8][150];

int main()
{
    #ifndef ONLINE_JUDGE
  // freopen("in.txt", "r", stdin);
    #endif

    dp[0][0] = 1;

    FOR(i,0,7)
    {
        int w;
        cin >> w;

        int n = 1 << (i + 1);
        Matrix a(n);

        FOR(mask1 ,0,1 << (i + 1))
            FOR(mask2, 0, 1 << i)
                FOR(mask3, 0, 1 << (i + 1))
                {
                    bool ok = 1;

                    if (i == 0 && mask1 == 1 && mask3 == 1) ok = 0;

                    if ((mask1 & 1) && (mask3 & 1) && (mask2 & 1))
                    {
                        ok = 0;
                    }
                    FOR(k,1,i)
                    {
                        if ((mask1 & (1 << k)) && (mask3 & (1 << k)) && (mask2 & (1 << (k - 1))) && (mask2 & (1 << k)))
                        {
                            ok = 0;
                        }
                    }
                    if ((mask1 & (1 << (i))) && (mask3 & (1 << (i))) && (mask2 & (1 << (i - 1))))
                    {
                        ok = 0;
                    }

                    a.a[mask1][mask3]+=ok;
                }

        /*if (i < 2)
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                cout << a.a[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;*/

        a = bpow(a, w);

      /*  if (i < 2)
        FOR(i,0,n)
        {
            FOR(j,0,n)
            {
                cout << a.a[i][j] << ' ';
            }
            cout << endl;
        }
        cout << endl;*/

        FOR(mmm,0,1 << i)
        {
            int mask = mmm ^ (1 << i);

            FOR(nx , 0 , 1 << (i + 1))
            {
               /* if (dp[i][mmm] && i < 2)
                {
                    cout << "x " << mask << ' ' << nx << ' ' << a.a[mask][nx] << ' ' << dp[i][mmm] << endl;
                }*/
                dp[i + 1][nx] += 1LL * a.a[mask][nx] * dp[i][mmm] % MOD;
                dp[i + 1][nx] %= MOD;
            }
        }

        /*FOR(j,0,1 << (i + 1))
        {
            cout << dp[i + 1][j] << ' ';
        }
        cout << endl;*/

    }

    cout << dp[7][(1 << 7) - 1] << endl;

    return 0;
}