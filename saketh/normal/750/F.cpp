#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

map<int, set<int>> cache;
set<int> query(int loc) {
    assert(loc);
    if (cache.count(loc)) return cache[loc];

    cout << "? " << loc << endl;
    int nc, nbr;
    cin >> nc;

    if (nc == 0) { exit(0); }

    set<int> res;
    for (int i = 0; i < nc; i++) {
        cin >> nbr;
        res.insert(nbr);
    }

    return cache[loc] = res;
}

void ans(int root) { cout << "! " << root << endl; }

bool is_root(int loc) {
    if (!cache.count(loc) && cache.size() == 16) return true;
    return query(loc).size() == 2;
}

int find_next(int loc) {
    for (int nbr : query(loc))
        if (!cache.count(nbr))
            return nbr;
    return 0;
}

bool dfs(vi &path) {
    while (true) {
        int app = find_next(path.back());
        if (app) {
            if (is_root(app)) {
                ans(app);
                return true;
            }
            path.push_back(app);
        }
        else break;
    }
}

void solve() {
    int H;
    cin >> H;
    if (H == 0) exit(0);

    if (is_root(1)) {
        ans(1);
        return;
    }

    vector<int> path;
    path.push_back(1);

    for (int d = 0; d < 2; d++) {
        if (dfs(path)) return;
        reverse(all(path));
    }

    WATCHC(path);

    assert(path.size() & 1);
    int high = path[ path.size()/2 ];
    int dist = H - 1 - path.size()/2;

    while (dist > 3) {
        auto it = path.begin() + path.size() / 2;
        path.erase(it + 1, path.end());
        assert(path.back() == high);

        if (dfs(path)) return;
        high = path[ path.size()/2 ];
        dist = H - 1 - path.size()/2;
    }

    WATCH(high);
    vi bfs = { high };
    for (int i = 0; i < bfs.size(); i++) {
        while (true) {
            int nbr = find_next(bfs[i]);
            if (nbr) {
                if (is_root(nbr)) { ans(nbr); return; }
                bfs.push_back(nbr);
            }
            else break;
        }
    }

    assert(false);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int T;
    cin >> T;
    for (int t = 0; t < T; t++) {
        cache.clear();
        solve();
    }

    return 0;
}