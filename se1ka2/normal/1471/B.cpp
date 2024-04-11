#include <iostream>
using namespace std;
typedef long long ll;

ll a[100005];
ll d[100005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        ll x;
        cin >> n >> x;
        for(int i = 0; i < n; i++) cin >> a[i];
        for(int i = 0; i < n; i++){
            d[i] = 1;
            int b = a[i];
            while(b % x == 0){
                b /= x;
                d[i]++;
            }
        }
        int l = 0;
        for(int i = 1; i < n; i++){
            if(d[i] < d[l]) l = i;
        }
        ll ans = 0;
        for(int i = 0; i < l; i++) ans += a[i] * (d[l] + 1);
        for(int i = l; i < n; i++) ans += a[i] * d[l];
        cout << ans << endl;
    }
}