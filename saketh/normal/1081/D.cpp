#include <bits/stdc++.h>
using namespace std;

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

#define all(x) (x).begin(), (x).end()

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vs = vector<string>;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct union_find {
    vi P, R, S, SP;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1), SP.resize(N, 0);
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
        SP[a] += SP[b];
        if(R[a] == R[b]) R[a]++;
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int N, M, K;
    cin >> N >> M >> K;

    union_find uf(N);
    for (int i = 0; i < K; i++) {
        int sp;
        cin >> sp;
        uf.SP[sp - 1] = 1;
    }

    if (K == 1) {
        cout << 0 << endl;
        return 0;
    }

    vector<array<int, 3>> edges(M);
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({ w, u - 1, v - 1 });
    }
    sort(all(edges));

    for (auto [w, u, v] : edges) {
        uf.unio(u, v);
        if (uf.SP[uf.rep(u)] == K) {
            for (int i = 0; i < K; i++) {
                cout << w << " ";
            }
            cout << endl;
            return 0;
        }
    }

    return 0;
}