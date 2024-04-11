#include <iostream>
#include <iomanip>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m;
    cin >> n >> m;
    ll ans = 0;
    for(int i = 0; i < m; i++){
        ll x, d;
        scanf("%lld %lld", &x, &d);
        ans += x * n;
        ll b;
        if(d > 0) b = d * n * (n - 1) / 2;
        else b = d * (((n - 1) / 2) * ((n - 1) / 2 + 1) / 2 + (n / 2) * (n / 2 + 1) / 2);
        ans += b;
    }
    cout << fixed << setprecision(15) << ans * 1.0 / n << endl;
}