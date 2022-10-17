#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vb = vector<bool>;
using vs = vector<string>;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi lit(N);
    for (int i = 0; i < N; i++) {
        cin >> lit[i];
    }

    int off = 0;
    for (int i = 1; i + 1 < N; i++) {
        if (lit[i-1] && lit[i+1] && !lit[i]) {
            off++;
            lit[i+1] = 0;
        }
    }

    cout << off << endl;
    return 0;
}