#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz = 1e4+7;

int n, m, g, r;
int stp[sz], dp[sz][1003];
deque < pair <int,int> > dq;

void add(int pos, int light, int w)
{
    if(light < 0) return;
    if(!light) light = g, w++;
    if(dp[pos][light] < 0) {
        dp[pos][light] = w;
        if(light < g) dq.push_front({pos, light});
        else dq.push_back({pos, light});
    }
}

ll fnc()
{
    dp[1][g] = 0;
    dq.push_back({1, g});
    while(!dq.empty()) {
        auto now = dq.front(); dq.pop_front();
        int pos = now.first, light = now.second, w = dp[pos][light];

        if(pos > 1) add(pos - 1, light - stp[pos] + stp[pos - 1], w);
        if(pos < m-1) add(pos + 1, light - stp[pos + 1] + stp[pos], w);
    }

    ll ans = 1e18;
    for(int i=1; i<m; i++) {
        if(dp[i][g] < 0 || n - stp[i] > g) continue;
        ans = min(ans, 1LL * (g + r) * dp[i][g] + n - stp[i]);
    }
    if(ans == 1e18) ans = -1;
    return ans;
}

int main()
{
    cin >> n >> m;
    for(int i=1; i<=m; i++) scanf("%d", &stp[i]);
    sort(stp + 1, stp + m + 1);
    cin >> g >> r;
    memset(dp, -1, sizeof(dp));
    cout << fnc();
}