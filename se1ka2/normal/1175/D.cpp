#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[300005], s[300005] {0};
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = n - 1; i >= 0; i--) s[i] = s[i + 1] + a[i];
    sort(s + 1, s + n, greater<ll>());
    ll ans = 0;
    for(int i = 0; i < k; i++) ans += s[i];
    cout << ans << endl;
}