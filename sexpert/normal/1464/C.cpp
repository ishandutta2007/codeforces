#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll INF = 1e18;

bool f(int ps, ll req, vector<ll> &cnt) {
    if(ps == -1 || req > INF)
        return false;
    if(cnt[ps] >= req) {
        cnt[ps] -= req;
        return true;
    }
    req -= cnt[ps];
    cnt[ps] = 0;
    return f(ps - 1, 2*req, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int n;
    ll T;
    cin >> n >> T;

    string s;
    cin >> s;

    vector<ll> guys;
    for(int i = 0; i < n; i++)
        guys.push_back(1LL << (s[i] - 'a'));

    if(n == 1) {
        cout << ((guys[0] == T) ? "Yes" : "No") << '\n';
        return 0;
    }
    if(n == 2) {
        cout << ((guys[1] - guys[0] == T) ? "Yes" : "No") << '\n';
        return 0;
    }
    ll tot = guys[n - 1];
    for(int i = 0; i < n - 1; i++)
        tot -= guys[i];

    if(tot > T || (abs(tot) % 2 != abs(T) % 2)) {
        cout << "No\n";
        return 0;
    }
    ll rem = (T - tot) / 2LL;
    assert(rem >= 0);
    vector<ll> cnt(70, 0);
    for(int i = 0; i < n - 2; i++)
        cnt[(s[i] - 'a')]++;
    for(ll b = 59; b >= 0; b--) {
        if(!(rem & (1LL << b)))
            continue;
        if(!f(b, 1, cnt)) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";
}