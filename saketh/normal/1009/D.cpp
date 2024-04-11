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

    int N, M;
    cin >> N >> M;

    if (M < N - 1) {
        cout << "Impossible\n";
        return 0;
    }

    vector<pair<int, int>> edges;

    for (int i = 2; i <= N; i++)
        edges.emplace_back(1, i);

    for (int v = 2; v <= N; v++) {
        for (int i = 2; i < v; i++) {
            if (__gcd(v, i) != 1) continue;
            if (edges.size() < M)
                edges.emplace_back(i, v);
            else break;
        }

        if (edges.size() == M) break;
    }

    if (edges.size() == M) {
        cout << "Possible\n";
        for (auto p : edges)
            cout << p.first << " " << p.second << "\n";
    } else {
        cout << "Impossible\n";
    }

    return 0;
}