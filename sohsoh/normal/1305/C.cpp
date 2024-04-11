/*
    Soheil Mohammadkhani
    IDK :)
*/


#include <bits/stdc++.h>
#include <string>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template <class T> using Tree = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;

#define all(x)                      (x).begin(),(x).end()
#define Sort(x)                     sort(all((x)))
#define X                           first
#define Y                           second
#define sep                         ' '
#define endl                        '\n'
#define SZ(x)                       ll(x.size())

ll poww(ll a, ll b, ll md) {
    return (!b ? 1 : (b & 1 ? a * poww(a * a % md, b / 2, md) % md : poww(a * a % md, b / 2, md) % md));
}

const ll MAXN = 1e6 + 10;
const ll LOG = 22;
const ll INF = 8e18;
const ll MOD = 998244353; // 1e9 + 9;

pair<vector<int>, int*> solve(int* s, int n) {
   vector<int> res;

    for (int i = 0; i < n; i++) {
        if (s[i] == 1) {
            for (int j = n - 1; j >= 0 && j > i; j--) {
                if (s[j] == 0) {
                    res.push_back(j + 1);
                    res.push_back(i + 1);
                    s[i] = -1;
                    s[j] = -1;
                    break;
                }
            }
        }
    }

    return make_pair(res, s);
}

std::string stringulate(int v)
{
    std::ostringstream oss;
    oss << v;
    return oss.str();
}

long bigMod(long  a, long  b, long c) {
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a == 1) {
        return b;
    }
    if (b == 1) {
        return a;
    }

    // Returns: (a * b/2) mod c
    long a2 = bigMod(a, b / 2, c);

    // Even factor
    if ((b & 1) == 0) {
        // [((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return (a2 + a2) % c;
    } else {
        // Odd exponent
        // [(a mod c) + ((a * b/2) mod c) + ((a * b/2) mod c)] mod c
        return ((a % c) + (a2 + a2)) % c;
    }
}

int main() {
    int n, mo;
    cin >> n >> mo;

    ll* a = new ll[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n > 1000) return cout << 0 << endl, 0;
    sort(a, a + n);
    reverse(a, a + n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long k = a[i] - a[j];
            if (k % mo == 0) return cout << 0 << endl, 0;
        }
    }

    long long res = 1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            long long k = a[i] - a[j];
//            cout << k << endl;
            res = bigMod(res, k, mo);
        }
    }

    cout << res % mo << endl;
    return 0;
}