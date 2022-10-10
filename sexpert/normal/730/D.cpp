#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pos, curt, rem, r, k;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n >> r;
    vector<ll> l(n), t(n);
    for(auto &x : l) {
        cin >> x;
        x *= 2;
    }
    for(auto &x : t)
        cin >> x;
    for(int i = 0; i < n; i++) {
        if(t[i] < l[i] / 2) {
            cout << "-1\n";
            return 0;
        }
    }
    vector<ll> ans;
    for(int i = 0; i < n; i++) {
        if(t[i] + rem >= l[i]) {
            ll tirq = max(l[i]/2, l[i] - rem);
            curt += tirq;
            rem = max(0ll, rem - tirq);
            continue;
        }
        ll pot = (l[i] - (t[i] + rem) + r - 1) / r;
        k += pot;
        ll ptime = min(l[i] - t[i], t[i]);
        ll nptime = l[i] - 2 * ptime;
        for(ll i = 0; i < pot; i++) {
            if(ans.size() > 100000)
                break;
            ans.push_back(curt + rem + nptime + r * i);
        }
        rem = rem + pot * r - ptime;
        curt += l[i] - ptime;
    }
    cout << k << '\n';
    if(ans.size() <= 100000) {
        for(auto x : ans)
            cout << x << " ";
        cout << '\n';
    }
}