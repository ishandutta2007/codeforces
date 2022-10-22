#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        ll a[200005];
        map<ll, ll> mp;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            mp[(k * a[i] - a[i]) % k]++;
        }
        ll ans = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr->first == 0) continue;
            ans = max(ans, k * (itr->second - 1) + itr->first + 1);
        }
        cout << ans << endl;
    }
}