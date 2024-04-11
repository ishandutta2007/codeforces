#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(ll i = 0; i < n; ++i)
            cin >> a[i];

        ll x;
        cin >> x;
        for(ll i = 0; i < n; ++i)
            a[i] -= x;

        vector<ll> r(n + 1), suffix(n + 1);
        suffix[n] = 0;
        for(ll i = n - 1; i >= 0; --i)
            suffix[i] = suffix[i + 1] + a[i];

        r[n - 1] = n - 1;
        priority_queue<pair<ll, ll>> pq;
        for(ll i = n - 2; i >= 0; --i){
            r[i] = r[i + 1];

            pq.push({suffix[i + 2], i + 2});
            while(!pq.empty() && suffix[i] < pq.top().first){
                auto [val, idx] = pq.top();
                pq.pop();
                if(idx > r[i] + 1)
                    continue;

                r[i] = idx - 2;
            }
        }

        vector<ll> dp(n + 1);
        dp[n] = 0;
        dp[n - 1] = 0;
        for(int i = n - 2; i >= 0; --i){
            if(r[i] == n - 1)
                dp[i] = 0;
            else
                dp[i] = dp[r[i] + 2] + 1;
        }

        cout << n - dp[0] << "\n";
    }
}