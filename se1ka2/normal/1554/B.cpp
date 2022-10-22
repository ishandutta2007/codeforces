#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll ans = -INF;
        for(ll i = n; i > 0; i--){
            for(ll j = i - 1; j > 0; j--){
                if(i * j < ans) break;
                ans = max(ans, i * j - k * (a[i - 1] | a[j - 1]));
            }
        }
        cout << ans << endl;
    }
}