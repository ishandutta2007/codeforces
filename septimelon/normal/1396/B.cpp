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

void solve() {
    int n;
    cin >> n;
    int sa = 0;
    int ma = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        sa += a;
        ma = max(ma, a);
    }

    if (ma * 2 > sa || sa % 2 == 1) {
        cout << "T\n";
    }
    else {
        cout << "HL\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int t;
    cin >> t;
    for (int qq = 0; qq < t; ++qq) {
        solve();
    }

    return 0;
}