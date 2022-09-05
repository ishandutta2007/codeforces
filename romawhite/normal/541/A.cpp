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
const int MAX = 1000000;
const int MAX2 = 7000;
const int BASE = 1000000000;

struct RMQ
{
    int n;
    int * T;
    int * I;
    RMQ(){}
    RMQ(int len)
    {
        n = len;
        T = new int[n*4];
        I = new int[n*4];
        FOR (i,0,n*4)
                T[i] = I[i] = 0;
    }
    void add(int j, int d, int id, int i, int tl, int tr)
    {
        if (tl == tr)
        {
            T[i] = d;
            I[i] = id;
        }
        else
        {
            int m = (tl+tr)/2;
            if (j <= m)
                add(j, d, id, i*2, tl, m);
            else
                add(j, d, id, i*2+1, m+1, tr);
            if (T[i*2] > T[i*2+1])
            {
                T[i] = T[i*2];
                I[i] = I[i*2];
            }
            else
            {
                T[i] = T[i*2+1];
                I[i] = I[i*2+1];
            }
        }
    }
    PII getMax(int l, int r, int i, int tl, int tr)
    {
        //cout << l << ' '<< r << endl;
        if (l == tl && r == tr)
            return MP(T[i], I[i]);
        int m = (tl+tr)/2;
        if (r <= m)
            return getMax(l, r, i*2, tl, m);
        else
        if (l > m)
            return getMax(l, r, i*2+1, m+1, tr);
        else
        {
            PII a = getMax(l, m, i*2, tl, m);
            PII b = getMax(m+1, r, i*2+1, m+1, tr);
            if (a.first > b.first)
                return a;
            return b;
        }
    }
};

int n, m, cnt, q;
Int res;
int r1, r2;
PII A[MAX];
pair<PII, PII> B[MAX];
vector <PII> In[MAX];
vector <PII> Out[MAX];
set<PII> S;
int X[MAX];
int XX[MAX];
RMQ Q;
set<PII> W[MAX];

void Solve()
{
    FOR (i,0,n)
    {
        In[A[i].first].PB(MP(A[i].second, i));
        Out[A[i].second].PB(MP(A[i].first, i));
    }
    S.clear();
    sort(B, B+m);
    int pos = 0;
    FOR (i,0,m)
    {
        int l = B[i].first.first;
        int r = B[i].first.second;
        int c = B[i].second.first;
        int id = B[i].second.second;
        while (pos < l)
        {
            FOR (j,0,SZ(In[pos]))
                S.insert(In[pos][j]);
            ++ pos;
        }
        if (!S.empty())
        {
            PII cur = *S.rbegin();
            cur.first = min(cur.first, r);
            if (X[cur.first] > X[l])
            {
                //cout << c << ' ' << (X[cur.first]-X[l]) << endl;
                if (res < Int(c) * (X[cur.first]-X[l]))
                {
                    res = Int(c) * (X[cur.first]-X[l]);
                    r1 = cur.second;
                    r2 = id;
                }
            }
        }
    }
}

bool Cmp(pair<PII, PII> a, pair<PII, PII> b)
{
    if (a.first.second > b.first.second)
        return 1;
    if (a.first.second < b.first.second)
        return 0;
    return a.first.first > b.first.first;
}

void SolveRev()
{
    S.clear();
    sort(B, B+m, Cmp);
    int pos = q-1;
    FOR (i,0,m)
    {
        int l = B[i].first.first;
        int r = B[i].first.second;
        int c = B[i].second.first;
        int id = B[i].second.second;
        while (pos > r)
        {
            FOR (j,0,SZ(Out[pos]))
                S.insert(Out[pos][j]);
            -- pos;
        }
        if (!S.empty())
        {
            PII cur = *S.begin();
            cur.first = max(cur.first, l);
            if (X[cur.first] < X[r])
            {
                if (res < Int(c) * (X[r]-X[cur.first]))
                {
                    res = Int(c) * (X[r]-X[cur.first]);
                    r1 = cur.second;
                    r2 = id;
                }
            }
        }
    }
}

