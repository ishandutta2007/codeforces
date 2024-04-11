#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    if(n == 2) cout << 1 << endl;
    else if(n == 4) cout << 3 << endl;
    else{
        ll ans = 1;
        for(ll i = n; i > n / 2; i--) ans *= i;
        for(ll i = n / 2; i >= 1; i--) ans /= i;
        ans /= 2;
        for(int i = 2; i < n / 2; i++) ans *= i * i;
        cout << ans << endl;
    }
}