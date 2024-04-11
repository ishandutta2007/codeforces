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
        ll c[6];
        for(int i = 0; i < 6; i++) cin >> c[i];
        for(int t = 0; t < 100; t++){
            for(int i = 0; i < 6; i++){
                c[i] = min(c[i], c[(i + 1) % 6] + c[(i + 5) % 6]);
            }
        }
        if(x >= 0){
            if(y >= 0){
                if(x >= y) cout << c[0] * y + c[5] * (x - y) << endl;
                else cout << c[0] * x + c[1] * (y - x) << endl;
            }
            else{
                cout << c[5] * x + c[4] * abs(y) << endl;
            }
        }
        else{
            if(y >= 0){
                cout << c[2] * abs(x) + c[1] * y << endl;
            }
            else{
                if(abs(x) >= abs(y)) cout << c[3] * abs(y) + c[2] * (abs(x) - abs(y)) << endl;
                else cout << c[3] * abs(x) + c[4] * (abs(y) - abs(x)) << endl;
            }
        }
    }
}