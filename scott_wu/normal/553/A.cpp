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
const int MOD = 1e9 + 7;
const int MAXN = 1100;

ll cpow (ll b, ll e)
{
    ll res = 1, cp = b;
    while (e)
    {
        if (e % 2 == 1)
            res = (res * cp) % MOD;
        cp = (cp * cp) % MOD;
        e /= 2;
    }
    return res % MOD;
}

ll inv (ll x)
{
    return cpow (x, MOD - 2);
}

int K;
int arr[MAXN];

int main() {
    ios_base::sync_with_stdio(0);
    cin >> K;
    for (int i = 0; i < K; i++)
        cin >> arr[i];
    
    int csum = 0;
    ll res = 1;
    
    for (int i = 0; i < K; i++)
    {
        csum += arr[i];
        int a = csum - 1, b = arr[i] - 1;
        
        for (int j = 0; j < b; j++)
        {
            res = (res * (a - j)) % MOD;
            res = (res * inv (j + 1)) % MOD;
        }
    }
    cout << res << "\n";
    return 0;
}