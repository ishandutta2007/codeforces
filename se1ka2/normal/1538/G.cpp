#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll x, y, a, b;
        cin >> x >> y >> a >> b;
        if(x > y) swap(x, y);
        if(a > b) swap(a, b);
        if(x * b < y * a) cout << x / a << endl;
        else{
            ll s = (x + y) / (a + b);
            ll left = -1, right = s;
            while(right - left > 1){
                ll mid = (right + left) / 2;
                if(a * mid + b * (s - mid) > y) left = mid;
                else right = mid;
            }
            if(a * (s - right) + b * right > x) cout << s - 1 << endl;
            else cout << s << endl;
        }
    }
}