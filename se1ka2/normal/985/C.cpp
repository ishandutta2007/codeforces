#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k, l;
    cin >> n >> k >> l;
    ll a[100005];
    for(int i = 0; i < n * k; i++) cin >> a[i];
    sort(a, a + n * k);
    int p = upper_bound(a, a + n * k, a[0] + l) - a;
    if(p < n){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    for(int i = 0; i < n; i++) ans += a[min(i * k, p - (n - i))];
    cout << ans << endl;
}