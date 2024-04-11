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

void assign(vvi &res, int i, int j, int v) {
    res[i][j] = v;
    res[j][i] = 2 - v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vector<pair<int, int>> pts(N);
    for (int i = 0; i < K; i++)
        cin >> pts[i].first;

    int sum = 0;

    for (int i = 0; i < N; i++) {
        int lim = 2 * (i + 1) * (N - i - 1) 
                + i * (i + 1) 
                - sum;

        if (pts[i].first > lim) {
            cout << "no\n";
            return 0;
        }

        if (i >= K) {
            pts[i].first = min(lim, pts[i-1].first);
        }

        sum += pts[i].first;
        pts[i].second = i;
    }

    if (sum != N * (N - 1)) {
        cout << "no\n";
        return 0;
    }

    vvi res(N, vi(N));

    while (pts.size() > 0) {
        sort(all(pts), [&](pair<int, int> &a, pair<int, int> &b) {
            return a.first > b.first;
        });

        for (int i = pts.size() - 1; i > 0; i--) {
            int take = min(2, pts[0].first);
            assign(res, pts[0].second, pts[i].second, take);
            pts[0].first -= take;
            pts[i].first -= (2 - take);
        }

        pts.erase(pts.begin());
    }

    const string out = "LDW";

    cout << "yes\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) cout << 'X';
            else cout << out[res[i][j]];
        }
        cout << "\n";
    }

    return 0;
}