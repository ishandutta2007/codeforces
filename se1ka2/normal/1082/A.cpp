#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000007;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, x, y, d;
        cin >> n >> x >> y >> d;
        if(abs(y - x) % d == 0){
            cout << abs(y - x) / d << endl;
        }
        else{
            ll ans = INF;
            if((y - 1) % d == 0){
                ans = min(ans, (x - 2) / d + 1 + (y - 1) / d);
            }
            if((n - y) % d == 0){
                ans = min(ans, (n - x - 1) / d + 1 + (n - y) / d);
            }
            if(ans != INF) cout << ans << endl;
            else cout << -1 << endl;
        }
    }
}