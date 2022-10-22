#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        ll n, m, k;
        cin >> n >> m >> k;
        if(n > k || m > k){
            cout << -1 << endl;
            continue;
        }
        ll ans = k;
        if(n % 2 != k % 2) ans--;
        if(m % 2 != k % 2) ans--;
        cout << ans << endl;
    }
}