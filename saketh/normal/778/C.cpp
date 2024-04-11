#include <bits/stdc++.h>
using namespace std;

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

const int MAXN = 3e5 + 1;
const int SIGMA = 26;
int tree[MAXN][SIGMA];
int temp[MAXN][SIGMA], tail;

int get_node() {
    memset(temp[tail], 0, sizeof(temp[tail]));
    return tail++;
}

void insert(int tloc, int cloc) {
    for (int ch = 0; ch < 26; ch++) {
        if (!tree[tloc][ch]) continue;
        if (!temp[cloc][ch])
            temp[cloc][ch] = get_node();
        insert(tree[tloc][ch], temp[cloc][ch]);
    }
}

int count_rep(int tloc, int cloc) {
    int ans = 1;
    for (int ch = 0; ch < 26; ch++) {
        if (tree[tloc][ch] && temp[cloc][ch])
            ans += count_rep(tree[tloc][ch], temp[cloc][ch]);
    }
    return ans;
}

int simulate(int loc, int bch, int big) {
    tail = 1;
    int root = get_node();
    for (int ch = 0; ch < 26; ch++) {
        if (ch != bch && tree[loc][ch] > 0)
            insert(tree[loc][ch], root);
    }
    int share = count_rep(tree[loc][bch], root);
    return big + tail - 1 - share;
}

int solve(vi &save, int loc, int dep) {
    int sz = 1, big = 0, bch = -1;
    for (int ch = 0; ch < 26; ch++) {
        if (!tree[loc][ch]) continue;
        int sub = solve(save, tree[loc][ch], dep + 1);
        if (sub > big) {
            big = sub;
            bch = ch;
        }
        sz += sub;
    }
    if (bch != -1) {
        save[dep] += sz - simulate(loc, bch, big);
    }
    return sz;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        char c;
        cin >> u >> v >> c;
        tree[u][c-'a'] = v;
    }

    vi save(N);
    solve(save, 1, 0);
    int bp = 0;
    for (int p = 1; p < N; p++) {
        if (save[p] > save[bp])
            bp = p;
    }

    cout << N - save[bp] << "\n";
    cout << bp + 1 << "\n";

    return 0;
}