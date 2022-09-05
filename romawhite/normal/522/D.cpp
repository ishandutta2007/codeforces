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
#include <complex>
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
const int MAX = 600007;
const int MAX2 = 6255;
const int BASE = 1000000000;

struct RMQ
{
    int n;
    int* T;
    RMQ(){}
    RMQ(int nn)
    {
        n = nn;
        T = new int[n * 4];
    }
    void Init(int val)
    {
        FOR (i,0,n*4)
            T[i] = val;
    }
    int Update(int j, int d, int i, int l, int r)
    {
        if (l == r)
            T[i] = min(T[i], d);
        else
        {
            int m = (l+r)/2;
            if (j <= m)
                Update(j, d, i*2, l, m);
            else
                Update(j, d, i*2+1, m+1, r);
            T[i] = min(T[i*2], T[i*2+1]);
        }
    }
    int GetMin(int l, int r, int i, int tl, int tr)
    {
        if (l == tl && r == tr)
            return T[i];
        int m = (tl+tr)/2;
        if (r <= m)
            return GetMin(l, r, i*2, tl, m);
        if (l > m)
            return GetMin(l, r, i*2+1, m+1, tr);
        int a = GetMin(l, m, i*2, tl, m);
        int b = GetMin(m+1, r, i*2+1, m+1, tr);
        return min(a, b);
    }
};

int n, m;
int A[MAX];
int R[MAX];
vector <PII> Q[MAX];
RMQ M;
map<int, int> P;

int main()
{
    #ifndef ONLINE_JUDGE
        //freopen("in.txt", "r", stdin);
    #endif

    scanf("%d %d", &n, &m);
    FOR (i,0,n)
    {
        scanf("%d", &A[i]);
    }

    FOR (i,0,m)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        -- l;
        -- r;
        Q[r].PB(MP(l, i));
    }
    M = RMQ(n);
    M.Init(INF);
    FOR (i,0,n)
    {
        int cur = A[i];
        if (P.find(cur) != P.end())
        {
            int pos = P[cur];
            M.Update(pos, i - pos, 1, 0, M.n-1);
        }
        P[cur] = i;
        FOR (j,0,SZ(Q[i]))
        {
            int l = Q[i][j].first;
            int r = i;
            int id = Q[i][j].second;
            int res = M.GetMin(l, r, 1, 0, M.n-1);
            if (res >= INF)
                res = -1;
            R[id] = res;
        }
    }
    FOR (i,0,m)
        printf("%d\n", R[i]);




    return 0;
}