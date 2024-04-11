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

    const vi vals = { 4, 8, 15, 16, 23, 42 };

    int N;
    cin >> N;

    int lost = 0;

    vi made(7);
    made[0] = INT_MAX;

    for (int i = 0, v; i < N; i++) {
        cin >> v;
        int j = 0; while (vals[j] != v) j++;

        if (made[j]) { made[j+1]++; made[j]--; }
        else lost++;
    }

    for (int l = 1; l <= 5; l++)
        lost += made[l] * l;
    cout << lost << endl;

    return 0;
}