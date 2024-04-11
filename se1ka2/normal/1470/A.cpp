#include <algorithm>
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
        int n, m;
        cin >> n >> m;
        int k[300005];
        for(int i = 0; i < n; i++){
            cin >> k[i];
            k[i]--;
        }
        sort(k, k + n, greater<int>());
        ll c[300005];
        for(int i = 0; i < m; i++) cin >> c[i];
        ll s = 0;
        for(int i = 0; i < n; i++) s += c[k[i]];
        ll ans = s;
        int r = n + m;
        for(int i = 0; i < min(m, n); i++){
            if(r == 0) break;
            s = s + c[i] - c[k[i]];
            ans = min(ans, s);
            r = min(r - 1, k[i]);
        }
        cout << ans << "\n";
    }
}