#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        ll ans = 0;
        for(ll i = 2; i <= min(b, 50000ll); i++){
            ans += min(i - 1, a / (i + 1));
        }
        if(b > 50000){
            for(ll i = 1; i <= 50000; i++){
                ans += max(0ll, min(a / i - 50001, b - 50000));
            }
        }
        cout << ans << endl;
    }
}