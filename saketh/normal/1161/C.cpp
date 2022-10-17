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

    auto lose = []() {
        cout << "Bob" << endl;
        exit(0);
    };

    auto win = []() {
        cout << "Alice" << endl;
        exit(0);
    };

    int N;
    cin >> N;

    vi vals(N);
    for (int i = 0; i < N; i++) {
        cin >> vals[i];
    }

    sort(all(vals));

    if (vals[0] == vals[N/2]) {
        lose();
    }

    win();

    return 0;
}