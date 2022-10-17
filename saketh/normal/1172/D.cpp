#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N;
    cin >> N;

    vi right(N), down(N);

    for (int i = 0; i < N; i++) {
        cin >> right[i];
        --right[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> down[i];
        --down[i];
    }

    vector<array<int, 4>> ans;

    for (int i = N - 1; i >= 0; i--) {
        if (right[i] == i && down[i] == i) continue;
        ans.push_back({ i, down[i], right[i], i });

        if (right[i] != i) {
            for (int j = 0; j < i; j++)
                if (right[j] == i)
                    right[j] = right[i];
        }

        if (down[i] != i) {
            for (int j = 0; j < i; j++)
                if (down[j] == i)
                    down[j] = down[i];
        }
    }

    cout << ans.size() << "\n";
    for (auto pr : ans) {
        for (int v : pr)
            cout << v + 1 << " ";
        cout << "\n";
    }

    return 0;
}