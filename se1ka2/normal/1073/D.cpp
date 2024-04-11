#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll t;
    cin >> t;
    ll a[200005];
    ll s = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        s += a[i];
    }
    int k = n;
    int next[200005];
    for(int i = 0; i < n; i++) next[i] = i + 1;
    next[n + 1] = 0;
    ll ans = 0;
    while(k){
        ans += t / s * k;
        t %= s;
        int i = n + 1;
        while(i != n){
            int l = i;
            i = next[i];
            while(i < n && a[i] > t){
                s -= a[i];
                k--;
                i = next[i];
            }
            next[l] = i;
            if(i == n) break;
            ans++;
            t -= a[i];
        }
    }
    cout << ans << endl;
}