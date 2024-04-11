#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll x;
        cin >> x;
        ll s = 0;
        ll r = 0;
        ll c = 0;
        for(ll i = 1;; i <<= 1){
            r = r * 2 + i * i;
            s += r;
            if(s > x) break;
            c++;
        }
        cout << c << endl;
    }
}