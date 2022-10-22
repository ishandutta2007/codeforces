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
        ll a[10005];
        ll s = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s += a[i];
        }
        if(s % n){
            cout << -1 << endl;
            continue;
        }
        ll m = s / n;
        cout << (n - 1) * 3 << endl;
        for(int i = 2; i <= n; i++){
            ll x = ((a[i] - 1) / i + 1) * i - a[i];
            cout << 1 << " " << i << " " << x << endl;
            a[1] -= x * 1;
            a[i] += x * 1;
            x = a[i] / i;
            cout << i << " " << 1 << " " << x << endl;
            a[i] -= x * i;
            a[1] += x * i;
        }
        for(int i = 2; i <= n; i++){
            cout << 1 << " " << i << " " << m << endl;
            a[1] -= m * 1;
            a[i] += m * 1;
        }
    }
}