#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = 0;
        while(n){
            ans += n;
            n /= 2;
        }
        cout << ans << endl;
    }
}