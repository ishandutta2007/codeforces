#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<string> vs;

template<class K> struct sp64_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(const K& x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(hash<K>()(x) + FIXED_RANDOM);
    }
};
template<class K, class V> using umap = gp_hash_table<K, V, sp64_hash<K>>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, K;
    cin >> N >> K;

    vs grid(N);
    for (int i = 0; i < N; i++)
        cin >> grid[i];

    vvi rank(N+1, vi(N+1, INT_MAX));
    for (int diag = 2*N-2; diag >= 0; diag--) {
        vector<array<int, 2>> cells;
        for (int i = 0; i < N; i++) {
            int j = diag - i;
            if ((j >= 0) && (j < N))
                cells.push_back({i, j});
        }

        sort(all(cells), [&](auto e1, auto e2) {
            auto [x1, y1] = e1;
            auto [x2, y2] = e2;

            char c1 = grid[x1][y1];
            char c2 = grid[x2][y2];
            if (c1 != c2) return c1 < c2;

            int s1 = min(rank[x1+1][y1], rank[x1][y1+1]);
            int s2 = min(rank[x2+1][y2], rank[x2][y2+1]);
            return s1 < s2;
        });

        for (int i = 0; i < cells.size(); i++) {
            auto [x, y] = cells[i];
            rank[x][y] = i;
        }
    }

    auto print = [&](int i, int j) {
        while (rank[i][j] != INT_MAX) {
            cout << grid[i][j];
            if (rank[i+1][j] < rank[i][j+1]) {
                i++;
            } else {
                j++;
            }
        }
        cout << endl;
    };

    if (K == 0) {
        print(0, 0);
        return 0;
    }

    int r = -1, c = -1;
    auto record = [&](int i, int j) {
        if ((r != -1) && (r+c > i+j)) return;
        if ((r == -1) || (i+j > r+c) || (rank[i][j] < rank[r][c])) {
            tie(r, c) = { i, j };
        }
    };

    vvi avis(N, vi(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            avis[i][j] = int(grid[i][j] == 'a');
            avis[i][j] += max(i ? avis[i-1][j] : 0, j ? avis[i][j-1] : 0);
            if (avis[i][j] + K >= i+j+1) {
                record(i+1, j);
                record(i, j+1);
            }
        }
    }

    for (int i = 0; i < r+c; i++) {
        cout << 'a';
    }
    print(r, c);

    return 0;
}