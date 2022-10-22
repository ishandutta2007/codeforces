#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const int MAXN = 3e6 + 7;
const double EPS = 1e-8;

struct Query {
    int l, x, id;
};

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
    int n, q;
    cin >> n >> q;
    vector <int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector <int> all;
    vector <bool> can(MAXN, 0);
    can[0] = true;
    all.push_back(0);
    vector <Query> qs;
    for (int i = 0; i < q; i++) {
        int l, x;
        cin >> l >> x;
        qs.push_back({l, x, i});
    }
    sort(qs.begin(), qs.end(), [&](Query a, Query b) {
        return a.l < b.l;
    });
    vector <ll> res(q);
    int now = 0;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        while (now < qs[i].l) {
            if (!can[a[now]]) {
                int sz = (int) all.size();
                for (int j = 0; j < sz; j++) {
                    int x = (all[j] ^ a[now]);
                    can[x] = 1;
                    all.push_back(x);
                }
            } else {
                cnt++;
            }
            now++;
        }
        res[qs[i].id] = (can[qs[i].x] ? power(2, cnt) : 0);
    }
    for (int i = 0; i < q; i++) {
        cout << res[i] << "\n";
    }
}