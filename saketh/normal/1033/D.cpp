#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
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

const int MOD = 998244353;
int sum(int a, int b) { return (a + b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }

ll gcd(ll a, ll b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

ll ipow(ll base, int e) {
    ll res = 1;
    for (int i = 0; i < e; i++)
        res = res * base;
    return res;
}

ll find_root(ll arg, int e) {
    ll cand = ll(pow(arg - 1, 1./e));
    while (ipow(cand, e) < arg)
        cand++;
    if (ipow(cand, e) == arg)
        return cand;
    return -1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    unordered_map<ll, int> primes;

    int N;
    cin >> N;
    unordered_map<ll, int> vals;

    for (int i = 0; i < N; i++) {
        ll v;
        cin >> v;

        bool done = false;
        for (int b = 4; b >= 2; b--) {
            ll root = find_root(v, b);
            if (root != -1) {
                primes[root] += b;
                done = true;
                break;
            }
        }
        if (!done) vals[v]++;
    }

    /*cout << "PRIMES: ";
    for (auto [pr, ct] : primes) {
        cout << pr << " (" << ct << ") ";
    }
    cout << endl << "VALS: ";
    for (auto [v, ct] : vals) {
        cout << v << " (" << ct << ") ";
    }
    cout << endl;*/

    while (true) {
        bool changed = false;

        for (auto [pr, _pct] : primes) {
            for (auto [va, vct] : vals) {
                if (va % pr == 0) {
                    primes[pr] += vct;
                    primes[va/pr] += vct;
                    vals.erase(va);
                    changed = true;
                    goto END;
                }
            }
        }

        for (auto it1 = vals.begin(); it1 != vals.end(); it1 = next(it1)) {
            for (auto it2 = next(it1); it2 != vals.end(); it2 = next(it2)) {
                ll v1 = it1->first;
                int v1ct = it1->second;
                ll v2 = it2->first;
                int v2ct = it2->second;

                ll g = gcd(v1, v2);
                if (g > 1) {
                    primes[g] += v1ct + v2ct;
                    primes[v1/g] += v1ct;
                    primes[v2/g] += v2ct;
                    vals.erase(v1);
                    vals.erase(v2);
                    changed = true;
                    goto END;
                }
            }
        }

        END:
        if (!changed) break;
    }

    int ans = 1;
    for (auto [p, ct] : primes)
        ans = prod(ans, ct + 1);
    for (auto [v, ct] : vals) {
        ans = prod(ans, ct + 1);
        ans = prod(ans, ct + 1);
    }
    cout << ans << endl;

    return 0;
}