#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;
const ll Q = 31;

ll power(ll a, ll k) {
    if (!k) {
        return 1;
    }
    ll b = power(a, k / 2);
    b = b * b % INF;
    if (k % 2) {
        return a * b % INF;
    } else {
        return b;
    }
}

ll rev(ll a) {
    return power(a, INF - 2);
}

vector <ll> f, rf;

void init() {
    f.resize(MAXN, 0);
    rf.resize(MAXN, 0);
    f[0] = 1;
    for (ll i = 1; i < MAXN; i++) {
        f[i] = f[i - 1] * i % INF;
    }
    for (ll i = 0; i < MAXN; i++) {
        rf[i] = rev(f[i]);
    }
}

inline ll C(ll k, ll n) {
    if (k < 0 || k > n) return 0;
    return f[n] * rf[k] % INF * rf[n - k] % INF;
}

string a, b;

inline ll get_ans(string &s) {
    ll ans = 1;
    ll n = s.size();
    vector <ll> cnt(Q, 0);
    for (char c : a) {
        cnt[c - 'a']++;
    }
    for (ll i = 0; i < n; i++) {
        ll all = n - i - 1;
        ll ans1 = 0, ans2 = 1;
        for (ll j = Q - 1; j >= 0; j--) {
            if (!cnt[j]) continue;
            if (j >= s[i] - 'a') {
                ans2 *= C(cnt[j], all);
                ans2 %= INF;
                all -= cnt[j];
                continue;
            }
            ans1 *= C(cnt[j], all + 1);
            ans1 += ans2 * C(cnt[j] - 1, all);
            ans1 %= INF;
            ans2 *= C(cnt[j], all);
            ans2 %= INF;
            all -= cnt[j];
        }
        ans += ans1;
        ans %= INF;
        cnt[s[i] - 'a']--;
    }
    return ans;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
    #endif // MY
    init();
    cin >> a >> b;
    cout << (get_ans(b) - get_ans(a) - 1 + 2 * INF) % INF;
}