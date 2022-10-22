#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, k;
    cin >> n >> m >> k;
    ll a[200005];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<ll>());
    cout << a[0] * (m - (m / (k + 1))) + a[1] * (m / (k + 1)) << endl;
}