#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, d, e;
    cin >> n >> d >> e;
    ll ans = n;
    for(int i = 0; i < 10000000; i++){
        if(d * i > n) continue;
        ans = min(ans, (n - d * i) % (e * 5));
    }
    cout << ans << endl;
}