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
const int MAX = 1000007;
const int MAX2 = 2000;
const int BASE = 1000000000;

int a[2 * MAX];
int c[2 * MAX];

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    //freopen("huffman.in" , "r" , stdin);

    int n , q;
    cin >> n >> q;

    Int sum = 0;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
        sum += a[i];
    }

    FOR(i,0,n)
    {
        a[i + n] = a[i];
    }

    FOR(tt,0,q)
    {
        Int b;
        cin >> b;
        if (b >= sum)
        {
            cout << 1 << endl;
            continue;
        }
        int r = 0;
        Int cur = 0;
        FOR(i,0,n)
        {
            while (cur + a[r] <= b)
            {
                cur += a[r];
                ++r;
            }
            c[i] = r;
            cur -= a[i];
        }
        int len = INF;
        int st = -1;


        FOR(i,0,n)
        {
            //if (c[i] % n != c[(i + n - 1) % n] % n)
            {
                if (c[i] - i < len)
                {
                    len = c[i] - i;
                    st = i;
                }
            }
        }
        int res = INF;
        FOR(i,n,2 * n)
        {
            c[i] = c[i - n] + n;
        }
        int f = (st + len) % n;
        for(int i = st;; ++i)
        {
            if (i == n) i = 0;
            int v = i;
            int cur = 0;
            while (v < i + n)
            {
                ++cur;
                if (cur == res) break;
                v = c[v];
            }
            res = cur;
            if (i == f) break;
        }
        cout << res << endl;
    }

    return 0;
}