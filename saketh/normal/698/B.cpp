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
    
    union_find (int N) {
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

    vector<int> p(N + 1);
    union_find uf(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        uf.unio(i, p[i]);
    }

    vector<bool> seen(N + 1, false),
                 didf(N + 1, false);

    vector<pair<bool, int>> isl;

    for (int i = 1; i <= N; i++) {
        int fam = uf.rep(i);
        if (didf[fam]) continue;
        didf[fam] = true;

        int tmp = i;
        while (!seen[tmp]) {
            seen[tmp] = true;
            tmp = p[tmp];
        }

        isl.emplace_back(p[tmp] != tmp, tmp);
    }

    sort(isl.begin(), isl.end());

    vector<int> ans = p;

    if (!isl[0].first) {
        cout << isl.size() - 1 << "\n";
    } else {
        cout << isl.size() << "\n";
    }
    
    for (int i = 0; i < isl.size(); i++)
        ans[isl[i].second] = isl[0].second;

    for (int i = 1; i <= N; i++)
        cout << ans[i] << " ";
    cout << "\n";

    return 0;
}