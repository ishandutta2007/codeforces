#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, a, b;
        cin >> n >> a >> b;
        if(a == 1){
            if((n - 1) % b == 0) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
        else{
            ll t = 1;
            bool f = false;
            while(t <= n){
                if((n - t) % b == 0){
                    cout << "Yes" << endl;
                    f = true;
                    break;
                }
                t *= a;
            }
            if(!f) cout << "No" << endl;
        }
    }
}