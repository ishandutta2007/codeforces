#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MAXN = 1000100;
const ll MOD = 998244353;

ll mpow (ll b, int e)
{
    if (e == 0) return 1;
    if (e == 1) return b % MOD;
    ll v = mpow (b, e / 2);
    v = (v * v) % MOD;
    if (e & 1) v = (v * b) % MOD;
    return v;
}

ll minv (ll x)
{
    return mpow (x, MOD - 2);
}

int N;
int arr[MAXN];
int ncnt[MAXN];

vector <ll> cnts;
int G;
vector <ll> gfacs;
ll nmul[MAXN]; // # of occurrences (not divided)
ll nsum[MAXN]; // sum of occurrences per loc

ll fac[MAXN];
ll ifac[MAXN];

int gcd (int a, int b)
{
    if (b == 0) return a;
    return gcd (b, a % b);
}

void gogo()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];
    sort (arr, arr + N);
    for (int i = 0; i <= N; i++)
        ncnt[i] = 0;

    if (arr[0] == arr[N-1])
    {
        cout << "1\n";
        return;
    }

    for (int i = 0; i < N; i++)
        ncnt[arr[i]]++;

    cnts.clear();
    G = 0;
    for (int i = 0; i <= N; i++)
    {
        if (ncnt[i])
        {
            G = gcd (G, ncnt[i]);
            cnts.push_back(ncnt[i]);
        }
    }

    gfacs.clear();
    for (int i = 1; i <= G; i++)
    {
        if (G % i == 0)
        {
            gfacs.push_back(i);
        }
    }

    for (int i = 0; i <= N; i++)
        nmul[i] = nsum[i] = 0;

    int ng = gfacs.size();
    ll ctot = 0;
    ll cans = 0;
    for (int i = ng - 1; i >= 0; i--)
    {
        int v = gfacs[i];
        ll ncnt = fac[N/v];
        ll pcnt = 0;
        for (int j = 0; j < cnts.size(); j++)
        {
            ncnt = (ncnt * ifac[cnts[j]/v]) % MOD;
            pcnt = pcnt + ((cnts[j]/v) * ((ll) cnts[j]/v - 1)) / 2;
            pcnt %= MOD;
        }

        ll tcnt = (N/v) * ((ll) N/v - 1) / 2;
        tcnt %= MOD;

        nmul[i] = ncnt;
        nsum[i] = ((ncnt * pcnt) % MOD * minv (tcnt)) % MOD;
        for (int j = i + 1; j < ng; j++)
        {
            if (gfacs[j] % gfacs[i] != 0) continue;
            nmul[i] = (nmul[i] - nmul[j] + MOD) % MOD;
            nsum[i] = (nsum[i] - nsum[j] + MOD) % MOD;
        }

        //cout << gfacs[i] << " " << nmul[i] << " " << nsum[i] << "\n";
        ctot += (nmul[i] * minv (N/v)) % MOD;
        cans += (nsum[i] * minv (N/v)) % MOD;
        ctot %= MOD;
        cans %= MOD;
    }
    cans = (N * cans) % MOD;
    cout << (N - (cans * minv (ctot)) % MOD + MOD) % MOD << "\n";
}

int main()
{
    ios_base::sync_with_stdio(0);

    fac[0] = 1;
    for (int i = 1; i < MAXN; i++)
        fac[i] = (i * fac[i-1]) % MOD;
    for (int i = 0; i < MAXN; i++)
        ifac[i] = minv (fac[i]);

    int T; cin >> T;
    for (int t = 0; t < T; t++)
        gogo();
}