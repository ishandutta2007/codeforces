#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    ll x, y, m;
    cin >> x >> y >> m;

    if (x <= 0 && y <= 0 && max(x, y) < m){
        cout << "-1";
        return 0;
    }

    if (x > y) swap(x, y);
    ll ans = 0;

    if (y >= m){
        cout << '0';
        return 0;

    }

    if (x < 0 && y > 0){
        ll k = (-x) / y;
        if (k > 0){
            ans += k;
            x += k * y;
        }
    }

    while(y < m){
        x += y;
        if (x > y)
            swap(x, y);
        ans++;
    }

    cout << ans;


    return 0;
}