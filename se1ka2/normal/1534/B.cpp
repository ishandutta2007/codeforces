#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        ll a[400005];
        a[0] = 0;
        for(int i = 1; i <= n; i++) cin >> a[i];
        a[n + 1] = 0;
        ll ans = 0;
        for(int i = 1; i <= n; i++){
            if(a[i] > a[i - 1] && a[i] > a[i + 1]){
                ans += a[i] - max(a[i - 1], a[i + 1]);
                a[i] = max(a[i - 1], a[i + 1]);
            }
        }
        for(int i = 1; i <= n; i++){
            if(a[i] > a[i - 1]) ans += a[i] - a[i - 1];
            if(a[i] > a[i + 1]) ans += a[i] - a[i + 1];
        }
        cout << ans << endl;
    }
}