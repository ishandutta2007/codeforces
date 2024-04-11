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

    int M, N;
    cin >> M >> N;

    vector<bitset<10000>> days(M);

    for (int i = 0, B; i < M; i++) {
        cin >> B;
        for (int j = 0, v; j < B; j++) {
            cin >> v;
            days[i].set(v - 1, true);
        }

        for (int j = 0; j < i; j++) {
            if ((days[i] & days[j]).count() == 0) {
                cout << "impossible\n";
                return 0;
            }
        }
    }

    cout << "possible\n";

    return 0;
}