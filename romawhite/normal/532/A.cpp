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
const int MAX = 507000;
const int MAX2 = 7000;
const int BASE = 1000000000;


struct RMQ
{
    int n;
    int * T;
    int * P;
    RMQ(){}
    RMQ(int len)
    {
        n = len;
        T = new int[n*4];
        P = new int[n*4];
        FOR (i,0,n*4)
        {
            T[i] = 0;
            P[i] = 0;
        }
    }
    void push(int v, int l, int r)
    {
        if (P[v] != 0 && l != r)
        {
            T[v*2] += P[v];
            P[v*2] += P[v];
            T[v*2+1] += P[v];
            P[v*2+1] += P[v];
        }
        P[v] = 0;
    }
    void add(int l, int r, int d, int i, int tl, int tr)
    {
        if (l > r)
            return;
        push(i, tl, tr);
        if (l == tl && r == tr)
        {
            T[i] += d;
            P[i] += d;
        }
        else
        {
            int m = (tl+tr)/2;
            if (r <= m)
                add(l, r, d, i*2, tl, m);
            else
            if (l > m)
                add(l, r, d, i*2+1, m+1, tr);
            else
            {
                add(l, m, d, i*2, tl, m);
                add(m+1, r, d, i*2+1, m+1, tr);
            }
            T[i] = min(T[i*2], T[i*2+1]);
        }
    }
    int get(int l, int r, int i, int tl, int tr)
    {
        push(i, tl, tr);
        //if (T[i] == 0)
          //  return 0;
        if (l == tl && r == tr)
            return T[i];
        else
        {
            int m = (tl+tr)/2;
            if (r <= m)
                return get(l, r, i*2, tl, m);
            if (l > m)
                return get(l, r, i*2+1, m+1, tr);
            int a = get(l, m, i*2, tl, m);
            int b = get(m+1, r, i*2+1, m+1, tr);
            return min(a, b);
        }
    }
};

int n, m;
int H[MAX];
int M1[MAX];
int M2[MAX];
VI G[MAX];
VI I[MAX];
int A[MAX];
RMQ Q;

void dfs1(int v, int p, int Min, int cnt, int pos, int Min2)
{
    if (H[v] < Min)
    {
        Min2 = Min;
        Min = H[v];
        cnt = 1;
        pos = v;
    }
    else
    if (H[v] == Min)
    {
        Min2 = Min;
        ++ cnt;
    }
    else
    if (H[v] < Min2)
    {
        Min2 = H[v];
    }

    M1[v] = Min;
    M2[v] = Min2;

    if (cnt == 1)
        I[pos].PB(v);
    FOR (i,0,SZ(G[v]))
    {
        int to = G[v][i];
        if (to == p)
            continue;
        dfs1(to, v, Min, cnt, pos, Min2);
    }
}

int Height[MAX];

void dfs47(int v, int p)
{
    FOR(i,0,G[v].size())
    {
        int to = G[v][i];
        if (to == p) continue;
        Height[to] = min(H[to] , Height[v]);
        dfs47(to, v);
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif

    scanf("%d", &n);
    FOR (i,0,n)
        scanf("%d", &H[i]);
    FOR (i,0,n-1)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        -- u;
        -- v;
        G[u].PB(v);
        G[v].PB(u);
    }

    dfs1(0, -1, INF, 0, -1, INF);

    scanf("%d", &m);
    FOR (i,0,m)
        scanf("%d", &A[i]);
    sort(A, A+m);

    Q = RMQ(m);
    FOR (i,0,m)
    {
        Q.add(i, i, -(m-i), 1, 0, Q.n-1);
    }

    FOR (i,0,n)
    {
        int h = M1[i];
        int pos = upper_bound(A, A+m, h) - A - 1;
        if (pos >= 0)
            Q.add(0, pos, 1, 1, 0, Q.n-1);
    }

    int add;

    Height[0] = H[0];
    dfs47(0, -1);
    sort(Height, Height + n);
    reverse(Height, Height + n);
    reverse(A, A+m);
    //FOR (i,0,m)
    //cout << Height[i] << ' ' << A[i] << endl;
    int needHeight = -1;
    FOR(i,0,m)
    {
        if (A[i] > Height[i])
        {
            needHeight = A[i];
            break;
        }
    }

    reverse(A, A+m);

    if (needHeight == -1)
    {
        cout << 0 << endl;
        return 0;
    }

    //cout << needHeight << endl;
    //needHeight = 6;

    int res = INF;
    FOR (i,0,n)
    {
        if (H[i] >= needHeight)
            continue;
        int h = max(H[i], needHeight);
        FOR (j,0,SZ(I[i]))
        {
            int v = I[i][j];
            int old = upper_bound(A, A+m, M1[v]) - A - 1;
            if (old >= 0)
                Q.add(0, old, -1, 1, 0, Q.n-1);
            int next = upper_bound(A, A+m, min(M2[v], h)) - A - 1;
            if (next >= 0)
                Q.add(0, next, 1, 1, 0, Q.n-1);
            //cout << old << ' ' << next << endl;
        }

        int w = Q.get(0, m-1, 1, 0, Q.n-1);
        if (w >= 0)
        {
            res = min(res, h - H[i]);
        }

        FOR (j,0,SZ(I[i]))
        {
            int v = I[i][j];
            int old = upper_bound(A, A+m, M1[v]) - A - 1;
            if (old >= 0)
                Q.add(0, old, +1, 1, 0, Q.n-1);
            int next = upper_bound(A, A+m, min(M2[v], h)) - A - 1;
            if (next >= 0)
                Q.add(0, next, -1, 1, 0, Q.n-1);
        }
        //FOR (j,0,m)
          //  cout << Q.get(j, j, 1, 0, Q.n-1) << ' ';
        //cout << endl;
    }

    if (res >= INF)
        res = -1;
    cout << res << endl;






    return 0;
}