#include <bits/stdc++.h>
using namespace std;

#define TRACE(x)
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

const int MAXN = 200000;
const int MAXK = 5;

int K;

ll total[MAXN];
ll quant[MAXN * MAXK];

ll all = 0;
ll counts[MAXK], tmp[MAXK];

// extend all the paths in inx by length add
void extend(int inx, int add) {
    for (int i = 0; i < K; i++) {
        tmp[i] = 0;
        total[inx] += ll(add) * quant[K * inx + i];
    }

    for (int i = 0; i < K; i++) {
        int n = (i + add) % K;
        tmp[n] = quant[K * inx + i];
    }

    for (int i = 0; i < K; i++) {
        quant[K * inx + i] = tmp[i];
    }
}

// add all the paths from inx2 to inx1
void combine(int inx1, int inx2) {
    // record all the paths rooted here!
    for (int a = 0; a < K; a++) {
        for (int b = 0; b < K; b++) {
            counts[(a+b)%K] += quant[inx1 * K + a] * quant[inx2 * K + b];
        }
        all += total[inx1] * quant[inx2 * K + a];
        all += total[inx2] * quant[inx1 * K + a];
    }

    total[inx1] += total[inx2];

    for (int i = 0; i < K; i++) {
        quant[K * inx1 + i] 
            += quant[K * inx2 + i];
    }
}

void go(int loc, int par, vvi &adj) {
    bool child = false;
    for (int nbr : adj[loc]) {
        if (nbr == par) continue;
        child = true;
        go(nbr, loc, adj);

        extend(nbr, 1);
        combine(loc, nbr);
    }

    quant[loc * K + 0]++;

    all += total[loc];
    for (int i = 0; i < K; i++)
        counts[i] += quant[loc * K + i];

    TRACE(
        cout << "The vertical paths rooted at " << loc << " have total length " << total[loc] << endl;
        for (int i = 0; i < K; i++) {
            cout << quant[loc * K + i] << " of them have length " << i << " mod K" << endl;
        }
    );

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N >> K;

    vvi adj(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    go(0, 0, adj);

    for (int i = 1; i < K; i++)
        all += counts[i] * (ll(K) - i);
    cout << all/K << endl;

    return 0;
}