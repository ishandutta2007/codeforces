#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

int main()
{
    int n, k;
    cin >> n >> k;
    ll a[100005];
    for(int i = 0; i < n; i++) scanf("%lld", &a[i]);
    ll d[100005];
    priority_queue<P> que;
    ll ans = 0;
    for(int i = 0; i < n; i++){
        d[i] = 1;
        ans += a[i] * a[i];
        que.push(P(a[i] * a[i] - ((a[i] / 2) * (a[i] / 2) + ((a[i] + 1) / 2) * ((a[i] + 1) / 2)), i));
    }
    for(int c = 0; c < k - n; c++){
        P p = que.top();
        que.pop();
        ans -= p.first;
        int i = p.second;
        d[i]++;
        ll s = (a[i] / d[i]) * (a[i] / d[i]) * (d[i] - a[i] % d[i]) +
            (a[i] / d[i] + 1) * (a[i] / d[i] + 1) * (a[i] % d[i]);
        ll t = (a[i] / (d[i] + 1)) * (a[i] / (d[i] + 1)) * ((d[i] + 1) - a[i] % (d[i] + 1)) +
            (a[i] / (d[i] + 1) + 1) * (a[i] / (d[i] + 1) + 1) * (a[i] % (d[i] + 1));
        que.push(P(s - t, i));
    }
    printf("%lld\n", ans);
}