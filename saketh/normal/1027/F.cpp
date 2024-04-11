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
    vector<int> P, R, S, E, M;

    union_find(int N) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1), E.resize(N, 0);
        for (int i = 0; i < N; i++)
            P[i] = i;
        M = P;
    }

    int rep(int i) {
        if(P[i] != i) P[i] = rep(P[i]);
        return P[i];
    }

    bool unio(int a, int b) {
        a = rep(a), b = rep(b);
        if(a == b) {
            E[a]++;
            return false;
        }
        if(R[a] < R[b]) swap(a, b);
        P[b] = a;
        S[a] += S[b];
        if(R[a] == R[b]) R[a]++;
        E[a] += E[b] + 1;
        M[a] = max(M[a], M[b]);
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;
    vi a(N), b(N), vals(2 * N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
        vals[2 * i] = a[i];
        vals[2 * i + 1] = b[i];
    }

    sort(all(vals));
    vals.erase(unique(all(vals)), vals.end());
    vi ca(N), cb(N);
    for (int i = 0; i < N; i++) {
        ca[i] = lower_bound(all(vals), a[i]) - vals.begin();
        cb[i] = lower_bound(all(vals), b[i]) - vals.begin();
    }

    union_find uf(vals.size());
    for (int i = 0; i < N; i++) {
        uf.unio(ca[i], cb[i]);
    }

    int ans = 0;
    for (int i = 0; i < vals.size(); i++) {
        if (i != uf.M[uf.rep(i)])
            ans = max(ans, i);

        if (i != uf.rep(i)) {
            continue;
        }

        if (uf.E[i] > uf.S[i]) {
            cout << -1 << endl;
            return 0;
        }

        if (uf.E[i] == uf.S[i]) {
            ans = max(ans, uf.M[i]);
        }
    }

    cout << vals[ans] << endl;
    return 0;
}