#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

#define TRACE(x) x
#define WATCH(x) TRACE(cout << #x" = " << x << endl)
#define WATCHR(a, b) TRACE(for (auto it=a; it!=b;) cout << *(it++) << " "; cout << endl)
#define WATCHC(V) TRACE({cout << #V" = "; WATCHR(V.begin(), V.end());})

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

struct union_find {
    vector<int> P, R, S;
    vll fsum;
    
    union_find (int N, vll &vals) {
        P.resize(N), R.resize(N, 0), S.resize(N, 1);
        for (int i = 0; i < N; i++)
            P[i] = i;

        fsum = vals;
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
        fsum[a] += fsum[b];
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

    vll vals(N + 1);
    vi perm(N + 1);

    for (int i = 1; i <= N; i++) 
        cin >> vals[i];

    for (int i = 1; i <= N; i++) {
        cin >> perm[i];
    }

    vll ans(N + 2, 0);

    union_find uf(N + 1, vals);
    vector<bool> pres(N + 2, false);

    for (int inx = N; inx >= 1; inx--) {
        int put = perm[inx];

        pres[put] = true;
        if (pres[put + 1])
            uf.unio(put, put + 1);
        if (pres[put - 1])
            uf.unio(put, put - 1);

        ans[inx] = max(ans[inx + 1], uf.fsum[uf.rep(put)]);
    }

    for (int i = 2; i <= N; i++) 
        cout << ans[i] << "\n";
    cout << 0 << "\n";
    return 0;
}