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

const int MAXN = 5e5;
int P[MAXN], R[MAXN], S[MAXN];

void reset(int N) {
    for (int i = 0; i < N; i++)
        P[i] = i;
    fill(R, R+N, 0);
    fill(S, S+N, 1);
}

int rep(int i) {
    if(P[i] != i) P[i] = rep(P[i]);
    return P[i];
}

bool unio(int a, int b) {
    a = rep(a), b = rep(b);
    if(a == b) return false;
    if(R[a] < R[b]) swap(a, b);
    P[b] = a;
    S[a] += S[b];
    if(R[a] == R[b]) R[a]++;
    return true;
}

const int MAXN2 = MAXN + MAXN;
int nodes[MAXN2];

struct g {
    vi eu, ev;
    void edge(int u, int v) {
        eu.push_back(u);
        ev.push_back(v);
    }
    int cc(int N) {
        int M = 0;
        for (int v : eu)
            nodes[M++] = v;
        for (int v : ev)
            nodes[M++] = v;
        sort(nodes, nodes + M);
        M = unique(nodes, nodes + M) - nodes;

        reset(M);
        for (int i = 0; i < eu.size(); i++) {
            int u = lower_bound(nodes, nodes + M, eu[i]) - nodes;
            int v = lower_bound(nodes, nodes + M, ev[i]) - nodes;
            N -= unio(u, v);
        }

        return N;
    }
};

const int MOD = 1e9 + 7;
int sum(int a, int b) { return (a + b) % MOD; }
int diff(int a, int b) { return (a + MOD - b) % MOD; }
int prod(int a, int b) { return a * 1ll * b % MOD; }
int pow2[MAXN + 1];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    pow2[0] = 1;
    for (int i = 1; i <= MAXN; i++)
        pow2[i] = prod(2, pow2[i-1]);

    int N, M, K;
    cin >> N >> M >> K;

    vll c(N);
    for (int i = 0; i < N; i++)
        cin >> c[i];

    map<ll, g> graphs;
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        graphs[c[u] ^ c[v]].edge(u, v);
    }

    ll rest = diff(pow2[K], graphs.size());
    ll ans = prod(rest, pow2[N]);
    for (auto &[v, g] : graphs) {
        ans = sum(ans, pow2[g.cc(N)]);
    }
    cout << ans << endl;

    return 0;
}