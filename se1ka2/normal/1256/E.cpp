#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;

ll a[200002];
P p[200002];
ll pre[200002];
ll s[200002];
ll dp[200002];
ll ans[200002];

int main()
{
    ll n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i);
    }
    sort(p, p + n, greater<P>());
    fill(dp, dp + n + 1, 100000000000000000);
    dp[0] = 0;
    s[0] = 0;
    for(int i = 3; i <= n; i++){
        ll num = -1;
        for(int j = 3; j <= 5; j++){
            if(j > i) continue;
            if(dp[i - j] + p[i - j].first - p[i - 1].first < dp[i]){
                num = j;
                dp[i] = dp[i - j] + p[i - j].first - p[i - 1].first;
            }
        }
        pre[i] = num;
        s[i] = s[i - num] + 1;
    }
    cout << dp[n] << " " << s[n] << endl;
    ll l = 1;
    ll now = n;
    while(now > 0){
        for(int i = pre[now]; i > 0; i--){
            ans[p[now - i].second] = l;
        }
        l++;
        now -= pre[now];
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;
}