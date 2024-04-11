#include <bits/stdc++.h>
#define ll long long

#define TASKNAME ""

using namespace std;

const ll INF = 1e9 + 7;
const ll MAXN = 1e6 + 7;
const double EPS = 1e-8;

map <ll, ll> win;
map <ll, ll> cnt;

ll getH(vector <ll> &a) {
    ll res = 0;
    for (ll x : a) {
        res = res * 9 + x;
    }
    return res;
}

vector <ll> getV(ll h) {
    vector <ll> a;
    for (ll i = 0; i < 5; i++) {
        a.push_back(h % 9);
        h /= 9;
    }
    reverse(a.begin(), a.end());
    return a;
}

ll g(ll a, ll b, ll t) {
    return a * INF + b * 2 + t;
}

int iter = 0;

void go(ll a, ll b, ll t) {
    iter++;
    //cout << iter << "\n";
    auto av = getV(a), bv = getV(b);
    if (!t) {
        swap(av, bv);
    }
    for (ll i = 0; i < 5; i++) {
        for (ll j = 1; j < 5; j++) {
            if (!av[i] || !bv[j] || i == j) continue;
            av[i]--;
            av[(i - j + 5) % 5]++;
            ll h1 = getH(av), h2 = getH(bv);
            if (!t) {
                swap(h1, h2);
            }
            ll gn = g(h1, h2, t ^ 1);
            ll gp = g(a, b, t);
            //cout << gn << " " << gp << "\n";
            if (win.count(gn) > 0) {
                av[i]++;
                av[(i - j + 5) % 5]--;
                continue;
            }
            if (win[gp] == (t + 1) % 2 + 1) {
                win[gn] = (t + 1) % 2 + 1;
                go(h1, h2, (t + 1) % 2);
            } else {
                cnt[gn]--;
                if (!cnt[gn]) {
                    win[gn] = t + 1;
                    go(h1, h2, (t + 1) % 2);
                }
            }
            av[i]++;
            av[(i - j + 5) % 5]--;
        }
    }
}


vector <ll> all;

void force(vector <ll> &a, ll cnt, ll now) {
    if (now == 4) {
        a[now] = 8 - cnt;
        all.push_back(getH(a));
        return;
    }
    for (ll i = 0; i <= 8 - cnt; i++) {
        a[now] = i;
        force(a, cnt + i, now + 1);
    }
}

void init() {
    vector <ll> a(5, 0);
    force(a, 0, 0);
    //cout << all.size() << "\n";
    for (ll i = 0; i < (ll) all.size(); i++) {
        for (ll j = 0; j < (ll) all.size(); j++) {
            auto a = getV(all[i]), b = getV(all[j]);
            for (ll ida = 1; ida < 5; ida++) {
                for (ll idb = 1; idb < 5; idb++) {
                    if (!a[ida] || !b[idb]) continue;
                    cnt[g(all[i], all[j], 0)]++;
                    cnt[g(all[i], all[j], 1)]++;
                }
            }
        }
    }
    //cout << all.back() << "\n";
    //cout << (all.size() - 1) * 4 << "\n";
    for (ll i = 0; i < (ll) all.size() - 1; i++) {
        //win[g(all.back(), all[i], 0)] = 1;
        win[g(all.back(), all[i], 1)] = 1;
        win[g(all[i], all.back(), 0)] = 2;
        //win[g(all[i], all.back(), 1)] = 2;
    }
    for (ll i = 0; i < (ll) all.size() - 1; i++) {
        //go(all.back(), all[i], 0);
        go(all.back(), all[i], 1);
        go(all[i], all.back(), 0);
        //go(all[i], all.back(), 1);
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
    init();
    ll tz;
    cin >> tz;
    //cout << "kek\n";
    //cout << iter << "\n";
    for (ll id = 0; id < tz; id++) {
        vector <ll> a(5, 0), b(5, 0);
        ll t;
        cin >> t;
        for (ll i = 0; i < 8; i++) {
            ll x;
            cin >> x;
            a[x]++;
        }
        for (ll j = 0; j < 8; j++) {
            ll x;
            cin >> x;
            b[x]++;
        }
        ll h1 = getH(a), h2 = getH(b);
        ll gn = g(h1, h2, t);
        //cout << h1 << " " << h2 << " " << t << "\n";
        //cout << win[gn] << "\n";
        if (win[gn] == 1) {
            cout << "Alice\n";
        } else if (win[gn] == 2) {
            cout << "Bob\n";
        } else {
            cout << "Deal\n";
        }
    }
}