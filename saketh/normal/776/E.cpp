#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

void log(vector<pair<ll, int>> &fact) {
    TRACE(for (auto p : fact) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;)
}

void factor(vector<pair<ll, int>> &targ, ll val) {
    for (ll p = 2; p * p <= val; p++) {
        if (val % p) continue;

        int ct = 0;
        while (val % p == 0) {
            val /= p;
            ct++;
        }

        targ.emplace_back(p, ct);
    }

    if (val != 1) targ.emplace_back(val, 1);
}

void cleanup(vector<pair<ll, int>> &fact) {
    sort(all(fact));
    vector<pair<ll, int>> res;
    for (auto p : fact) {
        if (!p.second) continue;
        if (res.size() == 0 || res.back().first != p.first)
            res.push_back(p);
        else res.back().second += p.second;
    }
    swap(res, fact);
}

void totient(vector<pair<ll, int>> &fact) {
    vector<pair<ll, int>> upd;
    for (auto &p : fact) {
        if (p.second > 1) upd.emplace_back(p.first, p.second - 1);
        factor(upd, p.first - 1);
    }
    cleanup(upd);
    swap(fact, upd);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll N, K;
    cin >> N >> K;

    vector<pair<ll, int>> fact;
    factor(fact, N);

    log(fact);

    for (; K > 0; K--) {
        if (K & 1) {
            totient(fact);
            if (fact.size() == 0) {
                break;
            }
        } else {
            // do nothing
        }

        log(fact);
    }

    const int MOD = 1e9 + 7;
    ll res = 1;
    for (auto p : fact) {
        for (int ct = 0; ct < p.second; ct++)
            res = res * p.first % MOD;
    }
    cout << res << endl;

    return 0;
}