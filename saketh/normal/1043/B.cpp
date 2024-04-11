#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vi a(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> a[i];
    }

    vi vals(N);
    for (int i = 0; i < N; i++) {
        vals[i] = a[i+1] - a[i];
    }

    vi pos;
    for (int k = 1; k <= N; k++) {
        bool ok = true;
        for (int i = 0; i < N; i++) {
            if (vals[i % k] != vals[i])
                ok = false;
        }
        if (ok) pos.push_back(k);
    }

    cout << pos.size() << "\n";
    for (int v : pos) cout << v << " ";
    cout << endl;

    return 0;
}