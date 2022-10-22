#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll s = 0;
        for(int i = 0; i < n; i++){
            ll a;
            cin >> a;
            s += a;
        }
        s %= n;
        cout << s * (n - s) << endl;
    }
}