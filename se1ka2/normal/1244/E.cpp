#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    cin >> n >> k;
    ll a[100002];
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    ll now = 1048576 * 1024;
    ll mid = now / 2;
    while(mid > 0){
        ll r = 0;
        for(int i = 0; i < n - 1 - i; i++){
            r += max(0ll, a[n - i - 1] - a[i] - now);
        }
        if(r > k) now += mid;
        else now -= mid;
        mid /= 2;
    }
    if(now == 1) now--;
    for(int c = 0; c < 2; c++){
        ll r = 0;
        for(int i = 0; i < n - 1 - i; i++){
            r += max(0ll, a[n - i - 1] - a[i] - now);
        }
        if(r > k) now++;
    }
    cout << now << endl;
}