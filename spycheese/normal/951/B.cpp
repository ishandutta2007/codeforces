#include <bits/stdc++.h>
#define forn(i,n) for (int i = 0; i < (n); ++i)
#define forab(i,a,b) for (int i = (a); i < (b); ++i)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define X first
#define Y second
#define db(x) cout << #x << " = " << x << '\n'

#ifdef LOCAL
    #define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
    #define eprintf(args...) ;
#endif

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> ipair;
typedef pair<ll, ll> lpair;
typedef vector<int> vi;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
const double PI = acos(-1.0);
const double EPS = 1e-9;

const int N = 52;

int n, m;
vector<ipair> spos, fepos;

bool read() {
    if (scanf("%d%d", &n, &m) < 1) {
        return 0;
    }
    spos.resize(m);
    fepos.resize(m);
    for (ipair &a : spos) {
        scanf("%d%d", &a.X, &a.Y);
        --a.X;
        --a.Y;
    }
    for (ipair &a : fepos) {
        scanf("%d%d", &a.X, &a.Y);
        --a.X;
        --a.Y;
    }
    return 1;
}

void solve1(vector<ipair> &pos, vector<pair<ipair, ipair>> &ans1) {
    static bool occ[N][N];
    memset(occ, 0, sizeof(occ));
    for (ipair a : pos)
        occ[a.X][a.Y] = 1;

    vector<ipair> order(m);
    for (int i = 0; i < m; ++i)
        order[i] = {pos[i].X, i};
    sort(all(order));
    vector<int> nx(m);
    for (int i = 0; i < m; ++i)
        nx[order[i].Y] = i;

    while (true) {
        bool was = false;
        for (int i = 0; i < m; ++i) {
            int x1;
            if (pos[i].X == nx[i])
                continue;
            else if (pos[i].X > nx[i])
                x1 = pos[i].X - 1;
            else
                x1 = pos[i].X + 1;
            if (!occ[x1][pos[i].Y]) {
                occ[pos[i].X][pos[i].Y] = 0;
                occ[x1][pos[i].Y] = 1;
                ipair npos = {x1, pos[i].Y};
                ans1.push_back({pos[i], npos});
                pos[i] = npos;
                was = 1;
            }
        }
        if (!was)
            break;
    }

    for (int i = 0; i < m; ++i) {
        while (pos[i].Y > i) {
            ipair npos = {pos[i].X, pos[i].Y - 1};
            ans1.push_back({pos[i], npos});
            pos[i] = npos;
        }
        while (pos[i].Y < i) {
            ipair npos = {pos[i].X, pos[i].Y + 1};
            ans1.push_back({pos[i], npos});
            pos[i] = npos;
        }
    }
}

void solve() {
    vector<ipair> pos1 = spos;
    vector<ipair> pos2 = fepos;
    vector<pair<ipair, ipair>> ans1, ans3;
    solve1(pos1, ans1);
    solve1(pos2, ans3);
    
    reverse(all(ans3));
    for (auto &a : ans3)
        swap(a.X, a.Y);

    for (int i = 0; i < m; ++i) {
        while (pos1[i].X < pos2[i].X) {
            ipair npos = {pos1[i].X + 1, pos1[i].Y};
            ans1.push_back({pos1[i], npos});
            pos1[i] = npos;
        }
        while (pos1[i].X > pos2[i].X) {
            ipair npos = {pos1[i].X - 1, pos1[i].Y};
            ans1.push_back({pos1[i], npos});
            pos1[i] = npos;
        }
    }

    assert(pos1 == pos2);
    assert(sz(ans1) + sz(ans3) <= 10800);
    cout << sz(ans1) + sz(ans3) << "\n";
    for (auto a : ans1)
        cout << a.X.X + 1 << " " << a.X.Y + 1 << " " << a.Y.X + 1 << " " << a.Y.Y + 1 << "\n";
    for (auto a : ans3)
        cout << a.X.X + 1 << " " << a.X.Y + 1 << " " << a.Y.X + 1 << " " << a.Y.Y + 1 << "\n";
}

int main() {
#ifdef LOCAL
    assert(freopen("b.in", "r", stdin));
#endif

    while (read()) {
        solve();
    }

    return 0;
}