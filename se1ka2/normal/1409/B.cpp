#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a, b, x, y, n;
        cin >> a >> b >> x >> y >> n;
        ll ans = a * b;
        if(a - x >= n) ans = min(ans, (a - n) * b);
        else ans = min(ans, x * max(y, b - (n - (a - x))));
        if(b - y >= n) ans = min(ans, a * (b - n));
        else ans = min(ans, max(x, a - (n - (b - y))) * y);
        cout << ans << endl;
    }
}