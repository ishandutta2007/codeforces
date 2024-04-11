#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int d[20][300005];

int lth(int v, ll *a){
    int res = 0;
    for(int i = 19; i >= 0; i--){
        if(d[i][v] >= 0 && a[d[i][v]]){
            v = d[i][v];
            res += (1 << i);
        }
    }
    return res;
}

int par(int v, int l){
    for(int i = 19; i >= 0; i--){
        if((l >> i) & 1) v = d[i][v];
    }
    return v;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    ll a[300005], c[300005];
    cin >> q >> a[0] >> c[0];
    for(int u = 1; u <= q; u++){
        int o;
        cin >> o;
        if(o == 1){
            int p;
            cin >> p >> a[u] >> c[u];
            d[0][u] = p;
            for(int i = 1; i < 20; i++){
                if(d[i - 1][u] == -1) d[i][u] = -1;
                else d[i][u] = d[i - 1][d[i - 1][u]];
            }
        }
        else{
            int v, w;
            cin >> v >> w;
            int d = lth(v, a);
            ll ans = 0, e = 0;
            for(int i = d; i >= 0; i--){
                int p = par(v, i);
                if(a[p] < w){
                    e += a[p];
                    ans += a[p] * c[p];
                    w -= a[p];
                    a[p] = 0;
                }
                else{
                    e += w;
                    ans += w * c[p];
                    a[p] -= w;
                    w = 0;
                    break;
                }
            }
            cout << e << " " << ans << endl;
        }
    }
}