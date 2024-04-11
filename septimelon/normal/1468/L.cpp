#include <algorithm>
#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <cassert>
#include <assert.h>

//#pragma GCC optimize("O3")

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll MOD = 1000000007;
const ld EPS = 1e-11;
const ll INFL = 1e18;
const ll INF = 1e9 + 7;
const ld PI = acos(-1);

mt19937 rnd((unsigned)chrono::steady_clock::now().time_since_epoch().count());

using u64 = uint64_t;
using u128 = __uint128_t;

u64 binpower(u64 base, u64 e, u64 mod) {
    u64 result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (u128)result * base % mod;
        base = (u128)base * base % mod;
        e >>= 1;
    }
    return result;
}

bool check_composite(u64 n, u64 a, u64 d, int s) {
    u64 x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (u128)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
};

bool MillerRabin(u64 n) {
    if (n < 2)
        return false;

    int r = 0;
    u64 d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    for (int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}) {
        if (n == a)
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }
    return true;
}

vector<ll> prim;

ll isprimep(ll x) {
    for (int i = 0; i < prim.size(); ++i) {
        if (x % prim[i] != 0) {
            continue;
        }
        while (x != 1 && x % prim[i] == 0) {
            x /= prim[i];
        }
        if (x != 1) {
            return 1;
        }
        return prim[i];
    }

    if (MillerRabin(x)) {
        return x;
    }

    ll sqr = sqrt(x);
    if (sqr * sqr == x && MillerRabin(sqr)) {
        return sqr;
    }
    ++sqr;
    if (sqr * sqr == x && MillerRabin(sqr)) {
        return sqr;
    }

    ll cbr = cbrt(x);
    if (cbr * cbr * cbr == x && MillerRabin(cbr)) {
        return cbr;
    }
    ++cbr;
    if (cbr * cbr * cbr == x && MillerRabin(cbr)) {
        return cbr;
    }

    return 1;
}

set<ll> primes(ll x, const vector<pair<int, ll>>& coup) {
    set<ll> ans;
    for (int i = 0; i < coup.size(); ++i) {
        if (x % coup[i].second == 0) {
            ans.insert(coup[i].second);
            while (x % coup[i].second == 0) {
                x /= coup[i].second;
            }
        }
    }
    if (x != 1) {
        ans.clear();
    }
    return ans;
}

void prep() {
    vector<bool> isp(1000001, true);
    for (ll i = 2; i < isp.size(); ++i) {
        if (!isp[i]) {
            continue;
        }
        prim.push_back(i);
        for (ll j = i * i; j < isp.size(); j += i) {
            isp[j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    prep();

    int n, k;
    cin >> n >> k;
    vector<ll> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }

    if (k == 1) {
        cout << "0\n";
        return 0;
    }

    map<ll, vector<ll>> primd;
    primd[1] = {};
    for (int i = 0; i < n; ++i) {
        ll cp = isprimep(x[i]);
        if (primd.count(cp) == 0) {
            primd[cp] = { x[i] };
        }
        else {
            primd[cp].push_back(x[i]);
        }
    }

    int pri1 = primd[1].size();

    vector<pair<int, ll>> coup;
    for (auto it = primd.begin(); it != primd.end(); ++it) {
        if (it->first != 1 && it->second.size() > 1) {
            coup.push_back({ it->second.size(), it->first });
        }
    }
    sort(coup.begin(), coup.end());
    reverse(coup.begin(), coup.end());

    if (coup.size() == 0) {
        cout << "0\n";
        return 0;
    }

    vector<ll> ans;
    
    if (k % 2 == 1 && coup[0].first == 2 && coup.size() * 2 > k) {
        for (int i = 0; i < pri1; ++i) {
            set<ll> cs = primes(primd[1][i], coup);
            if (cs.size() * 2 + 1 > k || cs.size() == 0) {
                continue;
            }
            ans.push_back(primd[1][i]);
            for (auto it = cs.begin(); it != cs.end(); ++it) {
                ans.push_back(primd[*it][0]);
                ans.push_back(primd[*it][1]);
            }
            for (int j = 0; j < coup.size() && ans.size() < k; ++j) {
                if (cs.count(coup[j].second) != 0) {
                    continue;
                }
                ans.push_back(primd[coup[j].second][0]);
                ans.push_back(primd[coup[j].second][1]);
            }
            sort(ans.begin(), ans.end());
            for (int j = 0; j < ans.size(); ++j) {
                cout << ans[j] << " ";
            }
            cout << "\n";
            return 0;
        }
        cout << "0\n";
        return 0;
    }

    for (int i = 0; i < coup.size() && ans.size() + 1 < k; ++i) {
        ans.push_back(primd[coup[i].second][0]);
        ans.push_back(primd[coup[i].second][1]);
    }
    for (int i = 0; i < coup.size() && ans.size() < k; ++i) {
        for (int j = 2; j < coup[i].first && ans.size() < k; ++j) {
            ans.push_back(primd[coup[i].second][j]);
        }
    }
    for (int i = 0; i < pri1 && ans.size() < k; ++i) {
        set<ll> cs = primes(primd[1][i], coup);
        if (cs.size() != 0) {
            ans.push_back(primd[1][i]);
        }
    }

    if (ans.size() < k) {
        cout << "0\n";
        return 0;
    }

    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}