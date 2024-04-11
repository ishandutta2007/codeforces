#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll t[300005], b[300005];
P p[300005];

int main()
{
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> t[i] >> b[i];
        p[i] = P(b[i], t[i]);
    }
    sort(p, p + n, greater<P>());
    priority_queue<ll, vector<ll>, greater<ll>> que;
    ll st = 0, nb = -1, ans = 0;
    for(int i = 0; i < k; i++){
        que.push(p[i].second);
        nb = p[i].first;
        st += p[i].second;
        ans = max(ans, st * nb);
    }
    for(int i = k; i < n; i++){
        que.push(p[i].second);
        nb = p[i].first;
        st += p[i].second - que.top();
        que.pop();
        ans = max(ans, st * nb);
    }
    cout << ans << endl;
}