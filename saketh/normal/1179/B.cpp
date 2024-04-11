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
using vd = vector<double>;
using vs = vector<string>;

template<typename T> void ckmin(T& a, const T& b) { a = min(a, b); }
template<typename T> void ckmax(T& a, const T& b) { a = max(a, b); }

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> visits;

    int fr = 0, lr = N - 1;
    while (fr < lr) {
        for (int i = 0; i < M; i++) {
            visits.emplace_back(fr, i);
            visits.emplace_back(lr, M - 1 - i);
        }

        fr++, lr--;
    }

    if (fr == lr) {
        for (int i = 0; i <= M - 1 - i; i++) {
            visits.emplace_back(fr, i);
            if (i != M - 1 - i)
                visits.emplace_back(fr, M - 1 - i);
        }
    }

    /*assert(sz(visits) == N * M);

    set<pair<int, int>> used, seen;
    seen.insert(visits[0]);

    for (int i = 1; i < sz(visits); i++) {
        assert(!seen.count(visits[i]));
        seen.insert(visits[i]);

        pair<int, int> diff = { visits[i].first - visits[i-1].first,
            visits[i].second - visits[i-1].second };
        assert(!used.count(diff));
        used.insert(diff);
    }*/

    for (auto p : visits) {
        cout << p.first + 1 << " " << p.second + 1 << "\n";
    }

    return 0;
}