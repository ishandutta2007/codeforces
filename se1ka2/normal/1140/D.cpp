#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i = 2; i < n; i++) ans += i * (i + 1);
    cout << ans << endl;
}