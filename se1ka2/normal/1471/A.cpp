#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        ll a[100005];
        ll s = 0, l = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s += a[i];
            l += (a[i] - 1) / x + 1;
        }
        cout << (s - 1) / x + 1 << " " << l << endl;
    }
}