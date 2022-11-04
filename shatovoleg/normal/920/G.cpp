#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

#define pb push_back
#define kek pop_back
#define mp make_pair
#define pii pair<int, int>
#define all(v) v.begin(), v.end()
#define len(v) ((int)(v).size())
#define int ll

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());
const int INF = 1e9;

template<class t1, class t2>
bool cmin(t1 &a, const t2 &b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

template<class t1, class t2>
bool cmax(t1 &a, const t2 &b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
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
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    run();
}

vector<int> get_prime_divisors(int p) {
    vector<int> ans;
    for (int i = 2; i * i <= p; ++i) {
        if (p % i == 0) {
            ans.pb(i);
            while (p % i == 0) {
                p /= i;
            }
        }
    }
    if (p != 1) {
        ans.pb(p);
    }
    return ans;
}

int get_mul(const vector<int> &nums, int msk) {
    int ans = 1;
    for (auto &x : nums) {
        if (msk & 1) {
            ans *= x;
        }
        msk >>= 1;
    }
    return ans;
}

int count_coprimes_less(int x, const vector<int> &primes) {
    int ans = 0;
    for (int msk = 0; msk < (1 << len(primes)); ++msk) {
        if (__builtin_popcount(msk) & 1) {
            ans -= x / get_mul(primes, msk);
        } else {
            ans += x / get_mul(primes, msk);
        }
    }
    return ans;
}

void solve() {
    int x, p, k;
    cin >> x >> p >> k;
    int l = 0, r = 1e9;
    vector<int> pr = get_prime_divisors(p);
    int val = count_coprimes_less(x, pr);
    while (r - l > 1) {
        int c = (r + l) >> 1;
        if (count_coprimes_less(c, pr) - val >= k) {
            r = c;
        } else {
            l = c;
        }
    }
    cout << r << endl;
}

void run() {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        solve();
    }
}