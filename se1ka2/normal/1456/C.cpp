#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll c[500005];
    for(int i = 0; i < n; i++) scanf("%lld", &c[i]);
    sort(c, c + n, greater<ll>());
    ll s = 0, ans = 0;
    int l;
    for(l = 0; l < n; l++){
        if(s + c[l] < 0) break;
        ans += s;
        s += c[l];
    }
    if(l == n){
        cout << ans << endl;
        return 0;
    }
    ans += s;
    c[l] += s;
    for(int i = 0; i < n - l; i++){
        ans += c[n - 1 - i] * (i / (k + 1));
    }
    cout << ans << endl;
}