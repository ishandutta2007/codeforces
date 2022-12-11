#include <bits/stdc++.h>
using namespace std;
bool D = false;
const int INF = (int)1e9 + 34;
typedef long long ll;
const ll MD = (ll)1e9 + 7;

void add(ll &a, ll b) {
    a += b;
    if (a >= MD) a -= MD;
}

void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<ll> a0(n + 1, 0), a1(n + 1, 0);
    vector<ll> ab0(n + 1, 0), ab1(n + 1, 0), ab2(n + 1, 0);

    vector<ll> deg3(n + 1, 1);
    for (int i = 1; i <= n; i++)
        deg3[i] = deg3[i - 1] * 3 % MD;

    ll ans = 0;
    int numQ = count(s.begin(), s.end(), '?');

    auto addToAns = [&](ll value, int usedQ) {
        ans = (ans + value * deg3[numQ - usedQ]) % MD;
    };

    for (int i = 0; i < n; i++) {
        a0[i + 1] = a0[i], a1[i + 1] = a1[i];
        ab0[i + 1] = ab0[i], ab1[i + 1] = ab1[i], ab2[i + 1] = ab2[i];

        if (s[i] == 'a') add(a0[i + 1], 1);
        if (s[i] == 'b') {
            add(ab0[i + 1], a0[i]);
            add(ab1[i + 1], a1[i]);
        }
        if (s[i] == 'c') {
            addToAns(ab0[i], 0);
            addToAns(ab1[i], 1);
            addToAns(ab2[i], 2);
        }
        if (s[i] == '?') {
            addToAns(ab2[i], 3);
            addToAns(ab1[i], 2);
            addToAns(ab0[i], 1);
            add(ab2[i + 1], a1[i]);
            add(ab1[i + 1], a0[i]);
            add(a1[i + 1], 1);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
#ifdef SERT
    freopen("a.in", "r", stdin);
    D = true;
    t = 4;
#else

#endif
    while (t--) {
        solve();
    }
}