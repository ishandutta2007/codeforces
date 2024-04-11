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
#define Pi acos(-1.0)
#define y1 adsfasdgasg
#define x2 asdfagdsasdg
#define x1 twretwret
#define y2 oupoupoupo
#define eps 1e-10

typedef long long Int;
typedef unsigned long long UINT;
typedef vector <int> VI;
typedef pair <int, int> PII;

const int INF = 1000000000;
const int MAX = 1024;
const int MAX2 = 7000;
const int BASE = 1000000007;
const int CNT = 300;
const int MOD = 1000000007;

const int MAXN = 200007;
const int K = 4000;

int A[MAXN][300];

char a[MAXN];
char b[MAXN];

unsigned aa[MAXN];
unsigned bb[MAXN];

int F1(int n)
{
    int r = 0;
    while(n)
    {
        r += n % 2;
        n /= 2;
    }
    return r;
}

int prec[1 << 16];

int F(unsigned n)
{
    return prec[n & 65535] + prec[n >> 16];
}

int main()
{
        #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
        #endif

    //freopen("tetrahedron.in", "r", stdin);
    //freopen("tetrahedron.out", "w", stdout);

    FOR(i,0,1 << 16)
    {
        prec[i] = F1(i);
    }

    scanf("%s" , a);
    scanf("%s" , b);
    int n = strlen(a);
    int m = strlen(b);

    /*int n = 200000;
    int m = 200000;
    FOR(i,0,n)
    {
        a[i] = '0' + rand() % 2;
        b[i] = '0' + rand() % 2;
    }*/

    FOR(i,0,n)
    {
        FOR(j,0,32)
        {
            if (i + j < n && a[i + j] == '1')
            {
                aa[i] |= ((unsigned)1 << j);
            }
        }
    }

    FOR(i,0,m)
    {
        FOR(j,0,32)
        {
            if (i + j < m && b[i + j] == '1')
            {
                bb[i] |= ((unsigned)1 << j);
            }
        }
    }


    for(int j = 0; j < m; j += K)
        {
            int jj = j / K;
            if (j + K <= m)
            {
                for(int i = 0; i < n; ++i)
                {
                    if (i + K <= n)
                    {
                        int x = i;
                        int y = j;
                        int bound = K / 32;
                        for(int k = 0; k < bound; ++k)
                        {
                            A[i][jj] += F(aa[x] ^ bb[y]);
                            x += 32;
                            y += 32;
                        }
                        /*for(int k = 0; k < 4; ++k)
                        {
                            A[i][jj] += a[i + k] != b[j + k];
                        }*/
                    }
                }
            }
        }

    int q;
    scanf("%d" , &q);

    FOR(i,0,q)
    {
        int x,y,len;
        scanf("%d%d%d" , &x , &y , &len);
        int res = 0;
        int l = (K - y % K) % K;
        while (y % K != 0)
        {
            if (len == 0) break;
            if (l >= 32 && len >= 32)
            {
                res += F(aa[x] ^ bb[y]);
                l -= 32;
                len -= 32;
                x += 32;
                y += 32;
            }
            else
            {
                res += (a[x] != b[y]);
                --l;
                --len;
                ++x;
                ++y;
            }
        }
        //cout << res << endl;
        int yy = y / K;
        while (len >= K)
        {
            res += A[x][yy];
            len -= K;
            ++yy;
            y += K;
            x += K;
        }
        while (len > 0)
        {
            if (len >= 32)
            {
                res += F(aa[x] ^ bb[y]);
                len -= 32;
                x += 32;
                y += 32;
            }
            else
            {
                res += F(a[x] != b[y]);
                --len;
                ++x;
                ++y;
            }
            //cout << len << ' ' << x << ' ' << y << ' ' << res << endl;
        }
        printf("%d\n" , res);
    }


    return 0;
}