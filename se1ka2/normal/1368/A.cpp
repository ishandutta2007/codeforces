#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll a, b, n;
        cin >> a >> b >> n;
        if(a < b) swap(a, b);
        int ans = 0;
        while(a <= n){
            b += a;
            swap(a, b);
            ans++;
        }
        cout << ans << endl;
    }
}