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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

struct union_find {
    vi P, R, S;

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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    union_find uf(N + 1);
    for (int v = 2; v <= N; v++) {
        for (int m = 2*v; m <= N; m += v)
            uf.unio(v, m);
    }

    map<int, ll> tot;
    for (int v = 2; v <= N; v++) {
        int fam = uf.rep(v);
        for (int m = 2*v; m <= N; m += v) {
            tot[fam] += m/v;
        }
    }

    ll ans = 0;
    for (auto [k, v] : tot)
        ans = max(ans, 4 * v);
    cout << ans << endl;

    return 0;
}