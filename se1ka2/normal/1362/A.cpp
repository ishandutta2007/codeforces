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
        if(a % b){
            cout << -1 << endl;
            continue;
        }
        a /= b;
        ll p = 1;
        ll k = 0;
        while(p < a){
            p *= 2;
            k++;
        }
        if(p != a){
            cout << -1 << endl;
        }
        else{
            cout << (k + 2) / 3 << endl;
        }
    }
}