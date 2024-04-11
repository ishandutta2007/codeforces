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
        ll a[200005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll ans = 0;
        for(int i = 0; i < n - 1; i++) ans = max(ans, a[i] * a[i + 1]);
        cout << ans << endl;
    }
}