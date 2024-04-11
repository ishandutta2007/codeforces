#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll n, p, w, d;
    cin >> n >> p >> w >> d;
    for(ll i = 0; i < 200000; i++){
        if(d * i > p) break;
        if((p - d * i) % w == 0){
            ll j = (p - d * i) / w;
            if(i + j <= n) cout << j << " " << i << " " << n - (i + j) << endl;
            else cout << -1 << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}