#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, int> PP;

const ll MOD = 1000000007;

int main()
{
    int n;
    cin >> n;
    PP pout[200005], pin[200005];
    int l[200005];
    for(int i = 1; i <= n; i++){
        int out, in;
        cin >> out >> in;
        l[i] = in;
        pout[i] = PP(P(out, in), i);
        pin[i] = PP(P(in, out), i);
    }
    l[0] = 0;
    pout[0] = PP(P(0, 0), 0);
    pin[0] = PP(P(0, 0), 0);
    l[n + 1] = MOD;
    pout[n + 1] = PP(P(MOD, MOD), MOD);
    pin[n + 1] = PP(P(MOD, MOD), MOD);
    sort(pout, pout + n + 1);
    sort(pin, pin + n + 1);
    ll dp[200005] {0};
    dp[0] = 1;
    int j = 0;
    int d = 0;
    ll s = 0;
    for(int i = 1; i <= n; i++){
        d += pin[i].first.first - pin[i - 1].first.first;
        for(; pout[j].first.first <= pin[i].first.first; j++){
            if(pin[i].first.first - pout[j].first.first + l[pout[j].second] < d){
                d = pin[i].first.first - pout[j].first.first + l[pout[j].second];
                s = dp[pout[j].second];
            }
            else if(pin[i].first.first - pout[j].first.first + l[pout[j].second] == d)
                s = (s + dp[pout[j].second]) % MOD;
        }
        dp[pin[i].second] = s;
        l[pin[i].second] -= pin[i].first.first - d;
    }
    int les = MOD;
    for(int i = 1; i <= n; i++){
        if(pout[i].first.first > pin[n].first.first) les = min(les, l[pout[i].second]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) if(pout[i].first.first > pin[n].first.first && l[pout[i].second] == les)
        ans = (ans + dp[pout[i].second]) % MOD;
    cout << ans << endl;
}