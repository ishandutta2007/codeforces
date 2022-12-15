#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll INF = 1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    while(t--){
        ll n;
        cin >> n;

        vector<array<ll, 3>> v(n);
        for(ll i = 0; i < n; ++i)
            cin >> v[i][0] >> v[i][1] >> v[i][2];

        ll ch_l = 0, ch_r = 0, l = INF, r = -INF;
        ll ch_both = 0;
        for(ll i = 0; i < n; ++i){
            if(l > v[i][0]){
                l = v[i][0];
                ch_both = INF;
                ch_l = INF;
            }
            if(r < v[i][1]){
                r = v[i][1];
                ch_r = INF;
                ch_both = INF;
            }

            if(l == v[i][0]) check_min(ch_l, v[i][2]);
            if(r == v[i][1]) check_min(ch_r, v[i][2]);
            if(l == v[i][0] && r == v[i][1]) check_min(ch_both, v[i][2]);

            cout << min(ch_l + ch_r, ch_both) << "\n";
       }
    }
}