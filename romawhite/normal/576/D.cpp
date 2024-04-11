#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <string>
#include <vector>
#include <map>
#include <list>
#include <iterator>
#include <set>
#include <queue>
#include <iostream>
#include <sstream>
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
const int MAX = 157;
const int MAX2 = 2000;
const int BASE = 1000000000;
const int MOD = 1000000007;

int n , m;

unsigned A[MAX][MAX / 32 + 7];
unsigned B[MAX / 32 + 7][MAX];

vector<vector<char> > mult(vector<vector<char> > a , vector<vector<char> > b)
{
    FILL(A , 0);
    FILL(B , 0);
    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if (a[i][j])
            {
                A[i][j / 32] |= (1 << (j % 32));
            }
        }
    }

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            if (b[i][j])
            {
                B[i / 32][j] |= (1 << (i % 32));
            }
        }
    }

    vector<vector<char> > c(n , vector<char> (n, 0));

    FOR(i,0,n)
    {
        FOR(j,0,n)
        {
            FOR(t,0,n / 32 + 1)
            {
                if (A[i][t] & B[t][j])
                {
                    c[i][j] = 1;
                    break;
                }
            }
        }
    }
    return c;
}

vector<pair<int, pair<int,int> > > E;

vector<char> step(vector<char> a , int cnt)
{
    vector<char> b(n , 0);
    FOR(i,0,cnt)
    {
        if (a[E[i].second.first])
        {
            b[E[i].second.second] = 1;
        }
    }
    return b;
}

vector<vector<char> > bpow(vector<vector<char> > a , int k)
{
    vector<vector<char> > res(n , vector<char>(n,0));
    FOR(i,0,n)
    {
        res[i][i] = 1;
    }
    while (k)
    {
        if (k & 1)
        {
            res = mult(res , a);
        }
        a = mult(a , a);
        k /= 2;
    }
    return res;
}

vector<char> mlt(vector<vector<char> > a , vector<char> b)
{
    vector<char> c(n, 0);
    FOR(i,0,n)
        FOR(j,0,n)
            if (a[i][j] && b[j])
            {
                c[i] = 1;
                break;
            }
    return c;
}

int main()
{

    //freopen("in.txt", "r", stdin);


    cin >> n >> m;

    FOR(i,0,m)
    {
        int a , b , d;
        cin >> a >> b >> d;
        --a;--b;
        E.push_back(MP(d , MP(a , b)));
    }

    int res = 2 * INF;

    sort(ALL(E));

    vector<char> cur(n, 0);
    cur[0] = 1;
    vector<vector<char> > G(n , vector<char>(n, 0));


    int prev = 0;

    FOR(i,0,E.size())
    {
//        cout << 1 << endl;
        vector<vector<char> > B = bpow(G , E[i].first - prev);
        cur = mlt(B , cur);
//        cout << 2 << endl;
 /*       FOR(i,0,n)
        {
            cout << (int)cur[i] << ' ';
        }
        cout << endl;
*/
        vector<char> c = cur;

        FOR(it,0,157)
        {
            if (c[n - 1])
            {
                res = min(res , E[i].first + it);
            }
            c = step(c , i + 1);
        }
  //      cout << 3 << endl;
        G[E[i].second.second][E[i].second.first] = 1;
        prev = E[i].first;
   //     cout << 4 << endl;
    }

    if (res == 2 * INF) cout << "Impossible" << endl;
    else cout << res << endl;

    return 0;
}