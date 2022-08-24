#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const int MAXP = (1 << 19) + 100;
const int P = (1 << 18);
const ll MOD = 1e9 + 7;

int Q, N;
vector <int> child[MAXN];
int v[MAXN];
int par[MAXN];
int nord;
int ord[MAXN];
int ssize[MAXN];
int qval[MAXN][3];
int deg[MAXN];

ll mult[MAXP], mval[MAXP];


ll cpow (ll x, int ccnt)
{
    if (ccnt == 1) return x;
    ll cres = cpow (x, ccnt / 2);
    cres = (cres * cres) % MOD;
    
    if (ccnt % 2 == 1)
        cres = (cres * x) % MOD;
    return cres;
}

ll inv (ll x)
{
    return cpow (x, MOD - 2);
}

void prop (int cloc)
{
    if (cloc >= P) return;
    
    mult[2*cloc] = (mult[2*cloc] * mult[cloc]) % MOD;
    mult[2*cloc+1] = (mult[2*cloc+1] * mult[cloc]) % MOD;
    mval[2*cloc] = (mval[2*cloc] * mult[cloc]) % MOD;
    mval[2*cloc+1] = (mval[2*cloc+1] * mult[cloc]) % MOD;
    
    mult[cloc] = 1;
}

ll rsum (int lo, int hi, int cloc, int rlo, int rhi)
{
    if (hi < rlo || rhi < lo) return 0;
    if (lo <= rlo && rhi <= hi)
    {
        //cout << "rsum " << lo << " " << hi << " " << cloc << " " << rlo << " " << rhi << " " << mval[cloc] << "\n";
        return mval[cloc];
    }
    
    prop (cloc);
    int rmid = (rlo + rhi) / 2;
    return (rsum (lo, hi, cloc * 2, rlo, rmid) + rsum (lo, hi, cloc * 2 + 1, rmid + 1, rhi)) % MOD;
}

void rset (int loc, ll val)
{
    rsum (loc, loc, 1, 0, P - 1);
    loc += P;
    
    mval[loc] = (val * mult[loc]) % MOD;
    
    //cout << "rset " << val << " " << mult[loc] << "\n";
    //cout << loc << " " << mval[loc] << "\n" << endl;
    loc /= 2;
    while (loc)
    {
        mval[loc] = (mval[2*loc] + mval[2*loc+1]) % MOD;
        loc /= 2;
    }
}

ll mget (int loc)
{
    rsum (loc, loc, 1, 0, P - 1);
    return mult[loc+P];
}

void mset (int loc, ll val)
{
    rsum (loc, loc, 1, 0, P - 1);
    loc += P;
    mval[loc] = (mval[loc] * inv (mult[loc])) % MOD;
    mult[loc] = val;
    rset (loc - P, mval[loc]);
}

void mmult (int lo, int hi, ll val, int cloc, int rlo, int rhi)
{
    if (hi < rlo || rhi < lo) return;
    if (lo <= rlo && rhi <= hi)
    {
        //cout << lo << " " << hi << " " << val << " " << cloc << " " << rlo << " " << rhi << "\n";
        mult[cloc] = (mult[cloc] * val) % MOD;
        mval[cloc] = (mval[cloc] * val) % MOD;
        //cout << mval[cloc] << "\n";
        return;
    }
    
    prop (cloc);
    int rmid = (rlo + rhi) / 2;
    mmult (lo, hi, val, 2 * cloc, rlo, rmid);
    mmult (lo, hi, val, 2 * cloc + 1, rmid + 1, rhi);
    
    //cout << "mmult " << cloc << " " << rlo << " " << rhi << " " << mval[2*cloc] << " " << mval[2*cloc+1] << "\n";
    mval[cloc] = (mval[2*cloc] + mval[2*cloc+1]) % MOD;
}

void flood (int cloc)
{
    ord[cloc] = nord++;
    ssize[cloc] = 1;
    for (int i = 0; i < child[cloc].size(); i++)
    {
        int neigh = child[cloc][i];
        flood (neigh);
        ssize[cloc] += ssize[neigh];
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin >> v[0] >> Q;
    N = 1;
    
    for (int i = 0; i < Q; i++)
    {
        cin >> qval[i][0];
        if (qval[i][0] == 1)
            cin >> qval[i][1] >> qval[i][2];
        else
            cin >> qval[i][1];
    }
    
    for (int i = 0; i < Q; i++)
    {
        if (qval[i][0] == 1)
        {
            par[N] = qval[i][1] - 1;
            child[qval[i][1] - 1].push_back (N);
            v[N] = qval[i][2];
            N++;
        }
    }
    
    nord = 0;
    flood (0);
    
    for (int i = 0; i < N; i++)
        deg[i] = 0;
    
    for (int i = 0; i < MAXP; i++)
        mult[i] = mval[i] = 0;
    for (int i = 0; i <= P; i++)
        mult[i] = 1;
    rset (0, v[0]);
    
    
    nord = 1;
    for (int i = 0; i < Q; i++)
    {
        if (qval[i][0] == 1)
        {
            int d = deg[par[nord]];
            mmult (ord[par[nord]], ord[par[nord]] + ssize[par[nord]] - 1, ((d + (ll) 2) * inv (d + 1)) % MOD, 1, 0, P - 1);
            
            //cout << "Q" << i << " " << mget (ord[par[nord]]) << "\n";
            mset (ord[nord], mget (ord[par[nord]]));
            rset (ord[nord], v[nord]);
            
            deg[par[nord]]++;
            nord++;
        }
        else
        {
            int cloc = qval[i][1] - 1;
            ll ans = rsum (ord[cloc], ord[cloc] + ssize[cloc] - 1, 1, 0, P - 1) % MOD;
            if (cloc)
                ans = (ans * inv (mget (ord[par[cloc]]))) % MOD;
            cout << ans << endl;
        }
    }
    
    //system ("Pause");
    return 0;
}