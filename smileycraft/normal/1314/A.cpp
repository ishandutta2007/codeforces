
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpll = vector<pll>;
using vvll = vector<vll>;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(13);
    ll n;
    cin >> n;
    vll a(n), t(n);
    for (ll i = 0; i < n; ++i) cin >> a[i];
    for (ll i = 0; i < n; ++i) cin >> t[i];
    vll is(n);
    for (ll i = 0; i < n; ++i) is[i] = i;
    sort(is.begin(), is.end(), [&](ll i1, ll i2){return a[i1] < a[i2];});
    priority_queue<ll> q;
    ll total = 0, current = 0, last_a = -1000000000;
    for (ll ii = 0; ; ++ii){
        ll current_a = ii == n ? 2000000000 : a[is[ii]];
        while (last_a < current_a){
            if (q.empty()){
                last_a = current_a;
                break;
            }
            else{
                current -= q.top();
                q.pop();
                total += current;
                ++last_a;
            }
        }
        if (ii == n) break;
        current += t[is[ii]];
        q.push(t[is[ii]]);
        while (ii + 1 < n && a[is[ii + 1]] == current_a){
            ++ii;
            current += t[is[ii]];
            q.push(t[is[ii]]);
        }
    }
    cout << total << endl;
    return 0;
}