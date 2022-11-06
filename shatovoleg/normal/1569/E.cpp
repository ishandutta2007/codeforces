#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef long double ld;

#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define pb push_back
#define kek pop_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define mp make_pair
// #define int ll


const int INF = (is_same<int, ll>::value ? 1e18l + 666 : 1e9 + 666);
const ll INFll = 1e18 + 666;
mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template<class t1, class t2>
inline bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
inline bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

inline int bpow(ll a, ll b, int mod) {
    a %= mod;
    int res = 1;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int(1ll * res * a % mod);
        }
        a *= a;
        a %= mod;
    }
    return res;
}

void run();

signed main() {
    // freopen("mining.in", "r", stdin);
    // freopen("mining.out", "w", stdout);
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

constexpr int mod = 998'244'353;

int k, a, h;
vector<char> looser_place;
vector<int> pows;
vector<int> good_pows;

vector<char> table;
vector<char> results;

void init() {
    table.resize(1 << k);
    results.resize(1 << k);
    looser_place.pb(1);
    looser_place.pb(2);
    for (int i = 1; i < k; ++i) {
        looser_place.pb(char(looser_place.back() * 2 - 1));
    }
    pows.resize(looser_place.back() + 1, 1);
    for (int i = 1; i < len(pows); ++i) {
        pows[i] = int(1ll * pows[i - 1] * a % mod);
    }
    good_pows.resize(len(looser_place));
    for (int i = 0; i < len(looser_place); ++i) {
        good_pows[i] = pows[looser_place[i]];
    }
}

void simulate(int game_results) {
    fill(all(results), -1);
    iota(all(table), 0);
    for (int i = k; i > 0; --i) {
        const int first_game = (1 << (i - 1)) - 1;
        for (int j = 0; j < (1 << (i - 1)); ++j) {
            char winner = table[j << 1], looser = table[(j << 1) + 1];
            if (game_results & (1 << (j + first_game))) {
                swap(winner, looser);
            }
            results[looser] = (char)i;
            table[j] = winner;
        }
    }
    results[table[0]] = 0;
}

vector<pii> get_game_finals_left(int top_results) {
    const int amount_of_games = (1 << (k - 2));
    const int first_game = (1 << (k - 1)) - 1;
    vector<pii> ret;
    for (int msk = 0; msk < (1 << amount_of_games); ++msk) {
        simulate(top_results | (msk << first_game));
        ll h = 0;
        for (int i = 0; i < (1 << (k - 1)); ++i) {
            h += 1ll * (i + 1) * good_pows[results[i]];
        }
        h %= mod;
        ret.emplace_back(int(h), msk);
    }
    return ret;
}

vector<pii> get_game_finals_right(int top_results) {
    const int amount_of_games = (1 << (k - 2));
    const int first_game = (1 << (k - 1)) - 1 + amount_of_games;
    vector<pii> ret;
    for (int msk = 0; msk < (1 << amount_of_games); ++msk) {
        simulate(top_results | (msk << first_game));
        ll h = 0;
        for (int i = (1 << (k - 1)); i < (1 << k); ++i) {
            h += 1ll * (i + 1) * good_pows[results[i]];
        }
        h %= mod;
        ret.emplace_back(int(h), msk);
    }
    return ret;
}

void run() {
    cin >> k >> a >> h;
    init();
    if (k == 1) {
        if (h == int((0ll + 1 * pows[1] + 2 * pows[2]) % mod)) {
            cout << "1 2\n";
            return;
        }
        if (h == int((0ll + 2 * pows[1] + 1 * pows[2]) % mod)) {
            cout << "2 1\n";
            return;
        }
        cout << -1 << endl;
        return;
    }
    const int last_games = (1 << (k - 1)) - 1;
    const int half_bot_games = (1 << (k - 2));
    
    int ans = -1;

    unordered_map<int, int> mp;
    mp.rehash(1 << ((1 << (k - 2)) + 1));
    for (int top_results = 0; top_results < (1 << last_games) && ans == -1; ++top_results) {
        vector<pii> left = get_game_finals_left(top_results);
        vector<pii> right = get_game_finals_right(top_results);
        for (auto& [h, msk] : left) {
            mp[h] = msk;
        }
        for (auto& [h, msk] : right) {
            int rem = ::h - h;
            if (rem < 0) rem += mod;
            if (auto it = mp.find(rem); it != mp.end()) {
                ans = (msk << half_bot_games);
                ans += it->second;
                ans <<= last_games;
                ans += top_results;
                break;
            }
        }
        mp.clear();
    }
    if (ans == -1) {
        cout << -1 << endl;
        return;
    }
    simulate(ans);
    for (auto& x : results) {
        cout << (int)looser_place[x] << " ";
    }
    cout << endl;
}