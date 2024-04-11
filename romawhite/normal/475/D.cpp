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
#include <fstream>
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
#define y0 gfdssdfer
#define y1 wetgwervbwqr

typedef long long Int;

const int MAX = 100007;
const int MOD = 1000000007;

map<int, Int> M;

int a[MAX];
int b[MAX][20];

int gcd(int a, int b)
{
    if (!b) return a;
    return gcd(b , a % b);
}

int main()
{
   // freopen("in.txt" , "r" , stdin);
  //  freopen("out.txt" , "w" , stdout);

    int n;
    scanf("%d" , &n);
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }

    FILL(b, -1);

    RFOR(i,n,0)
    {
        b[i][0] = a[i];
        FOR(j,1,20)
        {
            if (i + (1 << j) <= n)
            {
                b[i][j] = gcd(b[i][j - 1] , b[i + (1 << (j - 1))][j - 1]);
            }
        }
    }

    /*FOR(i,0,n)
    {
        FOR(j,0,4)
        {
            cout << b[i][j] << ' ';
        }
        cout << endl;
    }*/

    int q;
    cin >> q;
    vector<int> Q;
    FOR(i,0,q)
    {
        int x;
        scanf("%d" , &x);
        Q.push_back(x);
        M[x] = 0;
    }

    FOR(i,0,n)
    {
        int G = a[i];
        int l = i;
        int r = i;
        while(l < n)
        {
            RFOR(j,20,0)
            {
                if (r < n && r + (1 << j) <= n && b[r][j] % G == 0)
                {
                    r += (1 << j);
                }
            }
            if (M.count(G))
            {
                M[G] += r - l;
            }
            //cout << l << ' ' << r << ' ' << G << endl;
            l = r;
            G = gcd(G , a[l]);

        }
    }

    FOR(i,0,q)
    {
        printf("%I64d\n" , M[Q[i]]);
    }

    return 0;
}