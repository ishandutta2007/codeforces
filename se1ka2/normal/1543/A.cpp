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
        if(a == b){
            cout << 0 << " " << 0 << endl;
        }
        else{
            if(a < b) swap(a, b);
            cout << a - b << " " << min(a % (a - b), (a - b) - a % (a - b)) << endl;
        }
    }
}