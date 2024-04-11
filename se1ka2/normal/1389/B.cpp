#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k, z;
        cin >> n >> k >> z;
        ll a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        ll s[100005];
        s[0] = 0;
        for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i - 1];
        ll ans = s[k + 1];
        for(int i = 0; i < k - 1; i++){
            int l = min(i / 2 + 1, z);
            ans = max(ans, s[k + 1 - l * 2] + (a[k - i - 1] + a[k - i - 2]) * l);
        }
        cout << ans << endl;
    }
}