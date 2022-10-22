#include <bits/stdc++.h>
#define ll long long
#define TASKNAME ""

using namespace std;

const int INF = 1e9 + 7;
const int MAXN = 1e6 + 7;
const double EPS = 1e-6;

ll n, k, a, b;

ll rec(ll l, ll r, vector <ll> &all) {
    if (!all.size()) {
        return a;
    }
    if (r - l == 1) {
        return b * all.size();
    }
    ll mid = (l + r) / 2;
    vector <ll> lt, rt;
    for (ll x : all) {
        if (x < mid) {
            lt.push_back(x);
        } else {
            rt.push_back(x);
        }
    }
    if (!lt.size()) {
        return min(b * (r - l) * all.size(), rec(mid, r, rt) + a);
    }
    if (!rt.size()) {
        return min(b * (r - l) * all.size(), rec(l, mid, lt) + a);
    }
    ll res = rec(l, mid, lt) + rec(mid, r, rt);
    //cout << l << " " << r << " " << res << "\n";
    return res;
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
    cin >> n >> k >> a >> b;
    vector <ll> mas(k);
    for (ll i = 0; i < k; i++) {
        cin >> mas[i];
        mas[i]--;
    }
    sort(mas.begin(), mas.end());
    cout << rec(0, 1LL << n, mas);
}