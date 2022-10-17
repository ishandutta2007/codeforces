#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

template<class K> struct sp64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const K& x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash<K>()(x) + FIXED_RANDOM);
    }
};
template<class K, class V> using umap = gp_hash_table<K, V, sp64_hash<K>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void find_dist(vi &sieve, int targ, vi &sig, int &best, int inx, int cur, int prod, int last) {
    if (cur > best) return;
    if (inx >= sig.size() && prod == targ) {
        best = min(best, cur);
        return;
    }
    for (int nxt = sieve[targ / prod]; nxt <= last; nxt++) {
        if ((targ / prod) % nxt != 0) continue;
        int cv = (inx >= sig.size()) ? 0 : sig[inx];
        int cost = abs((nxt - 1) - cv);
        find_dist(sieve, targ, sig, best, inx+1, cur + cost, prod * nxt, nxt);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    const int MAXV = 1e6 + 1;
    vi sieve(MAXV);
    sieve[1] = 1;
    for (int p = 2; p < MAXV; p++) {
        if (sieve[p]) continue;
        for (int q = p; q < MAXV; q += p)
            sieve[q] = p;
    }

    map<vector<int>, int> inx;
    vvi types;
    vi ident(MAXV);

    for (int v = 1; v < MAXV; v++) {
        vi res;
        for (int tmp = v; tmp > 1; ) {
            int p = sieve[tmp];
            int ct = 0;
            while (sieve[tmp] == p) {
                tmp /= p;
                ct++;
            }
            res.push_back(ct);
        }

        sort(all(res), greater<int>());
        if (!inx.count(res)) {
            inx[res] = types.size();
            types.push_back(res);
        }
        ident[v] = inx[res];
    }

    int T = types.size();
    vvi dist(T, vi(1000, INT_MAX));
    for (int i = 0; i < types.size(); i++) {
        for (int t = 1; t < 1000; t++) {
            find_dist(sieve, t, types[i], dist[i][t], 0, 0, 1, t);
        }
    }

    vvi ans(T, vi(T, INT_MAX));
    for (int i = 0; i < T; i++) {
        for (int j = i; j < T; j++) {
            for (int k = 1; k < 1000; k++) {
                ans[i][j] = min(ans[i][j], dist[i][k] + dist[j][k]);
            }
        }
    }

    int Q;
    cin >> Q;
    for (int q = 0; q < Q; q++) {
        int a, b;
        cin >> a >> b;
        int ta = ident[a];
        int tb = ident[b];
        if (ta > tb) swap(ta, tb);
        cout << ans[ta][tb] << "\n";
    }

    return 0;
}