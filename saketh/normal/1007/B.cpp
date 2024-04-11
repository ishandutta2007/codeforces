#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int ndivs[100005];
set<array<int, 3>> pos;

ll solve(int a, int b, int c) {
    array<int, 8> ct{};
    for (int m = 7; m > 0; m--) {
        int g = 0;
        if ((m&1)) g = __gcd(g, a);
        if ((m&2)) g = __gcd(g, b);
        if ((m&4)) g = __gcd(g, c);
        g = ndivs[g];

        for (int n = 7; n > 0; n--) {
            if ((m|n) == n)
                g -= ct[n];
        }

        ct[m] = g;
    }

    ll ans = 0;
    for (auto a : pos) {
        array<int, 8> rep{};
        for (int v : a) rep[v]++;

        ll ways = 1;
        for (int v = 1; v < 8; v++) {
            ll nr = ct[v];
            if (rep[v] == 1) ways *= nr;
            else if (rep[v] == 2) ways *= nr + nr * (nr - 1) / 2;
            else if (rep[v] == 3) ways *= nr
                                        + nr * (nr - 1)
                                        + nr * (nr - 1) * (nr - 2) / 6;
        }
        ans += ways;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    for (int a = 0; a < 8; a++) {
        if (!(a&1)) continue;
        for (int b = 0; b < 8; b++) {
            if (!(b&2)) continue;
            for (int c = 0; c < 8; c++) {
                if (!(c&4)) continue;
                array<int, 3> res = { a, b, c };
                sort(all(res));
                pos.insert(res);
            }
        }
    }

    for (int i = 1; i <= 100000; i++) {
        for (int j = 1; j*j <= i; j++) {
            if (i % j != 0) continue;
            ndivs[i]++;
            if (i/j != j) ndivs[i]++;
        }
    }

    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        cout << solve(a, b, c) << "\n";
    }

    return 0;
}