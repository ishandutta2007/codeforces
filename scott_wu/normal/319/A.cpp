#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
typedef long long ll;
const ll MOD = 1000000007;

string str;

ll cpow (int x)
{
    ll res = 1;
    for (int i = 0; i < x; i++)
        res = (2 * res) % MOD;
    return res;
}

int main()
{
    cin >> str;
    
    int N = str.length();
    
    ll ans = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        ans = (2 * ans) % MOD;
        if (str[i] == '1')
            ans = (ans + cpow (2 * (N - 1 - i))) % MOD;
    }
    
    cout << ans << "\n";
    return 0;
}