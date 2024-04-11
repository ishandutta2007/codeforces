#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        ll c;
        cin >> n >> c;
        ll a[200005], b[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n - 1; i++) cin >> b[i];
        ll t = 0, u = 0;
        ll ans = (c + a[0] - 1) / a[0];
        for(int i = 1; i < n; i++){
            ll k = (b[i - 1] - t + a[i - 1] - 1) / a[i - 1];
            t = t + a[i - 1] * k - b[i - 1];
            u += k;
            ans = min(ans, (c - t + a[i] - 1) / a[i] + u + i);
        }
        cout << ans << endl;
    }
}