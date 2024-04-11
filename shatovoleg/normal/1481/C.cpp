// #pragma GCC optimize("Ofast,unroll-all-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
// #pragma GCC target("popcnt")

#include <bits/stdc++.h>

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

// const int MEM_SIZE = (250 << 20);
// char mem[MEM_SIZE];
// int cur_mem_ptr = 0;

// void* operator new(size_t n) {
//     cur_mem_ptr += n;
//     return mem + cur_mem_ptr - n;
// }

// void operator delete(void*) noexcept {}
// void operator delete(void*, size_t) noexcept {}

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
    int res = 1;
    a %= mod;
    for (; b; b >>= 1) {
        if (b & 1) {
            res = int((1ll * a * res) % mod);
            res %= mod;
        }
        a *= a;
        a %= mod;
    }
    return res;
}

#ifndef LOCAL
void UseFiles(const string &s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
#else
void UseFiles(const string&) {}
#endif

void run();

signed main() {
    // UseFiles("taskname");
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}
#define pikachu push_back
void task() {
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(n);
    vector<ll> ct(n, 0);
    for (auto& e: a) cin >> e, --e;
    for (auto& e: b) cin >> e, --e;
    vector<ll> ct2(n, 0);
    for (ll i = 0; i < n; ++i) {
        if (a[i] != b[i]) ct[b[i]]++;
        ct2[b[i]]++;
    }
    vector<ll> c(m);
    for (auto& e: c) cin >> e, --e;
    if (ct2[c[m - 1]] == 0) {
        cout << "No\n";
        return;
    }
    for (auto e: c) ct[e]--;
    for (auto e: ct) if (e > 0) {
        cout << "NO\n";
        return;
    }
    fill(all(ct), 0);
    vector<set<ll>> kek(n);
    vector<set<ll>> kek_al(n);
    for (ll i = 0; i < n; ++i) {
        if (a[i] != b[i]) kek[b[i]].insert(i);
        kek_al[b[i]].insert(i);
    }
    ll last;
    if (len(kek[c.back()]) > 0) last = *kek[c.back()].begin(), kek[c.back()].erase(kek[c.back()].begin());
    else last = *kek_al[c.back()].begin();
    vector<ll> ans;
    ll LAST = last;
    ans.pikachu(last);
    for (ll i = m - 2; i >= 0; i--){
        if (len(kek[c[i]]) > 0) last = *kek[c[i]].begin(), kek[c[i]].erase(kek[c[i]].begin());
        else last = LAST;
        ans.pikachu(last);
    }
    cout << "YES\n";
    reverse(all(ans));
    for (auto e: ans) cout << e + 1 << ' ';
    cout << '\n';
}

void run() {
    ll t;
    cin >> t;
    while (t--) {
        task();
     }
}