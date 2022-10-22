#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, greater<ll>());
        ll ans;
        ans = max(max(a[0] * a[1] * a[2] * a[3] * a[4], a[0] * a[1] * a[2] * a[n - 2] * a[n - 1]),
                  a[0] * a[n - 4] * a[n - 3] * a[n - 2] * a[n - 1]);
        cout << ans << endl;
    }
}