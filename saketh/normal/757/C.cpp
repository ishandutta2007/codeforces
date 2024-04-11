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

    vector<vector<pair<int, int>>> app(M);

    for (int g = 0; g < N; g++) {
        int S;
        cin >> S;

        vi poke(S);
        for (int i = 0; i < S; i++) {
            cin >> poke[i];
        }

        sort(all(poke));

        int i = 0;
        while (i < S) {
            int j = i;
            while (j < S && poke[i] == poke[j])
                j++;

            app[poke[i]-1].emplace_back(g, j - i);
            i = j;
        }
    }

    for (int i = 0; i < M; i++) {
        sort(all(app[i]));
    }

    const int MOD = 1e9 + 7;
    ll ans = 1;

    sort(all(app));
    int i = 0;
    while (i < M) {
        int j = i + 1;
        while (j < M && app[i] == app[j])
            j++;

        for (int k = j - i; k > 1; k--)
            ans = ans * k % MOD;
        i = j;
    }

    cout << ans << endl;
    return 0;
}