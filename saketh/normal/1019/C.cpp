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

    vvi adj(N);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    vb removed(N);
    vi order;
    for (int i = 0; i< N; i++) {
        if (!removed[i]) {
            removed[i] = true;
            for (int j : adj[i])
                removed[j] = true;
            order.push_back(i);
        }
    }

    reverse(all(order));

    vb in(N);
    vi ans;
    for (int i : order) {
        if (in[i]) continue;
        ans.push_back(i);
        for (int j : adj[i])
            in[j] = true;
    }

    cout << ans.size() << endl;
    for (int i : ans)
        cout << i + 1 << " ";
    cout << endl;

    return 0;
}