#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll x[1002], y[1002];
        for(int i = 0; i < n; i++) cin >> x[i] >> y[i];
        sort(x, x + n);
        sort(y, y + n);
        if(n % 2){
            cout << 1 << endl;
        }
        else{
            cout << (x[n / 2] - x[n / 2 - 1] + 1) * (y[n / 2] - y[n / 2 - 1] + 1) << endl;
        }
    }
}