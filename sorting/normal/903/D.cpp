#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef long long ll;
template<class T> void check_min(T &a, const T &b){ a = (a < b) ? a : b; }
template<class T> void check_max(T &a, const T &b){ a = (a > b) ? a : b; }
#define all(x) (x).begin(), (x).end()

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin >> n;

    vector<int> a(n);
    for(auto &x: a)
        cin >> x;
    
    ld sum = 0, ans = 0;
    map<ld, pair<ld, ld>> cnt;
    for(ll i = 0; i < a.size(); ++i){
        pair<ll, ll> p = cnt[a[i]];
        p.first += cnt[a[i] - 1].first;
        p.second += cnt[a[i] - 1].second;
        p.first += cnt[a[i] + 1].first;
        p.second += cnt[a[i] + 1].second;

        // cout << sum << " - " << p.first << " " << p.second << endl;
        // cout << (sum - p.first) - a[i] * (i - p.second) << endl;
        ans -= (sum - p.first) - a[i] * (i - p.second);

        cnt[a[i]].first += a[i];
        cnt[a[i]].second += 1;
        sum += a[i];
    }
    cout << fixed << setprecision(0) << ans << "\n";
}