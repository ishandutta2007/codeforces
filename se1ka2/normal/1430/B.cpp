#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<ll>());
        ll ans = 0;
        for(int i = 0; i < min(n, k + 1); i++) ans += a[i];
        cout << ans << endl;
    }
}