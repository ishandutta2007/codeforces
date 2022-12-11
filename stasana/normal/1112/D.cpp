// Megumin top

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <set>

using namespace std;

typedef int64_t ll;

inline void start() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
}

struct Node {
    vector<ll> next;
    ll link;
    ll par;

    Node() {
        next.resize(26, -1);
        link = par = -1;
    }
};

vector<Node> af(1);

ll add(ll a, char ch) {
    ll b = af.size();
    af.emplace_back();
    af[b].par = a;
    af[b].link = 0;
    while (a != -1) {
        if (af[a].next[ch - 'a'] == -1) {
            af[a].next[ch - 'a'] = b;
            a = af[a].link;
            continue;
        }
        ll c = af[a].next[ch - 'a'];
        if (af[c].par == a) {
            af[b].link = c;
            break;
        }
        ll d = af.size();
        af.emplace_back();
        af[d].link = af[c].link;
        af[d].next = af[c].next;
        af[d].par = a;
        af[c].link = d;
        af[b].link = d;
        while (a != -1 && af[a].next[ch - 'a'] == c) {
            af[a].next[ch - 'a'] = d;
            a = af[a].link;
        }
        break;
    }
    return b;
}

ll read(string& s, ll i) {
    ll v = 0;
    ll result = 0;
    for (; i < s.length(); ++i) {
        if (af[v].next[s[i] - 'a'] == -1) {
            break;
        }
        v = af[v].next[s[i] - 'a'];
        ++result;
    }
    return result;
}

inline void solve() {
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;
    vector<ll> c(n);
    ll v = 0;
    for (ll i = 0; i < n; ++i) {
        c[i] = read(s, i);
        v = add(v, s[i]);
    }
    vector<ll> dp(n, 1e17);
    dp[0] = a;
    for (ll i = 1; i < n; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + a);
        for (ll j = i; j < i + c[i]; ++j) {
            dp[j] = min(dp[j], dp[i - 1] + b);
        }
    }

    cout << dp[n - 1] << endl;
}

int32_t main() {
    start();
    solve();
    return 0;
}