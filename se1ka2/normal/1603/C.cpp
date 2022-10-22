#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<P, ll> PP;

const ll MOD = 998244353;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int a[100005];
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<PP> cp, dp;
        ll ans = 0;
        for(int i = n - 1; i >= 0; i--){
            vector<P> p;
            for(int j = 1; j <= a[i]; j++){
                if(p.size() && p.back().first == (a[i] - 1) / j + 1) break;
                p.push_back(P((a[i] - 1) / j + 1, j));
            }
            while(p.back().first > 1){
                int x = p.back().first - 1;
                p.push_back(P(x, (a[i] - 1) / x + 1));
            }
            vector<PP> c, d;
            int k = 0;
            for(int j = 0; j < (int)p.size(); j++){
                c.push_back(PP(p[j], 0));
                if(j == 0) c[j].second++;
                d.push_back(PP(p[j], 0));
                while(k < (int)dp.size()){
                    P q = dp[k].first;
                    ll y;
                    if(q.first * q.second == a[i + 1]) y = q.first;
                    else y = q.first - 1;
                    if(p[j].first > y) break;
                    c[j].second = (c[j].second + cp[k].second) % MOD;
                    d[j].second = (d[j].second + dp[k].second + cp[k].second * (p[j].second - 1)) % MOD;
                    k++;
                }
            }
            swap(cp, c);
            swap(dp, d);
            for(PP p : dp) ans = (ans + p.second) % MOD;
        }
        cout << ans << endl;
    }
}