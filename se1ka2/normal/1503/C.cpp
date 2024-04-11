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
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ll a, c;
        cin >> a >> c;
        p[i] = P(a, c);
        ans += c;
    }
    sort(p, p + n);
    ll l = p[0].first + p[0].second;
    for(int i = 1; i < n; i++){
        ans += max(0ll, p[i].first - l);
        l = max(l, p[i].first + p[i].second);
    }
    cout << ans << endl;
}