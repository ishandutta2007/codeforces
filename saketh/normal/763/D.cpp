#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x)
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int sum(int a, int b, int m) { return (a + b) % m; }
int prod(int a, int b, int m) { return a * 1ll * b % m; }

const int NPRIME = 3;
const int BASE = 3001;
const int P1 = 1e9 + 7, P2 = 1e9 + 9, P3 = 1e9 + 21;
const int primes[3] = { P1, P2, P3 };

const int MAXL = 1e6;
vvi powers(NPRIME, vi(MAXL));

void init() {
    for (int p = 0; p < NPRIME; p++) {
        powers[p][0] = 1;
        for (int i = 1; i < MAXL; i++)
            powers[p][i] = (powers[p][i-1] * 1ll * BASE) % primes[p];
    }
}

struct hashed {
    int len;
    array<int, NPRIME> v;

    hashed() {
        len = 0;
        fill(all(v), 0);
    }
    hashed(char c) {
        len = 1;
        fill(all(v), c);
    }

    hashed operator+(const hashed &h) const {
        hashed res;
        res.len = len + h.len;
        for (int p = 0; p < NPRIME; p++) {
            res.v[p] = sum(prod(powers[p][h.len], v[p], primes[p]), h.v[p], primes[p]);
        }
        return res;
    }

    bool operator<(const hashed &h) const {
        return v < h.v;
    }

    bool operator==(const hashed &h) const {
        return v == h.v;
    }
};

// compute hashes for all the edges going away from the root
hashed dfs1(int loc, int par, vvi &adj, vi &u, vi &v, vector<hashed> &hashes) {
    vector<hashed> below;
    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (nbr == par) continue;
        hashes[e] = dfs1(nbr, loc, adj, u, v, hashes);
        below.push_back(hashes[e]);
    }

    sort(all(below));
    auto res = hashed('(');
    for (const hashed &h : below)
        res = res + h;
    res = res + hashed(')');

    return res;
}

// compute hashes for all the edges going towards the root
void dfs2(int loc, int par, vvi &adj, vi &u, vi &v, vector<hashed> &hashes) {
    vector<hashed> nbrs;
    for (int e : adj[loc]) {
        nbrs.push_back(hashes[e]);
    }

    sort(all(nbrs));

    vector<hashed> pref(nbrs.size());
    pref.front() = nbrs.front();
    for (int i = 1; i < nbrs.size(); i++) {
        pref[i] = pref[i-1] + nbrs[i];
    }

    vector<hashed> suff(nbrs.size());
    suff.back() = nbrs.back();
    for (int i = nbrs.size() - 2; i >= 0; i--) {
        suff[i] = nbrs[i] + suff[i + 1];
    }

    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (nbr == par) continue;

        int inx = lower_bound(all(nbrs), hashes[e]) - nbrs.begin();
        hashes[e^1] = hashed('(');
        if (inx) hashes[e^1] = hashes[e^1] + pref[inx - 1];
        if (inx + 1 < nbrs.size()) hashes[e^1] = hashes[e^1] + suff[inx + 1];
        hashes[e^1] = hashes[e^1] + hashed(')');

        dfs2(nbr, loc, adj, u, v, hashes);
    }
}

// put the hashes for all edges away from the root into the "map"
void dfs3(int loc, int par, vvi &adj, vi &u, vi &v, 
          vector<hashed> &hashes, vector<hashed> &comp, int &unique, vi &ct) {
    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (nbr == par) continue;

        int inx = lower_bound(all(comp), hashes[e]) - comp.begin();
        if (!ct[inx]) unique++;
        ct[inx]++;

        dfs3(nbr, loc, adj, u, v, hashes, comp, unique, ct);
    }
}

// traverse the tree and count unique subtrees from every root
void dfs4(int loc, int par, vvi &adj, vi &u, vi &v,
          vector<hashed> &hashes, vector<hashed> &comp, int &unique, vi &ct, vi &res) {
    res[loc] = unique;
    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (nbr == par) continue;

        int rem = lower_bound(all(comp), hashes[e]) - comp.begin();
        ct[rem]--;
        if (!ct[rem]) unique--;

        int add = lower_bound(all(comp), hashes[e^1]) - comp.begin();
        if (!ct[add]) unique++;
        ct[add]++;

        dfs4(nbr, loc, adj, u, v, hashes, comp, unique, ct, res);

        if (!ct[rem]) unique++;
        ct[rem]++;

        ct[add]--;
        if (!ct[add]) unique--;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    init();

    int N;
    cin >> N;

    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }

    vvi adj(N);
    vi u, v;

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(u.size());
        u.push_back(a);
        v.push_back(b);

        adj[b].push_back(u.size());
        u.push_back(b);
        v.push_back(a);
    }

    vector<hashed> hashes(u.size());
    dfs1(0, 0, adj, u, v, hashes);
    dfs2(0, 0, adj, u, v, hashes);

    TRACE(
        for (int e = 0; e < u.size(); e++) {
            cout << e << " " << u[e] << " " << v[e] << " " << hashes[e].v[0] << endl;
        }
    )

    vector<hashed> compress = hashes;
    sort(all(compress));
    compress.erase(unique(all(compress)), compress.end());

    int unique = 0;
    vi app(compress.size());

    dfs3(0, 0, adj, u, v, hashes, compress, unique, app);

    vi res(N);
    dfs4(0, 0, adj, u, v, hashes, compress, unique, app, res);

    WATCHC(res);

    int ans = 0;
    for (int i = 1; i < N; i++) {
        if (res[i] > res[ans])
            ans = i;
    }
    cout << ans + 1 << endl;

    return 0;
}