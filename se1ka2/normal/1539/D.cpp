#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    int n;
    cin >> n;
    P p[100005];
    for(int i = 0; i < n; i++){
        ll a, b;
        cin >> a >> b;
        p[i] = P(b, a);
    }
    sort(p, p + n);
    ll ans = 0, c = 0;
    for(int i = 0; i < n; i++){
        ll d = max(0ll, p[i].first - c);
        while(p[n - 1].second <= d && n > i + 1){
            c += p[n - 1].second;
            ans += p[n - 1].second * 2;
            d -= p[n - 1].second;
            n--;
        }
        ll e = min(d, p[n - 1].second);
        c += e;
        ans += e * 2;
        p[n - 1].second -= e;
        c += p[i].second;
        ans += p[i].second;
    }
    cout << ans << endl;
}