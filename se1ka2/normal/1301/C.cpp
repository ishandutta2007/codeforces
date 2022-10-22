#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int w = 0; w < t; w++){
        ll n, m;
        cin >> n >> m;
        ll r = n - m;
        ll ans = 0;
        if(r % (m + 1) == 0){
            ll k = r / (m + 1);
            ans = k * (k + 1) / 2 * (m + 1);
        }
        else{
            ll k = r / (m + 1);
            ans = (k + 1) * (k + 2) / 2 * (r % (m + 1)) + k * (k + 1) / 2 * (m + 1 - (r % (m + 1)));
        }
        cout << n * (n + 1) / 2 - ans << endl;
    }
}