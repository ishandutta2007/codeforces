#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll l, r;
        cin >> l >> r;
        ll ans = 0;
        for(ll p = 1; p <= 1000000000; p *= 10){
            ans += r / p - l / p;
        }
        cout << ans << endl;
    }
}