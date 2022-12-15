#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()  

const ll N = 2e5 + 3;
const ll INF = 1e18;

ll a[N], pos[N], n, m;
ll dp[N][2];
pair<ll, ll> r[N];
vector<pair<ll, ll>> new_r;

void solve(){
    cin >> n >> m;
    for(ll i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    a[0] = -INF;
    ++n;

    for(ll i = 0; i < m; ++i)
        cin >> r[i].first >> r[i].second;
    sort(r, r + m, [&](auto lval, auto rval){
        if(lval.first == rval.first)
            return lval.second > rval.second;
        return lval.first < rval.first;
    });

    new_r.clear();
    for(ll i = 0; i < m; ++i){
        if(lower_bound(a, a + n, r[i].first) != upper_bound(a, a + n, r[i].second))
            continue;
        while(!new_r.empty() && r[i].second <= new_r.back().second)
            new_r.pop_back();
        new_r.push_back(r[i]);
    }

    if(new_r.empty()){
        cout << "0\n";
        return;
    }
    m = new_r.size();   

    for(ll i = n - 1; i >= 0; --i)
        pos[i] = lower_bound(new_r.begin(), new_r.end(), pair{a[i], 0ll}) - new_r.begin();

    vector<ll> new_a, new_pos;
    for(ll i = 0; i < n; ++i){
        if(i && i != n - 1 && pos[i - 1] == pos[i] && pos[i] == pos[i + 1]) continue;
        new_a.push_back(a[i]);
        new_pos.push_back(pos[i]);
    }

    n = new_a.size();
    for(int i = 0; i < n; ++i){
        a[i] = new_a[i];
        pos[i] = new_pos[i];
    }

    ll mn1[2]{INF, INF}, mn2[2]{INF, INF};
    for(ll i = n - 1; i >= 0; --i){
        for(ll dir = 0; dir <= 1; ++dir){
            auto &ans = dp[i][dir];
            if(pos[i] != m)
                ans = (dir + 1) * (new_r.back().first - a[i]);
            else{
                ans = 0;
                continue;
            }

            if(i == n - 1) continue;

            for(ll j = i + 1; j <= min(n - 1, i + 2); ++j){
                for(ll dir2 = 0; dir2 <= 1; ++dir2){
                    auto nxt = dp[j][dir2];
                    if(pos[i] == pos[j]){
                        check_min(ans, nxt);
                        continue;
                    }

                    check_min(ans, nxt + (!dir2 + 1) * (a[j] - new_r[pos[i]].second));
                    check_min(ans, nxt + (dir + 1) * (new_r[pos[j] - 1].first - a[i]));

                    for(ll k = pos[i]; k <= pos[j] - 2; ++k)
                        check_min(ans, nxt + (!dir2 + 1) * (a[j] - new_r[k + 1].second) + (dir + 1) * (new_r[k].first - a[i]));
                }
            }
        }
    }

    //cout << dp[0][0] << " " << dp[0][1] << endl;
    cout << min(dp[0][0], dp[0][1]) << "\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;

    for(ll i = 1; i <= t; ++i)
        solve();
}