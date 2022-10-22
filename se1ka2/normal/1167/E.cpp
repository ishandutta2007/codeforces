#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll a[1000002];
P p[1000002];
P q[1000002];

int main()
{
    ll n, x;
    cin >> n >> x;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i);
    }
    sort(p, p + n);
    p[n] = P(100000000, 100000000);
    int d;
    for(d = 1; d < n; d++) if(p[d].second < p[d - 1].second) break;
    if(d == n){
        cout << x * (x + 1) / 2 << endl;
        return 0;
    }
    int u;
    for(u = n - 1; u >= 0; u--) if(p[u - 1].second > p[u].second) break;
    for(int i = 0; i < n; i++) q[i] = P(-1, -1);
    for(int i = u; i < n; i++) q[i] = P(p[i].second, p[i].first);
    sort(q, q + n);
    q[n] = P(100000000, 100000000);
    ll t = p[u - 1].first;
    ll ans = 0;
    int j = 0;
    for(int i = 1; i <= x; i++){
        ans += x - t + 1;
        if(i == p[d].first) break;
        while(i >= p[j].first){
            t = lower_bound(q, q + n, P(p[j].second, 0)) -> second;
            t = (lower_bound(p, p + n, P(t, p[j].second)) - 1) -> first;
            j++;
        }
    }
    cout << ans << endl;
}