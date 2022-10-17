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

void solve() {
    int N;
    cin >> N;
    vi lens(N);
    for (int i = 0; i < N; i++)
        cin >> lens[i];
    sort(all(lens));

    double ans = DBL_MAX;
    array<int, 4> res;

    int pv = 0;
    for (int i = 0; i + 1 < lens.size(); i++) {
        if (lens[i] == lens[i+1]) {
            if (pv) {
                int peri = 2 * (lens[i] + pv);
                double f = 1.0 * peri * peri / lens[i] / pv;
                if (f < ans) {
                    ans = f;
                    res = { pv, pv, lens[i], lens[i] };
                }
            }
            pv = lens[i];
            i++;
        }
    }

    for (int v : res) cout << v << " ";
    cout << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        solve();
    }

    return 0;
}