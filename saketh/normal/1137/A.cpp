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

void calc(vi vals, vi& resb, vi& resa) {
    vi copy = vals;
    sort(all(copy));
    copy.erase(unique(all(copy)), copy.end());

    map<int, int> below, above;
    for (int i = 0; i < copy.size(); i++) {
        below[copy[i]] = i;
        above[copy[i]] = copy.size() - i - 1;
    }

    for (int v : vals) {
        resb.push_back(below[v]);
        resa.push_back(above[v]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    vvi rows(N), cols(M);
    for (int i = 0; i < N; i++) {
        for (int j = 0, v; j < M; j++) {
            cin >> v;
            rows[i].push_back(v);
            cols[j].push_back(v);
        }
    }

    vvi rowB(N), rowA(N);
    for (int i = 0; i < N; i++) {
        calc(rows[i], rowB[i], rowA[i]);
    }

    vvi colB(M), colA(M);
    for (int i = 0; i < M; i++) {
        calc(cols[i], colB[i], colA[i]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (j) cout << " ";
            cout << max(rowB[i][j], colB[j][i]) + 1 + max(rowA[i][j], colA[j][i]);
        }
        cout << "\n";
    }

    return 0;
}