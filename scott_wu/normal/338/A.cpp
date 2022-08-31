#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <cmath>
#include <queue>

using namespace std;
typedef long long ll;
const int MOD = 1000000009;

int main()
{
    ll N, M, K;
    
    cin >> N >> M >> K;
    
    ll t = N - (N / K);
    
    if (t >= M)
    {
        cout << M << "\n";
        //return 0;
    }
    else
    {
        ll x = M - t;
        
        ll r100 = 1, b100 = 0;
        for (int i = 0; i < 100; i++)
        {
            b100 = (b100 + K) % MOD;
            r100 = (2 * r100) % MOD;
            b100 = (b100 * 2) % MOD;
        }
        
        ll res = 0;
        for (int i = 0; i < x / 100; i++)
        {
            res = (res * (ll) r100 + b100) % MOD;
        }
        for (int i = 0; i < x % 100; i++)
        {
            res = (res + K) % MOD;
            res = (res * 2) % MOD;
        }
        res += M - x * K;
        res %= MOD;
        
        cout << res << "\n";
    }
    //system ("Pause");
    return 0;
}