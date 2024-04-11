#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a, b;
        cin >> a >> b;
        if(a < b) swap(a, b);
        if(b * 2 < a){
            cout << b << endl;
        }
        else{
            cout << a - b + (b * 2 - a) * 2 / 3 << endl;
        }
    }
}