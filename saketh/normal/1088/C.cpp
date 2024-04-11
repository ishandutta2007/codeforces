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
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];

    cout << N + 1 << "\n";

    int tot = 0;
    for (int i = N - 1; i >= 0; i--) {
        int add = i - ((a[i] + tot) % N);
        if (add < 0) add += N;
        cout << 1 << " " << i + 1 << " " << add << "\n";
        tot += add;
    }

    cout << 2 << " " << N << " " << N << "\n";

    return 0;
}