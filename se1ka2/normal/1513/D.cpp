#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int n;
        ll p;
        cin >> n >> p;
        ll a[200005];
        P q[200005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            q[i] = P(a[i], i);
        }
        sort(q, q + n);
        ll d[200005];
        for(int i = 0; i < n - 1; i++) d[i] = p;
        for(int i = 0; i < n; i++){
            int u = q[i].second;
            ll g = a[u];
            for(int j = u; j < n - 1; j++){
                if(a[j + 1] % g) break;
                if(d[j] <= a[u]) break;
                d[j] = a[u];
            }
            for(int j = u - 1; j >= 0; j--){
                if(a[j] % g) break;
                if(d[j] <= a[u]) break;
                d[j] = a[u];
            }
        }
        ll ans = 0;
        for(int i = 0; i < n - 1; i++) ans += d[i];
        cout << ans << endl;
    }
}