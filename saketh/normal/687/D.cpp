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

const int MAXN = 1e3 + 5;

int rep[MAXN];
bool col[MAXN];

int siz[MAXN];
int fam[MAXN][MAXN];

struct union_find {
    union_find (int N) {
        for (int i = 0; i < N; i++) {
            rep[i] = i;
            col[i] = false;

            siz[i] = 1;
            fam[i][0] = i;
        }
    }
    
    bool unio(int a, int b) {
        bool flip = col[a] == col[b];
        a = rep[a], b = rep[b];
        
        if (siz[a] < siz[b]) swap(a, b);

        for (int i = 0; i < siz[b]; i++) {
            int v = fam[b][i];
            col[v] = col[v] ^ flip;
            rep[v] = a;

            fam[a][siz[a]++] = v;
        }

        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M, Q;
    scanf("%d %d %d", &N, &M, &Q);

    vector<int> u(M), v(M), w(M);

    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &u[i], &v[i], &w[i]);
        u[i]--, v[i]--;
    }

    vector<int> l(Q), r(Q), ans(Q);

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &l[i], &r[i]);
        l[i]--, r[i]--;
    }

    vector<int> inx(M);
    for (int i = 0; i < M; i++)
        inx[i] = i;

    sort(inx.begin(), inx.end(), [&](int i, int j) {
        return w[i] > w[j];
    });

    for (int q = 0; q < Q; q++) {
        union_find uf(N);
        for (int e : inx) {
            if (ans[q]) break;
            if (l[q] > e || r[q] < e) continue;

            if (rep[u[e]] == rep[v[e]]) {
                if (col[u[e]] == col[v[e]])
                    ans[q] = w[e];
            } else {
                uf.unio(u[e], v[e]);
            }
        }
    }

    for (int v : ans) {
        printf("%d\n", v ? v : -1);
    }

    return 0;
}