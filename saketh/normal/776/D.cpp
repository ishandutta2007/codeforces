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

void go(int loc, int put, vi &color, vvi &adj, vvi &edges, vi &init) {
    if (color[loc]) return;
    color[loc] = put;
    for (int door : adj[loc]) {
        int nbr = edges[door][0] + edges[door][1] - loc;
        if (init[door]) go(nbr, put, color, adj, edges, init);
        else go(nbr, 3 - put, color, adj, edges, init);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N, M;
    cin >> N >> M;

    vi init(N);
    for (int i = 0; i < N; i++) {
        int state;
        cin >> state;
        init[i] = state;
    }

    vvi edges(N);
    vvi adj(M);

    for (int i = 0; i < M; i++) {
        int ct;
        cin >> ct;

        for (int e = 0; e < ct; e++) {
            int door;
            cin >> door;
            door--;

            adj[i].push_back(door);
            edges[door].push_back(i);
        }
    }

    for (int i = 0; i < N; i++) {
        assert(edges[i].size() == 2);
    }

    // color all the switches
    vi color(M, 0);
    for (int i = 0; i < M; i++) {
        if (color[i]) continue;
        go(i, 1, color, adj, edges, init);
    }

    bool works = true;
    for (int door = 0; door < N; door++) {
        int s1 = edges[door][0],
            s2 = edges[door][1];

        if (init[door]) works &= (color[s1] == color[s2]);
        else works &= (color[s1] != color[s2]);
    }

    cout << (works ? "YES" : "NO") << endl;
    return 0;
}