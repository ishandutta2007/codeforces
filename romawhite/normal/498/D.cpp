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

int t[61][4 * MAX];
int a[MAX];

void build(int v, int l, int r)
{
    if (l == r)
    {
        FOR(i,0,60)
        {
            if (i % a[l] == 0)
                t[i][v] = 2;
            else
                t[i][v] = 1;
        }
        return;
    }

    int m = (l + r) / 2;
    build(2 * v + 1 , l, m);
    build(2 * v + 2 , m + 1 , r);

    FOR(i,0,60)
    {
        t[i][v] = t[i][2 * v + 1] + t[(i + t[i][2 * v + 1]) % 60][2 * v + 2];
    }
}

int res;

void get(int v, int l, int r, int L, int R)
{
    if (l == L && r == R)
    {
        res += t[res % 60][v];
        return;
    }

    int m = (l + r) / 2;
    if (L <= m)
    {
        get(2 * v + 1 , l, m, L, min(R, m));
    }

    if (R >= m + 1)
    {
        get(2 * v + 2, m + 1, r, max(L, m + 1), R);
    }
}

void upd(int v, int l, int r, int ind, int val)
{
    if (l == r)
    {
        a[l] = val;
        FOR(i,0,60)
        {
            if (i % a[l] == 0)
                t[i][v] = 2;
            else
                t[i][v] = 1;
        }
        return;
    }

    int m = (l + r) / 2;
    if (ind <= m)
    {
        upd(2 * v + 1, l , m, ind, val);
    }
    else
    {
        upd(2 * v + 2, m + 1 , r, ind, val);
    }

    FOR(i,0,60)
    {
        t[i][v] = t[i][2 * v + 1] + t[(i + t[i][2 * v + 1]) % 60][2 * v + 2];
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    //freopen("in.txt", "r", stdin);
    #endif

    int n;
    cin >> n;
    FOR(i,0,n)
    {
        scanf("%d" , &a[i]);
    }

    int q;
    cin >> q;

    build(0,0,n - 1);

    FOR(i,0,q)
    {

        char ch;
        scanf("%c" , &ch);
        int x, y;
        scanf("%c %d %d", &ch, &x, &y);
        if (ch == 'A')
        {
            --x;
            y -= 2;
            res = 0;
            get(0,0,n - 1,x, y);
            printf("%d\n" , res);
        }
        if (ch == 'C')
        {
            --x;
            upd(0,0,n - 1,x, y);
        }
    }

    return 0;
}