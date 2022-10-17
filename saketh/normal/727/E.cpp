#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

namespace rabin_karp {
    const int NPRIME = 3;
    const int P1 = 1e9 + 21, P2 = 1e9 + 321, P3 = 1e9 + 403;
    const int primes[3] = { P1, P2, P3 };

    struct strong_mod {
        int vals[NPRIME];

        strong_mod(ll value = 0) {
            for (int i = 0; i < NPRIME; i++) {
                vals[i] = value % primes[i];
                if(vals[i] < 0) vals[i] += primes[i];
            }
        }

        #define combine(h, op) \
            strong_mod res; \
            for (int i = 0; i < NPRIME; i++) \
                res.vals[i] = (vals[i] op h.vals[i]) % primes[i]; \
            return res;

        bool operator==(const strong_mod &h) { return !memcmp(this, &h, sizeof(strong_mod)); }
        strong_mod operator*(const strong_mod &h) { combine(h, * 1ll *); }
        strong_mod operator+(const strong_mod &h) { combine(h, +); }

        strong_mod operator*(ll m) { return (*this) * strong_mod(m); }
        strong_mod operator+(ll a) { return (*this) + strong_mod(a); }

        static const ll T6 = 1e6, T12 = 1e12;
        ll hash() {
            ll res = 0;
            for (int i = 0; i < NPRIME; i++)
                res = (T6 * res + vals[i]) % T12;
            return res;
        }
    };

    const int MAXL = 2e6 + 200;
    const int BASE = 3001;

    vector<strong_mod> powers;

    void init() {
        powers.resize(MAXL);
        powers[0] = strong_mod(1);
        for(int i=1; i<MAXL; i++)
            powers[i] = powers[i-1] * BASE;
    }

    void compute(vector<strong_mod> &hashes, string str) {
        hashes.resize(str.size() + 1);
        for(int i=1; i<=str.size(); i++)
            hashes[i] = hashes[i-1] * BASE + int(str[i-1]);
    }

    strong_mod read(vector<strong_mod> &hashes, int i, int l) {
        strong_mod sub = hashes[i] * powers[l];
        return hashes[i+l] + (sub * -1);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    rabin_karp::init();
    
    int N, K;
    cin >> N >> K;

    string cd;
    cin >> cd;

    stringstream ss;
    ss << cd << cd;
    string cdcd = ss.str();

    vector<rabin_karp::strong_mod> hashes, tmp;
    rabin_karp::compute(hashes, cdcd);

    unordered_map<ll, int> games;

    int G;
    cin >> G;
    for (int g = 0; g < G; g++) {
        string game;
        cin >> game;
        rabin_karp::compute(tmp, game);
        games[tmp.back().hash()] = g;
    }

    for (int s = 0; s < K; s++) {
        vector<bool> used(G, false);
        vector<int> order;

        for (int i = 0; i < N; i++) {
            int b = i * K + s;
            rabin_karp::strong_mod entry = rabin_karp::read(hashes, b, K);
            if (!games.count(entry.hash())) {
                break;
            }

            int g = games[entry.hash()];
            if (used[g]) {
                break;
            }

            used[g] = true;
            order.push_back(g);
        }

        if (order.size() == N) {
            cout << "YES\n";
            for (int v : order)
                cout << v + 1 << " ";
            cout << "\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}