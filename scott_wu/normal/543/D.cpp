#include <iostream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int MAXN = 200100;

ll cpow (ll x, int p)
{
    ll res = 1, xpow = x;
    
    while (p)
    {
        if (p % 2 == 1)
            res = (res * xpow) % MOD;
        p /= 2;
        xpow = (xpow * xpow) % MOD;
    }
    return res;
}

ll inv (ll x)
{
    return cpow (x, MOD - 2);
}

ll divide (ll a, ll b)
{
    return (a * inv (b)) % MOD;
}

int N;
vector <int> child[MAXN];
ll sdp[MAXN];
ll ans[MAXN];

void flood (int cloc)
{
    sdp[cloc] = 1;
    for (int i = 0; i < child[cloc].size(); i++)
    {
        int neigh = child[cloc][i];
        flood (neigh);
        sdp[cloc] = (sdp[cloc] * (sdp[neigh] + 1)) % MOD;
    }
}

void flood2 (int cloc, ll ctop)
{
    ans[cloc] = (ctop * sdp[cloc]) % MOD;
    //cout << cloc << " " << ctop << "\n";
    ll prod = ctop;
    int cnt = 0;
    for (int i = 0; i < child[cloc].size(); i++)
    {
        int neigh = child[cloc][i];
        if (sdp[neigh] == MOD - 1)
            cnt++;
        else
            prod = (prod * (sdp[neigh] + 1)) % MOD;
    }
    
    for (int i = 0; i < child[cloc].size(); i++)
    {
        int neigh = child[cloc][i];
        //cout << ctop << " " << sdp[neigh] + 1 << " " << divide (ctop, sdp[neigh] + 1) << "\n";
        if (sdp[neigh] == MOD - 1 && cnt == 1)
            flood2 (neigh, prod + 1);
        else
            flood2 (neigh, divide (ans[cloc], sdp[neigh] + 1) + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    for (int i = 1; i < N; i++)
    {
        int t;
        cin >> t;
        t--;
        
        child[t].push_back (i);
    }
    
    flood(0);
    flood2(0, 1);
    
    for (int i = 0; i < N; i++)
    {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    
    return 0;
}