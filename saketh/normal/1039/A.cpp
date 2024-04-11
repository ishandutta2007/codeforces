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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    ll T;
    cin >> N >> T;

    vll a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] += T;
    }

    vi x(N);
    for (int i = 0; i < N; i++) {
        cin >> x[i];
        --x[i];
        if (x[i] < i) {
            cout << "No\n";
            return 0;
        }
    }

    vll blim(N, LLONG_MAX);
    for (int i = 0; i < N; i++) {
        if (x[i] + 1< N) {
            blim[x[i]] = min(blim[x[i]], a[x[i] + 1] - 1);
        }
    }

    vll b(N);
    int cov = -1;
    for (int i = 0; i < N; i++) {
        cov = max(cov, x[i] - 1);

        b[i] = a[i];
        if (cov >= i) b[i] = max(b[i], a[i+1]);
        if (i) b[i] = max(b[i], b[i-1] + 1);

        if (b[i] > blim[i]) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
    for (ll v : b)
        cout << v << " ";
    cout << endl;

    return 0;
}