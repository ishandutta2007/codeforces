#include <algorithm>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

const ll MOD = 1000000007;

int main()
{
    string n;
    cin >> n;
    ll k = n.size();
    reverse(n.begin(), n.end());
    ll d[100005];
    d[0] = 1;
    for(int i = 1; i <= 100000; i++) d[i] = d[i - 1] * 10 % MOD;
    ll l = 0;
    ll ans = 0;
    for(int i = 0; i < k; i++){
        ans = (ans + (n[i] - '0') * (l + (k - i) * (k - i - 1) / 2 % MOD * d[i])) % MOD;
        l = (l + d[i] * (i + 1)) % MOD;
    }
    cout << ans << endl;
}