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

    srand(time(NULL));

    const int MAXN = 1e6;
    vll pow(MAXN);
    pow[0] = 1;
    for (int i = 1; i < MAXN; i++)
        pow[i] = pow[i-1] * 10003;

    int N, M;
    cin >> N >> M;

    vvi g(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        g[u-1].push_back(v-1);
        g[v-1].push_back(u-1);
    }

    ll ans = 0;
    unordered_map<ll, ll> ct, ctl;

    for (int i = 0; i < N; i++) {
        ll h = 0;
        for (int j : g[i])
            h += pow[j];
        ans += ct[h]++;

        h += pow[i];
        ans += ctl[h]++;
    }

    cout << ans << endl;
    return 0;
}