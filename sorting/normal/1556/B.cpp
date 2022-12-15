#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<ll> a(n);
        for(ll &x: a){
            cin >> x;
            x &= 1;
        }

        ll cnt[2]{};
        for(ll i = 0; i < n; ++i)
            cnt[a[i]]++;

        const ll INF = 1e18;
        ll ans = INF;
        for(ll i = 0; i <= 1; ++i){
            ll cnt2[2]{};
            cnt2[i] = (n + 1) / 2;
            cnt2[!i] = n / 2;

            if(cnt[0] != cnt2[0] || cnt[0] != cnt2[0])
                continue;

            ll ptr[2], cand = 0;
            ptr[i] = 0;
            ptr[!i] = 1;
            for(ll i = 0; i < n; ++i){
                cand += abs(ptr[a[i]] - i);
                ptr[a[i]] += 2;
            }
            check_min(ans, cand);
        }

        if(ans == INF) ans = -1;
        else ans /= 2;
        cout << ans << "\n";
    }
}