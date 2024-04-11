#include <iostream>
using namespace std;
typedef long long ll;

const ll INF = 1000000000000000000;

ll s[52][200005];
ll l[52][200005];

int main()
{
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll a[200005];
        for(int i = 0; i < n; i++){
            cin >> a[i];
            s[0][i] = a[i];
            l[0][i] = a[i];
        }
        for(ll j = 1; j < 50; j++){
            for(ll i = 0; i < n; i++){
                s[j][i] = max(-INF, s[j - 1][i] + s[j - 1][(i + (1ll << (j - 1))) % n]);
                l[j][i] = max(l[j - 1][i], s[j - 1][i] + l[j - 1][(i + (1ll << (j - 1))) % n]);
            }
        }
        while(m--){
            ll x;
            cin >> x;
            ll k;
            for(k = 0; k < 50; k++){
                if(l[k][0] >= x) break;
            }
            if(k == 50){
                cout << -1 << " ";
                continue;
            }
            ll ans = 0, u = 0, w = 0;
            for(ll j = k; j >= 0; j--){
                if(w + l[j][u] < x){
                    w += s[j][u];
                    ans += (1ll << j);
                    u = (u + (1ll << j)) % n;
                }
            }
            cout << ans << " ";
        }
        cout << endl;
    }
}