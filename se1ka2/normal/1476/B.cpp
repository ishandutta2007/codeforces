#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        ll s;
        cin >> s;
        ll ans = 0;
        for(int i = 1; i < n; i++){
            ll p;
            cin >> p;
            if(s * k < p * 100){
                ll x = (p * 100 - 1) / k + 1 - s;
                ans += x;
                s += x;
            }
            s += p;
        }
        cout << ans << endl;
    }
}