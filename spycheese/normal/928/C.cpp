#include <bits/stdc++.h>

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define fst first
#define snd second

using namespace std;

using vi = vector<int>;
using ll = long long;
using pii = pair<int, int>;

#define FNAME "a"

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(args...) ;
#endif

struct Proj {
    string name;
    int version;

    bool read() {
        if (!(cin >> name)) {
            return 0;
        }
        if (scanf("%d", &version) != 1) {
            return 0;
        }    

        return 1;
    }

    void print() {
        cout << name;
        printf(" %d\n", version);
    }

    bool operator<(const Proj &p) const {
        if (name != p.name) {
            return name < p.name;
        }
        return version > p.version;
    }
};

const int MAXN = (int)1e3 + 11;

int n;
Proj p[MAXN];
vector<Proj> deps[MAXN];
vi g[MAXN];
int len[MAXN];
map<Proj, int> proj_id;

bool read() {
    if (!(cin >> n)) {
        return 0;
    }
    forn(i, n) {
        deps[i].clear();
        g[i].clear();
    }
    proj_id.clear();

    forn(i, n) {
        assert(p[i].read());
        proj_id[p[i]] = i;

        int d;
        scanf("%d", &d);
        deps[i].clear();
        deps[i].resize(d);
        forn(j, d) {
            assert(deps[i][j].read());    
        }
    }

    return 1;
}

map<string, int> used_names;

vector<Proj> solve() {
    forn(i, n) {
        forn(j, sz(deps[i])) {
            g[i].pb(proj_id[deps[i][j]]);
        }
    }

    static const int INF = (int)1e9;
    forn(i, n) {
        len[i] = +INF;
    }
    set<pair<int, Proj>> q;

    len[0] = 0;
    q.insert(mp(len[0], p[0]));

    used_names.clear();

    while (!q.empty()) {
        int pid = proj_id[q.begin()->snd];
        q.erase(q.begin());

        // add project
        string name = p[pid].name;
        if (used_names.count(name) > 0) {
            continue;
        }
        used_names[name] = pid; 

        for (auto qid: g[pid]) {
            if (len[qid] == INF) {
                len[qid] = len[pid] + 1;
                q.insert(mp(len[qid], p[qid]));
            }
        }
    }

    vector<Proj> ans;
    for (auto e: used_names) {
        if (e.snd != 0) {
            ans.pb(p[e.snd]);
        }
    }
    sort(all(ans));

    return ans;
}

int main() {
#ifdef LOCAL
    freopen(FNAME ".in", "r", stdin);
    freopen(FNAME ".out", "w", stdout);
#endif

    while (read()) {
        auto ans = solve();
        cout << sz(ans) << '\n';
        for (auto &p: ans) {
            p.print();
        }
    }

    return 0;
}