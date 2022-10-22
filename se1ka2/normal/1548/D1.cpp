#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    ll d[4]{0};
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        d[x / 2 % 2 * 2 + y / 2 % 2]++;
    }
    ll ans = 0;
    for(int i = 0; i < 4; i++){
        ans += d[i] * (d[i] - 1) * (d[i] - 2) / 6;
        ans += d[i] * (d[i] - 1) * (n - d[i]) / 2;
    }
    cout << ans << endl;
}