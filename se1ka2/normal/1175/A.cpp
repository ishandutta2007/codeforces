#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for(int c = 0; c < t; c++){
        ll n, k;
        cin >> n >> k;
        ll ans = 0;
        while(n){
            ans += n % k;
            n /= k;
            ans++;
        }
        cout << ans - 1 << endl;
    }
}