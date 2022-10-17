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

    vector<array<int, 3>> gt, lt;
    for (int i = 0, a, b; i < N; i++) {
        cin >> a >> b;
        (a > b ? gt : lt).push_back({ a, b, i });
    }

    if (lt.size() > gt.size()) {
        sort(all(lt), [](auto a, auto b) {
            return a[1] > b[1];
        });

        cout << lt.size() << "\n";
        for (auto e : lt)
            cout << e[2] + 1 << " ";
        cout << endl;
    } else {
        sort(all(gt), [](auto a, auto b) {
            return a[0] < b[0];
        });

        cout << gt.size() << "\n";
        for (auto e : gt) {
            cout << e[2] + 1 << " ";
        }
        cout << "\n";
    }

    return 0;
}