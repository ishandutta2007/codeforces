#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define all(x) x.begin(), x.end()

template <typename T1, typename T2> inline void chkmin(T1 &x, const T2 & y) {if (x > y) x = y;}
template <typename T1, typename T2> inline void chkmax(T1 &x, const T2 & y) {if (x < y) x = y;}

int n, k;

void read() {
    cin >> n >> k;
}

const int MAXN = 20;
ll fact[MAXN];
const ll INF = 1e9 + 10;

ll mul(ll a, ll b) {
    if ((INF + a - 1) / a < b) return INF;
    return a * b;
}

bool check(int x) {
    while (x) {
        if (x % 10 != 4 && x % 10 != 7) {
            return false;
        }
        x /= 10;
    }
    return true;
}

ll pow(ll a, ll n) {
    ll ans = 1;
    while (n) {
        if (n & 1) {
            ans *= a;
        }
        a *= a;
        n >>= 1;
    }
    return ans;
}

int calc(int r) {
    int ans = 0;
    for (ll len = 1; pow(10, len - 1) <= r; len++) {
        vector<int> have(len, 4);
        for (int i = 0; i <= len; i++) {
            do {
                ll x = 0;
                for (auto num : have) {
                    x *= 10;
                    x += num;
                }
                ans += x <= r;
            } while (next_permutation(all(have)));
            if (i == len) break;
            have[len - 1 - i] = 7;
        }
    }
    return ans;
}

int ans;

void run() {
    fact[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fact[i] = mul(fact[i - 1], i);
    }
    int l;
    set<int> have;
    if (n <= 14) {
        if (fact[n] < k) {
            ans = -1;
            return;
        }
        l = 1;
        ans = 0; 
    } else {
        l = n - 13;
        ans = calc(l - 1);
    }
    for (int i = l; i <= n; i++) {
        have.insert(i);
    }
    for (int i = l; i <= n; i++) {
        for (auto x : have) {
            if (fact[n - i] < k) {
                k -= fact[n - i];
                continue;
            }
            ans += check(i) && check(x);
            have.erase(x);
            break;
        }
    }
    assert(k == 1);
}

void write() {
    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    read();
    run();
    write();
    return 0;
}