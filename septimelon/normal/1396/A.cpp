#include <iostream>
#include <vector>
#include <cmath>
#include <random>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MOD = 1000000007;
const int INF = 1000000000LL;

void add(int& a, int b) {
    a += b;
    if (a >= MOD) {
        a -= MOD;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<ll> vost(n + 1);
    for (ll i = 0LL; i < n; ++i) {
        vost[(i * (n - 1LL)) % n] = i * (n - 1LL);
    }
    vost[n] = vost[0];

    /*for (int i = 0; i <= n; ++i) {
        cout << vost[i] << " ";
    }*/

    if (n > 1) {
        cout << "2 " << n << "\n";
        for (int i = 1; i < n; ++i) {
            cout << vost[n - ((a[i] % n) + 10LL * n) % n] << " ";
            a[i] += vost[n - ((a[i] % n) + 10LL * n) % n];
        }
        cout << "\n";
    }
    else {
        cout << "1 1\n0\n";
    }

    cout << "1 1\n" << n - a[0] << "\n";
    a[0] = n;

    cout << "1 " << n << "\n";
    for (int i = 0; i < n; ++i) {
        cout << 0LL - a[i] << " ";
    }
    cout << "\n";

    return 0;
}