void SolveIn()
{
    Q = RMQ(q);
    sort(B, B+m);
    FOR (i,0,n)
    {
       // cout << A[i].second-A[i].first << endl;
       // cout << A[i].second << ' ' <<  X[A[i].second]-X[A[i].first] << endl;
        W[A[i].second].insert(MP(X[A[i].second]-X[A[i].first], i));
    }
  //  cout << q << endl;
    FOR (i,0,q)
        if (W[i].empty())
            Q.add(i, 0, -1, 1, 0, Q.n-1);
        else
            Q.add(i, W[i].rbegin()->first, W[i].rbegin()->second, 1, 0, Q.n-1);
    int pos = 0;
    FOR (i,0,m)
    {
        int l = B[i].first.first;
        int r = B[i].first.second;
        int c = B[i].second.first;
        int id = B[i].second.second;
        while (pos < l)
        {
            FOR (j,0,SZ(In[pos]))
            {
                int id = In[pos][j].second;
                int len = X[A[id].second] - X[A[id].first];
                //cout << len << ' ' << id << endl;
                //cout << '-' << endl;
                W[A[id].second].erase(W[A[id].second].find(MP(len, id)));
                //cout << '-' << endl;
                if (W[A[id].second].empty())
                    Q.add(A[id].second, 0, -1, 1, 0, Q.n-1);
                else
                    Q.add(A[id].second, W[A[id].second].rbegin()->first, W[A[id].second].rbegin()->second, 1, 0, Q.n-1);
            }
            ++ pos;
        }
        PII cur = Q.getMax(l, r, 1, 0, Q.n-1);
        //cout << cur.first << '-' << ' ' << l << ' ' << r << endl;
        if (cur.first > 0)
        {
            //cout << c << ' ' << cur.first << ' ' << l << ' ' << r << endl;
            if (Int(c)*cur.first > res)
            {
                res = Int(c)*cur.first;
                r1 = cur.second;
                r2 = id;
            }
        }
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
    #endif



    scanf("%d %d", &n, &m);
    //n = rand() % 10 + 1;
    //m = rand() % 10 + 1;
    FOR (i,0,n)
    {
        int l, r;
        scanf("%d %d", &l, &r);
        //r = rand() % 100 + 1;
        //l = rand() % r + 1;
        -- l;
        -- r;
        A[i] = MP(l, r);
        XX[cnt ++] = l;
        XX[cnt ++] = r;
    }
    FOR (i,0,m)
    {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        //r = rand() % 100 + 1;
        //l = rand() % r + 1;
        //c = rand() % 50 + 1;
        -- l;
        -- r;
        B[i] = MP(MP(l, r), MP(c, i));
        XX[cnt ++] = l;
        XX[cnt ++] = r;
    }
    sort(XX, XX+cnt);
    X[0] = XX[0];
    q = 1;
    FOR (i,1,cnt)
        if (XX[i] != XX[i-1])
            X[q ++] = XX[i];
    FOR (i,0,n)
    {
        A[i].first = lower_bound(X, X+q, A[i].first) - X;
        A[i].second = lower_bound(X, X+q, A[i].second) - X;
    }
    FOR (i,0,m)
    {
        B[i].first.first = lower_bound(X, X+q, B[i].first.first) - X;
        B[i].first.second = lower_bound(X, X+q, B[i].first.second) - X;
    }


    res = 0;
    r1 = -1;
    r2 = -1;

    Solve();
    SolveRev();
    SolveIn();


    cout << res << endl;
    if (res > 0)
        cout << r1+1 << ' ' << r2+1 << endl;




    /*
    int res2 = 0;
    FOR (i,0,n)
        FOR (j,0,m)
        {

            int ll = max(X[A[i].first], X[B[j].first.first]);
            int rr = min(X[A[i].second], X[B[j].first.second]);

            if (ll < rr)
                res2 = max(res2, (rr-ll) * B[j].second.first);
        }

    //cout << res << ' ' << res2 << endl;
    if (res != res2)
    {
        cout << res << ' ' << res2 << endl;
        cout << n << endl;
        FOR (i,0,n)
            cout << X[A[i].first] << ' ' << X[A[i].second] << endl;
        FOR (i,0,m)
            cout << X[B[i].first.first] << ' ' << X[B[i].first.second]  << ' ' << B[i].second.first << endl;
        return 0;
    }
    //cout << endl;

//return 0;
   }
   */




    return 0;
}