#include <iostream>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;
    ll l[2002], r[2002];
    for(int i = 0; i < m; i++){
        cin >> l[i] >> r[i];
        l[i]--;
    }
    ll ans = 0;
    for(ll x = 0; x + k <= n; x++){
        ll s = 0;
        ll c = 0;
        int d[2002]{0};
        for(int i = 0; i < m; i++){
            if(r[i] <= x) continue;
            else if(r[i] <= x + k) s += r[i] - max(x, l[i]);
            else if(l[i] <= x) s += k;
            else if(l[i] <= x + k){
                s += x + k - l[i];
                c++;
                d[r[i] - k]--;
                d[l[i]]--;
                d[r[i] + l[i] - x - k]++;
            }
            else{
                d[l[i] - k]++;
                d[r[i] - k]--;
                d[l[i]]--;
                d[r[i]]++;
            }
        }
        for(ll y = x; y + k <= n; y++){
            ans = max(ans, s);
            c += d[y];
            s += c;
        }
    }
    cout << ans << endl;
}