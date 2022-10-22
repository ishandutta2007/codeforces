#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll h[200003];
    for(int i = 0; i < n; i++) cin >> h[i];
    sort(h, h + n, greater<ll>());
    for(int i = 0; i < n; i++) h[i] -= h[n - 1];
    if(h[0] == 0){
        cout << 0 << endl;
        return 0;
    }
    ll j = 0;
    ll ans = 0;
    ll now = 0;
    for(int i = h[0]; i > 0; i--){
        while(i == h[j]) j++;
        now += j;
        if(now > k){
            now = j;
            ans++;
        }
    }
    cout << ans + 1 << endl;
}