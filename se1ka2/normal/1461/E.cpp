#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ll k, l, r, t, x, y;
    cin >> k >> l >> r >> t >> x >> y;
    if(y < x){
        if(k > r - y){
            t--;
            k -= x;
        }
        double d = t * 1.0 * (x - y);
        if(d > 2 * 1e18) cout << "No" << endl;
        else if(k - t * (x - y) >= l) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        if(x + y <= (r - l)) cout << "Yes" << endl;
        else{
            if(k <= r - y) k += y;
            for(int i = 0; i < x * 3; i++){
                ll u = min((k - (r - y) - 1) / x + 1, t);
                t -= u;
                k -= u * x;
                if(k < l){
                    cout << "No" << endl;
                    return 0;
                }
                if(t == 0){
                    cout << "Yes" << endl;
                    return 0;
                }
                k += y;
            }
            cout << "Yes" << endl;
        }
    }
}