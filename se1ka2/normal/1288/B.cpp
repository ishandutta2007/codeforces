#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll a, b;
        cin >> a >> b;
        ll i = 0;
        ll r = 0;
        for(; i < 11; i++){
            r = r * 10 + 9;
            if(r > b) break;
        }
        cout << a * i << endl;
    }
}