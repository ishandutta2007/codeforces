#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll k;
        cin >> k;
        ll left = 0, right = k * 2;
        while(right - left > 1){
            ll mid = (right + left) / 2;
            if(mid * mid < k) left = mid;
            else right = mid;
        }
        if(k <= left * left + right) cout << k - left * left << " " << right << endl;
        else cout << right << " " << left * left + right * 2 - k << endl;
    }
}