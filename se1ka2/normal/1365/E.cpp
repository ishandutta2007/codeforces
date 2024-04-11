#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll a[503];
    for(int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            for(int k = 0; k < n; k++){
                ans = max(ans, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << ans << endl;
}