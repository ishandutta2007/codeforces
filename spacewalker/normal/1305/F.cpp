#include <bits/stdc++.h>

using namespace std;
using ll = long long;
constexpr int SQRT_NMAX = 1000010;

vector<ll> primes;
bool isPrime[SQRT_NMAX];

vector<ll> pfacInWindow(ll a, ll b) {
    vector<ll> ans;
    a = max(1LL, a);
    if (a > b) return ans;
    vector<ll> nums(b - a + 1);
    for (int i = 0; i < nums.size(); ++i) nums[i] = a + i;
    for (ll p : primes) {
        ll st = a / p * p;
        if (st < a) st += p;
        for (ll mark = st; mark <= b; mark += p) {
            while (nums[mark - a] % p == 0) nums[mark - a] /= p;
        }
        if (a <= st && st <= b) ans.push_back(p);
    }
    for (ll v : nums) if (v > 1) ans.push_back(v);
    return ans;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    for (int i = 2; i < SQRT_NMAX; ++i) isPrime[i] = true;
    for (int i = 2; i < SQRT_NMAX; ++i) {
        if (!isPrime[i]) continue;
        primes.push_back(i);
        for (int j = i + i; j < SQRT_NMAX; j += i) isPrime[j] = false;
    }
    int n; scanf("%d", &n);
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) scanf("%lld", &arr[i]);
    ll ans = n + 5;
    auto basedOn = [&] (ll v) {
        ll cans = 0;
        for (ll x : arr) {
            if (x < v) cans += v - x;
            else {
                ll p = x % v;
                cans += min(p, v - p);
            }
        }
        return cans;
    };
    set<ll> divToTest;
    for (int trial = 0; trial < 10; ++trial) {
        int i = uniform_int_distribution<int>(0, n-1)(rng);
        vector<ll> divs = pfacInWindow(arr[i] - 5, arr[i] + 5);
        for (ll v : divs) divToTest.insert(v);
    }
    for (ll v : divToTest) ans = min(ans, basedOn(v));
    printf("%lld\n", ans);
}