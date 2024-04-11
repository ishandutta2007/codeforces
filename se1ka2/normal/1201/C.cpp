#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[200003];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<ll>());
    ll now = 1048576 * 1024;
    ll mid = now / 2;
    while(mid){
        ll s = 0;
        for(int i = 0; i <= n / 2; i++) s += max(0ll, now - a[i]);
        if(s > k) now -= mid;
        else now += mid;
        mid /= 2;
    }
    ll s = 0;
    for(int i = 0; i <= n / 2; i++) s += max(0ll, now - a[i]);
    if(s > k) now--;
    cout << now << endl;
}