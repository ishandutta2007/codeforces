#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e5 + 7;
const double EPS = 1e-8;
const ll LOGN = 30;
const ll BLOCK = 350;

struct Query {
    ll l, r, id;
};

bool operator<(Query a, Query b) {
    if (a.l / BLOCK != b.l / BLOCK) {
        return a.l < b.l;
    }
    return a.r < b.r;
}

int main() {
    #ifdef MY
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #else
        //freopen(TASKNAME".in", "r", stdin);
        //freopen(TASKNAME".out", "w", stdout);
    #endif // MY
    ll n, m, k;
    cin >> n >> k;
    vector <ll> t(n), a(n + 1, 0);
    for (ll i = 0; i < n; i++) {
        cin >> t[i];
    }
    vector <pair <ll, pair <ll, ll> > > data;
    for (ll i = 0; i < n; i++) {
        ll x;
        cin >> x;
        if (t[i] == 2) {
            x *= -1;
        }
        a[i + 1] = a[i] + x;
        data.push_back({a[i + 1], {1, i + 1}});
        data.push_back({a[i + 1] - k, {2, i + 1}});
        data.push_back({a[i + 1] + k, {3, i + 1}});
    }
    data.push_back({0, {1, 0}});
    //data.push_back({-k, {2, 0}});
    data.push_back({k, {3, 0}});
    sort(data.begin(), data.end());
    ll val = 0;
    vector <ll> val1(n + 1), val2(n + 1), val3(n + 1);
    for (ll i = 0; i < (ll) data.size(); i++) {
        if (!i || data[i].first != data[i - 1].first) {
            val++;
        }
        if (data[i].second.first == 1) {
            val1[data[i].second.second] = val;
        } else if (data[i].second.first == 2) {
            val2[data[i].second.second] = val;
        } else {
            val3[data[i].second.second] = val;
        }
    }
    cin >> m;
    vector <Query> q;
    for (ll i = 0; i < m; i++) {
        ll l, r;
        cin >> l >> r;
        q.push_back({l, r, i});
    }
    sort(q.begin(), q.end());
    ll l = 1, r = 0;
    ll ans = 0;
    vector <ll> cnt1(val + 1, 0), cnt2(val + 1, 0);
    vector <ll> answers(m, 0);
    for (ll i = 0; i < m; i++) {
        auto now = q[i];
        //cout << now.l << " " << now.r << "\n";
        while (l > now.l) {
            l--;
            cnt1[val1[l]]++;
            cnt2[val1[l - 1]]++;
            ans += cnt1[val3[l - 1]];
        }
        while (l < now.l) {
            ans -= cnt1[val3[l - 1]];
            cnt1[val1[l]]--;
            cnt2[val1[l - 1]]--;
            l++;
        }
        while (r < now.r) {
            cnt2[val1[r]]++;
            r++;
            cnt1[val1[r]]++;
            ans += cnt2[val2[r]];
        }
        while (r > now.r) {
            ans -= cnt2[val2[r]];
            cnt1[val1[r]]--;
            r--;
            cnt2[val1[r]]--;
        }
        answers[now.id] = ans;
    }
    for (ll x : answers) {
        cout << x << "\n";
    }
}