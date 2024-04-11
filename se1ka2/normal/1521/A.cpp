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
        if(b == 1) cout << "NO" << endl;
        else{
            cout << "YES" << endl;
            cout << a * b << " " << a << " " << a * b + a << endl;
        }
    }
}