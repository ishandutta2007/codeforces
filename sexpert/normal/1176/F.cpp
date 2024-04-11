#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const ll INF = 1e18;
const int MAXN = 2e5 + 5;
ll dp[MAXN][10];
vector<ll> cards[4];
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    int n;
    cin >> n;
 
    dp[0][0] = 0;
    for(int i = 1; i <= 9; i++)
        dp[0][i] = -INF;
 
    for(int t = 1; t <= n; t++) {
        for(int i = 0; i < 10; i++)
            dp[t][i] = dp[t - 1][i];
 
        int num;
        cin >> num;
        cards[1].clear();
        cards[2].clear();
        cards[3].clear();
        while(num--) {
            int c;
            ll d;
            cin >> c >> d;
            cards[c].push_back(d);
        }
        for(int i = 1; i <= 3; i++) sort(cards[i].rbegin(), cards[i].rend());
 
        // take 1 card
        for(int i = 0; i < 10; i++) {
            int pre = i - 1;
            if(pre < 0) pre += 10;
            ll be = 0;
            for(int j = 1; j <= 3; j++)
                if(cards[j].size()) be = max(be, cards[j][0]);
            if(i > 0)
                dp[t][i] = max(dp[t][i], dp[t - 1][pre] + be);
            else
                dp[t][i] = max(dp[t][i], dp[t - 1][pre] + 2ll*be);
        }
 
        // take 2 cards
        for(int i = 0; i < 10; i++) {
            int pre = i - 2;
            if(pre < 0) pre += 10;
            // 2x cost 1
            if(cards[1].size() >= 2) {
                if(i > 1)
                    dp[t][i] = max(dp[t][i], dp[t - 1][pre] + cards[1][0] + cards[1][1]);
                else
                    dp[t][i] = max(dp[t][i], dp[t - 1][pre] + 2ll*cards[1][0] + cards[1][1]);
            }
            // cost 1 and cost 2
            if(cards[1].size() && cards[2].size()) {
                ll a = cards[1][0], b = cards[2][0];
                int pre = i - 2;
                if(pre < 0) pre += 10;
                if(a < b) swap(a, b);
                if(i > 1)
                    dp[t][i] = max(dp[t][i], dp[t - 1][pre] + a + b);
                else
                    dp[t][i] = max(dp[t][i], dp[t - 1][pre] + a + a + b);
            }
        }
        // take 3 cards
        for(int i = 0; i < 10; i++) {
            int pre = i - 3;
            if(pre < 0) pre += 10;
            if(cards[1].size() >= 3) {
                ll su = cards[1][0] + cards[1][1] + cards[1][2], be = max({cards[1][0], cards[1][1], cards[1][2]});
                if(i > 2)
                    dp[t][i] = max(dp[t][i], dp[t - 1][pre] + su);
                else
                    dp[t][i] = max(dp[t][i], dp[t - 1][pre] + su + be);
            }
        }
    }
    ll mx = 0;
    for(int i = 0; i < 10; i++)
        mx = max(mx, dp[n][i]);
    cout << mx << '\n';
}