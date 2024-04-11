#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll x, y;
        cin >> x >> y;
        if(x > y){
            cout << x + y << endl;
            continue;
        }
        if(x == y){
            cout << x << endl;
            continue;
        }
        else{
            ll s = (x + y) / 2;
            ll a = s % x;
            cout << y - a << endl;
            continue;
        }
    }
}