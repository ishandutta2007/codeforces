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

    int N;
    cin >> N;

    int free = -1;

    vi tar(N);
    vb fixed(N);
    for (int i = 0; i < N; i++) {
        cin >> tar[i];
        --tar[i];
        if (tar[i] != i) {
            free = i;
        } else fixed[i] = true;
    }

    vector<vector<char>> res(N, vector<char>(N, '.'));
    auto done = [&](int ans) {
        cout << ans << "\n";
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++)
                cout << res[i][j];
            cout << "\n";
        }
        cout.flush();
        exit(0);
    };

    if (free == -1) {
        done(N);
    }
    fixed[free] = true;

    int use = 0, loc = tar[free];
    for (; loc != free; loc = tar[loc]) {
        res[use][loc] = tar[loc] > loc ? '/' : '\\';
        res[use][tar[loc]] = tar[loc] > loc ? '/' : '\\';
        fixed[loc] = true;
        use++;
    }

    for (int i = 0; i < N; i++) {
        if (fixed[i]) continue;
        vi cycle = { i };
        for (int j = tar[i]; j != i; j = tar[j])
            cycle.push_back(j);
        while (cycle[cycle.size() - 2] > cycle[cycle.size() - 1]) {
            int last = cycle.back();
            cycle.pop_back();
            cycle.insert(cycle.begin(), last);
        }

        res[use][cycle[0]] = '\\';
        res[use][free] = '\\';
        use++;

        for (int loc : cycle) {
            if (tar[loc] != cycle.front()) {
                res[use][loc] = tar[loc] > loc ? '/' : '\\';
                res[use][tar[loc]] = tar[loc] > loc ? '/' : '\\';
                fixed[loc] = true;
                use++;
            } else {
                res[use-1][free] = '/';
            }
        }

        fixed[cycle.back()] = true;
    }

    done(N-1);
    return 0;
}