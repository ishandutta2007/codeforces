#include "bits/stdc++.h"
using namespace std;
 
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define RFOR(i,b,a) for (int i = (b) - 1; i >= (a); i--)
#define ITER(it,a) for (__typeof(a.begin()) it = a.begin(); it != a.end(); it++)
#define FILL(a,value) memset(a, value, sizeof(a))
 
#define SZ(a) (int)a.size()
#define ALL(a) a.begin(), a.end()
#define PB push_back
#define MP make_pair
 
typedef long long Int;
typedef vector<int> VI;
typedef pair<int, int> PII;
 
const double PI = acos(-1.0);
const int INF = 1000 * 1000 * 1000;
const Int LINF = INF * (Int) INF;
const int MAX = 200007;
 
const int MOD = 998244353;
 
const double Pi = acos(-1.0);

VI G[MAX];
int tin[MAX];
int tout[MAX];
int timer = 0;
int P[MAX];
int SZ[MAX];

void dfs(int v, int p = -1)
{
    tin[v] = timer ++;
    P[v] = p;
    SZ[v] = 1;
    for(int to: G[v])
    {
        if (to == p) continue;
        dfs(to, v);
        SZ[v] += SZ[to];
    }
    tout[v] = timer;
}

const int K = 400;

int t[MAX];
int bl[MAX];
void Add(int i, int val)
{
	t[i] += val;
    if (t[i] >= MOD) t[i] -= MOD;
    bl[i / K] += val;
    if (bl[i / K] >= MOD) bl[i / K] -= MOD;
}

int Sum(int r)
{
	int l = 0;
    int res = 0;
    while (l <= r)
    {
        if (l % K == 0 && l + K - 1 <= r)
        {
            res += bl[l / K];
            if (res >= MOD) res -= MOD;
            l += K;
        }
        else
        {
            res += t[l];
            if (res >= MOD) res -= MOD;
            l ++;
        }
    }
    return res;
}


int M[MAX];



int V[MAX][K + 7];

int U[MAX];

bool C[MAX];

int CMP[MAX];
int sz_cmp;

void dfs2(int v, int p, int id) {
    if (p != -1)
        CMP[sz_cmp ++] = v;
    for(int to: G[v])
    {
        if (to == p) continue;
        if (p == -1)
        {
            sz_cmp = 0;
        }
        dfs2(to, v, id);
        if (p == -1)
        {
            FOR(i,0,sz_cmp)
            {
                V[CMP[i]][id] = sz_cmp;
            }
        }
    }
}

Int bpow(Int a, int k)
{
    Int res = 1;
    while (k)
    {
        if (k % 2)
        {
            res *= a;
            res %= MOD;
        }
        a *= a;
        a %= MOD;
        k /= 2;
    }
    return res;
}

int main(int argc, char* argv[])
{
    ios::sync_with_stdio(false); cin.tie(0);
	
    int n, q;
    cin >> n >> q;
    vector<PII> E;
    FOR(i,0,n - 1)
    {
        int a, b;
        cin >> a >> b;
        --a;--b;
        G[a].push_back(b);
        G[b].push_back(a);
        E.push_back(MP(a, b));
    }

    dfs(0);
    FOR(i,0,n)
    {
        M[i] = tin[i];
    }

    FOR(i,0,n)
    {
        G[i].clear();
    }
    FOR(i,0,n - 1)
    {
        int a = M[E[i].first];
        int b = M[E[i].second];
        G[a].push_back(b);
        G[b].push_back(a);
    }

    timer = 0;
    dfs(0);

    VI R;

    FOR(i,0,n)
    {
        if (SZ(G[i]) > n / K)
        {
            R.push_back(i);
            C[i] = true;
            dfs2(i, -1, SZ(R) - 1);
        }
    }

    FOR(i,0,q)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            int v, d;
            cin >> v >> d;
            -- v;
            v = M[v];
            if (C[v])
            {
                U[v] += d;
                U[v] %= MOD;
            }
            else
            {
                for(int to: G[v])
                {
                    if (to == P[v]) continue;
                    int val = 1LL * d * (n - SZ[to]) % MOD;
                    Add(tin[to], val);
                    Add(tout[to], MOD - val);
                }
                int val = 1LL * d * SZ[v] % MOD;
                Add(0, val);
                Add(tin[v], MOD - val);
                Add(tout[v], val);
                val = 1LL * d * n % MOD;
                Add(tin[v], val);
                Add(tin[v] + 1, MOD - val);
            }
        }
        else
        {
            int v;
            cin >> v;
            -- v;
            v = M[v];
            Int invn = bpow(n, MOD - 2);
            Int res = Sum(tin[v]);
            FOR(i,0,SZ(R))
            {
                res += 1LL * U[R[i]] * (n - V[v][i]) % MOD;
            }
            res %= MOD;
            res *= invn;
            res %= MOD;
            cout << res << endl;
        }
    }




}