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

ll find_num(int pairs) {
    for (ll c = 1; ; c++) {
        ll p = c * (c - 1) / 2;

        if (p == pairs) return c;
        if (p > pairs) return -1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    ll a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;

    // special cases where string only has zeroes or ones
    if (a01 == 0 && a10 == 0) {
        if (a00 == 0) {
            // only ones
            ll ones = find_num(a11);
            if (ones != -1) {
                while (ones) {
                    cout << 1;
                    ones--;
                }
                cout << "\n";
                return 0;
            }
        } else if (a11 == 0) {
            ll zeroes = find_num(a00);
            if (zeroes != -1) {
                while (zeroes) {
                    cout << 0;
                    zeroes--;
                }
                cout << "\n";
                return 0;
            }
        }

        cout << "Impossible\n";
        return 0;
    }

    ll zeroes = find_num(a00);
    ll ones = find_num(a11);

    if (zeroes == -1 || ones == -1) {
        cout << "Impossible\n";
        return 0;
    }

    ll diffs = zeroes * ones;

    if (a01 + a10 != diffs) {
        cout << "Impossible\n";
        return 0;
    }

    while (a10 >= zeroes) {
        cout << 1;
        ones--;
        a10 -= zeroes;
    }

    for (int i = 0; i < zeroes; i++) {
        cout << 0;

        int rem = zeroes - 1 - i;
        if (rem == a10 && ones > 0) {
            cout << 1;
            ones--;
        }
    }

    while (ones) {
        cout << 1;
        ones--;
    }
    cout << endl;

    return 0;
}