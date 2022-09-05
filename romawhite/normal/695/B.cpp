#include <bits/stdc++.h>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define RFOR(i,b,a) for(int i=(b)-1;i>=(a);--i)
#define FILL(A,val) memset(A,val,sizeof(A))
#define MP make_pair
#define PB push_back
#define ALL(A) A.begin(),A.end()
#define SZ(A) (int)A.size()

typedef long long Int;
typedef unsigned long long UInt;
typedef pair<int, int> PII;
typedef vector<int> VI;

const int INF = 1000000000;
const int MAX = 100000;
const int ST = 1000000007;

int n, m, s, t, del, it, a, b;
Int res;
vector<PII> G[MAX];
PII E[MAX];
int W[MAX];
int U[MAX];
int T[MAX];
int F[MAX];
int C[MAX];
VI D;
bool was;

void dfs1(int v, int p)
{
    if (v == t)
        was = 1;
    U[v] = 1;
    FOR (i,0,SZ(G[v]))
    {
        int to = G[v][i].first;
        int id = G[v][i].second;
        if (U[to])
            continue;
        dfs1(to, id);
        D.PB(id);
    }
}

void dfs2(int v, int p)
{
    C[v] = 0;
    if (v == t)
        C[v] = 1;
    U[v] = 1;
    T[v] = it ++;
    F[v] = T[v];

    FOR (i,0,SZ(G[v]))
    {
        int to = G[v][i].first;
        int id = G[v][i].second;
        if (id == p || id == del)
            continue;
        if (U[to] == 1)
        {
            F[v] = min(F[v], T[to]);
        }
        else
        {
            dfs2(to, id);
            F[v] = min(F[v], F[to]);
            C[v] |= C[to];
            if (C[to] == 1 && F[to] > T[v])
            {
                if (W[del] + W[id] < res)
                {
                    res = W[del] + W[id];
                    a = del;
                    b = id;
                }
            }
        }

    }
}

int main()
{
    //freopen("in.txt" , "r" , stdin);

    cin >> n >> m;
    cin >> s >> t;
    -- s;
    -- t;

    FOR (i,0,m)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        -- u;
        -- v;
        W[i] = w;
        G[u].PB(MP(v, i));
        G[v].PB(MP(u, i));
    }

    was = 0;
    dfs1(s, -1);

    if (!was)
    {
        cout << 0 << endl << 0 << endl;
        return 0;
    }

    res = Int(INF) * INF;
    FOR (i,0,SZ(D))
    {
        del = D[i];
        was = 0;
        FOR (j,0,n)
        {
            U[j] = 0;
        }
        it = 0;
        dfs2(s, -1);
        //cout << del+1 << ' ' << C[s] << endl;
        if (C[s] == 0)
        {
            if (W[del] < res)
            {
                res = W[del];
                a = del;
                b = -1;
            }
        }
    }

    if (res == Int(INF) * INF)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << res << endl;
    int cnt = 1;
    if (b != -1)
        ++ cnt;
    cout << cnt << endl;
    cout << a+1 << ' ';
    if (b != -1)
        cout << b+1 << endl;









    return 0;
}