#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll h[200005], d[200005];
P p[200005];
bool f[200005];

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    for(int i = 0; i < n; i++){
        cin >> h[i] >> d[i];
        p[i] = P(h[i] - d[i], i);
    }
    sort(p, p + n, greater<P>());
    for(int i = 0; i < b; i++){
        if(p[i].first <= 0) break;
        f[p[i].second] = true;
    }
    ll s = 0;
    for(int i = 0; i < n; i++){
        if(f[i]) s += h[i];
        else s += d[i];
    }
    if(b == 0){
        cout << s << endl;
        return 0;
    }
    int r = -1;
    if(p[b - 1].first > 0) r = p[b - 1].second;
    ll m = 1;
    for(int i = 0; i < a; i++) m *= 2;
    ll ans = s;
    for(int i = 0; i < n; i++){
        ll x = s;
        if(f[i]){
            x -= h[i];
            x += h[i] * m;
        }
        else if(r == -1){
            x -= d[i];
            x += h[i] * m;
        }
        else{
            x -= h[r];
            x += d[r];
            x -= d[i];
            x += h[i] * m;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}