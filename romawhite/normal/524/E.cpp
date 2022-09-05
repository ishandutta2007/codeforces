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
const int MAX = 400007;
const int MAX2 = 7000;
const int BASE = 1000000000;

struct RMQ
{
    int n;
    int T[MAX * 4];
    RMQ(){};
    RMQ(int len)
    {
        n = len;
        FOR (i,0,n*4)
            T[i] = -INF;
    }
    void Set(int j, int d, int i, int l, int r)
    {
        if (l == r)
        {
            T[i] = d;
        }
        else
        {
            int m = (l+r)/2;
            if (j <= m)
                Set(j, d, i*2, l, m);
            else
                Set(j, d, i*2+1, m+1, r);
            T[i] = max(T[i*2], T[i*2+1]);
        }
    }
    int GetMax(int l, int r, int i, int tl, int tr)
    {
        if (l == tl && r == tr)
            return T[i];
        int m = (tl+tr)/2;
        if (r <= m)
            return GetMax(l, r, i*2, tl, m);
        if (l > m)
            return GetMax(l, r, i*2+1, m+1, tr);
        int a = GetMax(l, m, i*2, tl, m);
        int b = GetMax(m+1, r, i*2+1, m+1, tr);
        return max(a, b);
    }
};

int n, m, k, q;
int cnt;
PII A[MAX];
pair<PII, PII> Q[MAX];
PII P[MAX];
bool U[MAX];
int Next[MAX];
int Prev[MAX];
int I[MAX];
int C[MAX];
int Res[MAX][2];
vector <PII> In[MAX];
vector <PII> Out[MAX];
RMQ T;

void Solve(int N, int M, int w)
{
    FILL(U, 0);
    FOR (i,0,k)
    {
        P[i] = A[i];
        U[A[i].second] = 1;
    }
    cnt = k;
    FOR (i,0,M)
        if (U[i] == 0)
            P[cnt ++] = MP(INF, i);
    sort(P, P+cnt);
    FOR (i,0,M)
        I[i] = -INF;
    FOR (i,0,cnt)
    {
        int y = P[i].second;
        Prev[i] = I[y];
        I[y] = i;
    }
    FOR (i,0,M)
        I[i] = INF;
    RFOR (i,cnt,0)
    {
        int y = P[i].second;
        Next[i] = I[y];
        I[y] = i;
    }
    FOR (i,0,cnt)
    {
        In[i].clear();
        Out[i].clear();
    }
    FILL(C, 0);
    FOR (i,0,q)
    {
        PII p = Q[i].first;
        int a = lower_bound(P, P+cnt, MP(p.first, -INF)) - P;
        int b = upper_bound(P, P+cnt, MP(p.second, INF)) - P - 1;
        if (a > b)
            C[i] = 2;
        else
        {
            In[a].PB(MP(b, i));
            Out[b].PB(MP(a, i));
        }
    }

    T = RMQ(M);
    int pos = 0;
    FOR (i,0,cnt)
    {
        FOR (j,0,SZ(In[i]))
        {
            int id = In[i][j].second;
            int r = In[i][j].first;
            int val = T.GetMax(Q[id].second.first, Q[id].second.second, 1, 0, T.n-1);
            if (val > r)
                ++ C[id];
        }
        //while (pos < i && P[pos].first < P[i].first)
        T.Set(P[i].second, Next[i], 1, 0, T.n-1);
    }
    T = RMQ(M);
    RFOR (i,cnt,0)
    {
        FOR (j,0,SZ(Out[i]))
        {
            int id = Out[i][j].second;
            int l = Out[i][j].first;
            int val = -T.GetMax(Q[id].second.first, Q[id].second.second, 1, 0, T.n-1);
            if (val < l)
                ++ C[id];
        }
        T.Set(P[i].second, -Prev[i], 1, 0, T.n-1);
    }
    //FOR (i,0,cnt)
      //  cout << P[i].first << ' ' << P[i].second << endl;
    //FOR (i,0,q)
      //  cout << C[i] << endl;
    FOR (i,0,q)
        if (C[i] > 0)
            Res[i][w] = 0;
        else
            Res[i][w] = 1;
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif


    scanf("%d %d %d %d", &n, &m, &k, &q);
    //n = 10;
    //m = 100;
    //k = 500;
    //q = 100000;
    FOR (i,0,k)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        //x = rand() % n + 1;
        //y = rand() % m + 1;
        -- x;
        -- y;
        A[i] = MP(x, y);
    }
    FOR (i,0,q)
    {
        int x, y, xx, yy;
        scanf("%d %d %d %d", &x, &y, &xx, &yy);
        //yy = rand() % m + 1;
        //y = rand() % yy + 1;
        //xx = rand() % n + 1;
        //x = rand() % xx + 1;
        -- x;
        -- y;
        -- xx;
        -- yy;
        Q[i] = MP(MP(x, xx), MP(y, yy));
    }

    Solve(n, m, 0);

    //FOR (i,0,q)
      //  cout << Res[i][0] << ' ' << Res[i][1] << endl;

    FOR (i,0,k)
        swap(A[i].first, A[i].second);
    FOR (i,0,q)
        swap(Q[i].first, Q[i].second);

    Solve(m, n, 1);

    //FOR (i,0,q)
      //  cout << Res[i][0] << ' ' << Res[i][1] << endl;


    FOR (i,0,q)
    {

        if (Res[i][0] || Res[i][1])
            printf("YES\n");
        else
            printf("NO\n");


        /*
        set<int> S1;
        set<int> S2;
        FOR (j,0,k)
            if (A[j].first >= Q[i].first.first && A[j].first <= Q[i].first.second)
                if (A[j].second >= Q[i].second.first && A[j].second <= Q[i].second.second)
                {
                        S2.insert(A[j].second);
                        S1.insert(A[j].first);
                }
        bool res0 = 0, res1 = 0;
        if (S1.size() == Q[i].first.second - Q[i].first.first + 1)
            res0 = 1;
        if (S2.size() == Q[i].second.second - Q[i].second.first + 1)
            res1 = 1;
        if (res0 != Res[i][0])
            cout << "EROOR" << endl;
        if (res1 != Res[i][1])
            cout << "EROOR" << endl;
        //cout << res0 << ' ' << res1 << ' ' << SZ(S1) << ' ' << SZ(S2) << ' ' << Res[i][0] << ' ' << Res[i][1] << endl;
        //cout << Q[i].first.first << ' ' << Q[i].first.second << ' ' << Q[i].second.first << ' ' << Q[i].second.second << endl;
        */
    }







    return 0;
}