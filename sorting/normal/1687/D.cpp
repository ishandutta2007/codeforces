#include <bits/stdc++.h>

#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

const ll N = 1e6 + 3;

ll n, a[N];

vector<pair<ll, ll>> curr, nxt;

ll calc_s(ll x){
    ll s = sqrt(x);
    // if(s * s > x)
        // --s;
    // else if((s + 1) * (s + 1) <= x)
        // ++s;
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll k = 0;

    cin >> n;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];

    for(ll i = 1; i <= n; ++i){
        curr.push_back({i, i});
    }

    ll cnt = 0;

    while(true){
        // for(auto [l, r]: curr)
            // cout << l << "," << r < " ";
        // cout << " curr" << endl;

        cnt += curr.size();

        ll prev_k = k;
        for(auto [l, r]: curr){
            // check_max(k, a[r] - a[l]); nothing like this
            // check_max(k, (a[r] - a[l]) * (a[r] - a[l]) - a[l]);
            ll xl = a[l] + k;
            ll xr = a[r] + k;

            ll s = calc_s(xr);
            if(s * s + s < xr)
                k += (s + 1) * (s + 1) - xr;
            xl = a[l] + k;
            if(xl < s * s)
                k += s * s - xl;
        }

        if(prev_k == k)
            break;

        // cout << k << " k" << endl;

        nxt.clear();
        nxt.push_back(curr[0]);

        for(int i = 1; i < curr.size(); ++i){
            ll xl = a[curr[i].first] + k;
            ll xr = a[curr[i - 1].second] + k;

            ll s = calc_s(xr);
            if(xl - xr <= s){
                nxt.back().second = curr[i].second;
            }
            else
                nxt.push_back(curr[i]);
        }
        swap(curr, nxt);
    }

    assert(cnt <= 4 * max(n, a[n]));

    cout << k << "\n";
}