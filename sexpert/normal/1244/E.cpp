#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    ll k;
    cin >> n >> k;
    vector<int> v(n);
    for(auto &x : v)
        cin >> x;
    map<int, int> cnt;
    for(auto x : v)
        cnt[x]++;
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    int l = 0, r = v.size() - 1, rl = v[l], rr = v[r];
    while(l < r && k > 0) {
        ll cl = cnt[v[l]], cr = cnt[v[r]];
        if(cl < cr) {
            ll di = v[l + 1] - v[l];
            if(cl * di <= k) {
                rl = v[l + 1];
                cnt[v[l + 1]] += cnt[v[l]];
                l++;
                k -= cl * di;
            }
            else {
                ll mov = k/cl;
                rl += mov;
                break;
            }
        }
        else {
            ll di = v[r] - v[r - 1];
            if(cr * di <= k) {
                rr = v[r - 1];
                cnt[v[r - 1]] += cnt[v[r]];
                r--;
                k -= cr * di;
            }
            else {
                ll mov = k / cr;
                rr -= mov;
                break;
            }
        }
    }
    cout << rr - rl << '\n';
}