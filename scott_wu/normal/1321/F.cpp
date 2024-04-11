#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 200100;
const ll MOD = 1e9 + 7;
const ll P = 5349;

int N, Q;
string S;
int tt[MAXN];

ll mpow[MAXN];
ll chash[MAXN], cnum[MAXN];
int nloc[MAXN], ploc[MAXN];

ll gh (int lo, int hi)
{
    int np = cnum[hi] - cnum[lo];
    if (np == 0)
    {
        if ((tt[lo] == 2) ^ (tt[hi-1] == 1))
            return S[lo];
        return 0;
    }

    ll ctot = (chash[hi] - mpow[np] * chash[lo]) % MOD;
    ctot = (ctot + MOD) % MOD;
    if (tt[lo] == 2)
    {
        int cp = nloc[lo];
        if (S[cp] == '1')
        {
            ctot = (ctot - mpow[np-1] * S[lo]) % MOD;
            ctot = (ctot + MOD) % MOD;
        }
        else
            ctot = (ctot + mpow[np] * S[lo]) % MOD;
    }
    if (lo < hi && tt[hi-1] == 1)
    {
        int cp = ploc[hi-1];
        if (S[cp] == '1')
            return gh (lo, cp);
        ctot = (ctot * P + S[hi-1]) % MOD;
    }
    return ctot;
}

int main()
{
    ios_base::sync_with_stdio(0);

    cin >> N >> S;

    for (int i = 0; i < N; i++)
    {
        if (i > 0 && S[i] == '1' && S[i-1] == '1' && !tt[i-1])
        {
            tt[i-1] = 1;
            tt[i] = 2;
        }
    }

    chash[0] = cnum[0] = 0;
    for (int i = 0; i < N; i++)
    {
        if (tt[i])
        {
            chash[i+1] = chash[i];
            cnum[i+1] = cnum[i];
        }
        else
        {
            chash[i+1] = (P * chash[i] + S[i]) % MOD;
            cnum[i+1] = cnum[i] + 1;
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (tt[i])
        {
            if (i) ploc[i] = ploc[i-1];
            else ploc[i] = -1e9;
        }
        else
            ploc[i] = i;
    }
    for (int i = N; i >= 0; i--)
    {
        if (tt[i])
            nloc[i] = nloc[i+1];
        else
            nloc[i] = i;
    }

    mpow[0] = 1;
    for (int i = 0; i < N; i++)
        mpow[i+1] = (mpow[i] * P) % MOD;

    cin >> Q;
    for (int i = 0; i < Q; i++)
    {
        int x, y, l;
        cin >> x >> y >> l;
        x--, y--;

        if (gh (x, x + l) == gh (y, y + l))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}