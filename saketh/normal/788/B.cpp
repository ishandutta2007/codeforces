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

struct union_find {
    vector<int> P, R, S;
    
    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;
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
};

ll nc2(ll v) {
    return v * (v - 1) / 2;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    union_find uf(N);

    int loops = 0;
    vi deg(N);
    vb has_edge(N);

    for (int e = 0; e < M; e++) {
        int u, v;
        cin >> u >> v;

        u--, v--;
        uf.unio(u, v);

        if (u == v) loops++;
        else {
            deg[u]++;
            deg[v]++;
        }

        has_edge[u] = true;
        has_edge[v] = true;
    }

    int ch = 0;
    while (!has_edge[ch]) ch++;

    int tot = 0;
    for (bool v : has_edge)
        if (v) tot++;

    if (uf.S[uf.rep(ch)] != tot) {
        cout << 0 << endl;
        return 0;
    }

    ll ans = 0;
    for (int i = 0; i < N; i++) {
        ans += nc2(deg[i]);
    }

    ans += nc2(loops);
    ans += loops * 1ll * (M - loops);

    cout << ans << endl;
    return 0;
}