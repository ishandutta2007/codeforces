#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<ll, int> P;

const ll INF = 10000000000000000;

P p[200005];
ll s[200005];
bool b[200005];

int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        ll a;
        cin >> a;
        p[i] = P(a, i);
    }
    sort(p, p + n, greater<P>());
    for(int i = 0; i < n; i++) s[0] += -p[i].first;
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + p[i - 1].first * 2;
    if(n % 2){
        for(int i = 0; i <= n / 2; i++) b[p[i].second] = true;
    }
    bool f = true;
    for(int i = 0; i < n; i += 2) f &= b[i];
    if(f && n > 1) s[n / 2 + 1] = s[n / 2 + 1] - p[n / 2].first * 2 + p[n / 2 + 1].first * 2;
    ll ans = -INF;
    int i = (n * 2 - 1) % 3;
    for(; i <= n; i += 3) ans = max(ans, s[i]);
    cout << ans << endl;
}