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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vector<ll> weight(M);
    for (int i = 0; i < M; i++)
        cin >> weight[i];

    vector<ll> diff(M);
    for (int i = 0; i < M; i++)
        cin >> diff[i];

    vector<bool> mst(M);
    vector<int> change(M);
    vector<int> u(M), v(M);

    vvi adj(N);
    for (int i = 0; i < M; i++) {
        cin >> u[i] >> v[i];
        u[i]--, v[i]--;
        adj[u[i]].push_back(i);
        adj[v[i]].push_back(i);
    }

    ll S;
    cin >> S;

    vector<int> order(M);
    for (int i = 0; i < M; i++)
        order[i] = i;
    sort(all(order), [&](int i, int j) { return weight[i] < weight[j]; });

    vi where(N);
    vvi fam(N);
    for (int i = 0; i < N; i++) {
        where[i] = i;
        fam[i].push_back(i);
    }

    for (int e : order) {
        int ue = u[e];
        int ve = v[e];

        if (where[ue] == where[ve]) continue;
        mst[e] = true;

        if (fam[where[ue]].size() > fam[where[ve]].size())
            swap(ue, ve);

        for (int vert : fam[where[ue]]) {
            for (int edge : adj[vert]) {
                int oth = u[edge] + v[edge] - vert;
                if (where[oth] == where[ve]) {
                    change[edge] = e;
                }
            }
        }

        for (int vert : fam[where[ue]]) {
            where[vert] = where[ve];
            fam[where[ve]].push_back(vert);
        }
    }

    ll total = 0;

    ll save = 0;
    int red = -1, rep = -1;

    for (int e = 0; e < M; e++) {
        if (mst[e]) {
            total += weight[e];
            ll could = S / diff[e];
            if (could > save) {
                save = could;
                red = e;
                rep = -1;
            }
        } else {
            ll could = S / diff[e];
            could = weight[change[e]] - weight[e] + could;
            if (could > save) {
                save = could;
                red = e;
                rep = change[e];
            }
        }
    }

    cout << total - save << endl;
    for (int e = 0; e < M; e++) {
        if (e == red) {
            cout << e + 1 << " " << weight[e] - S / diff[e] << "\n";
        } else if (mst[e] && e != rep) {
            cout << e + 1 << " " << weight[e] << "\n";
        }
    }

    return 0;
}