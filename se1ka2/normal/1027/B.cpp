#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main()
{
    ll n, q;
    cin >> n >> q;
    for(int c = 0; c < q; c++){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        if((x + y) % 2){
            ll r = x / 2;
            if(x % 2){
                cout << (n * n + 1) / 2 + r * n + n / 2 + y / 2 + 1 << endl;
            }
            else{
                cout << (n * n + 1) / 2 + r * n + (y + 1) / 2 << endl;
            }
        }
        else{
            ll r = x / 2;
            if(x % 2){
                cout << r * n + (n + 1) / 2 + (y + 1) / 2 << endl;
            }
            else{
                cout << r * n + y / 2 + 1 << endl;
            }
        }
    }
}