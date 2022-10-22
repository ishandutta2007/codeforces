#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[300005], b[300005];
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    ll s = 0;
    ll r = 0;
    for(int i = 0; i < n; i++){
        s += a[i] * i;
        r += a[i];
    }
    for(int i = 0; i < n; i++){
        s += b[i] * (n * 2 - 1 - i);
        r += b[i];
    }
    ll ans = s;
    for(int i = 0; i < n - 2; i += 2){
        s -= b[i] * (n - (i + 1)) * 2;
        s -= b[i + 1] * (n - (i + 2)) * 2;
        r -= b[i] + b[i + 1] + a[i];
        if(i > 0) r -= a[i - 1];
        s += r * 2;
        ans = max(ans, s);
    }
    s = 0;
    r = 0;
    for(int i = 1; i < n; i++){
        s += a[i] * (n * 2 - i);
        r += a[i];
    }
    for(int i = 0; i < n; i++){
        s += b[i] * (i + 1);
        r += b[i];
    }
    ans = max(ans, s);
    for(int i = 1; i < n - 2; i += 2){
        s -= a[i] * (n - (i + 1)) * 2;
        s -= a[i + 1] * (n - (i + 2)) * 2;
        r -= a[i] + a[i + 1] + b[i] + b[i - 1];
        s += r * 2;
        ans = max(ans, s);
    }
    cout << ans << endl;
}