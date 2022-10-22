#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    ll p[18];
    p[0] = 2050;
    for(int i = 1; i <= 15; i++) p[i] = p[i - 1] * 10;
    while(t--){
        ll n;
        cin >> n;
        int ans = 0;
        if(n % 2050){
            cout << -1 << endl;
            continue;
        }
        for(int i = 15; i >= 0; i--){
            ans += n / p[i];
            n %= p[i];
        }
        cout << ans << endl;
    }
}