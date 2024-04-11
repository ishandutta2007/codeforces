#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 100000000000000000;

int main()
{
    int n;
    cin >> n;
    ll a[5005];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = INF;
    for(int r = 0; r < n; r++){
        ll b[5005]{0};
        ll c = 0;
        for(int i = r - 1; i >= 0; i--){
            ll d = (b[i] - b[i + 1]) / a[i] + 1;
            c += d;
            b[i] -= a[i] * d;
        }
        for(int i = r + 1; i < n; i++){
            ll d = (b[i - 1] - b[i]) / a[i] + 1;
            c += d;
            b[i] += a[i] * d;
        }
        ans = min(ans, c);
    }
    cout << ans << endl;
}