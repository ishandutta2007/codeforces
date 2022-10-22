#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int q;
    cin >> q;
    for(int c = 0; c < q; c++){
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        if(m % 2 == 1 && m % 10 != 5) ans = n / (m * 10) * 45;
        if(m % 2 == 0 && m % 10 != 0) ans = n / (m * 10) * 40;
        if(m % 10 == 5) ans = n / (m * 10) * 25;
        n -= n / (m * 10) * (m * 10);
        ll now = 0;
        for(int i = 0; i < 10; i++){
            now += m;
            if(now > n) break;
            ans += now % 10;
        }
        cout << ans << endl;
    }
}