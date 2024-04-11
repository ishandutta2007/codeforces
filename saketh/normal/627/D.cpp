#include <bits/stdc++.h>
#define TRACE(x) x
using namespace std;

typedef long long ll;

const int MAXN = 2e5 + 100;
const int MAXE = 4e5 + 100;

int N, L;
int val[MAXN];

vector<int> adj[MAXN];
int u[MAXE], v[MAXE];

bool allow[MAXN];
int as_root[MAXN];

int path[MAXE];
bool comp[MAXE];

void do_rev(int loc, int par, int inc) {
    int comp_nbrs = 0;
    int total = 0;
    vector<pair<int, int>> incomp;

    for (int e : adj[loc]) {
        if (comp[e]) {
            comp_nbrs++;
            total += path[e];
        } else {
            incomp.emplace_back(path[e], e);
        }
    }

    sort(incomp.begin(), incomp.end());
    reverse(incomp.begin(), incomp.end());

    if (allow[loc]) {
        as_root[loc] = 1 + total;
        if (incomp.size()) as_root[loc] += incomp.begin()->first;
    } else {
        as_root[loc] = 0;
    }

    for (int e : adj[loc]) {
        int solve = e^1;
        if (solve == inc) continue;

        if (!allow[loc]) {
            comp[solve] = false;
            path[solve] = 0;
        }
        else if (comp[e]) {
            if (incomp.size()) {
                comp[solve] = false;
                path[solve] = 1 + total - path[e] + incomp.begin()->first;
            } else {
                comp[solve] = true;
                path[solve] = 1 + total - path[e];
            }
        } else {
            if (incomp.size() == 1) {
                comp[solve] = true;
                path[solve] = 1 + total;
            } else {
                comp[solve] = false;

                int idx = incomp[0].second == e ? 1 : 0;
                path[solve] = 1 + total + incomp[idx].first;
            }
        }
    }

    for (int e : adj[loc]) {
        if (v[e] == par) continue;
        do_rev(v[e], loc, e);
    }
}

void do_it(int loc, int par, int inc) {
    bool all = true;
    int total = 1;
    vector<int> incomp;

    for (int e : adj[loc]) {
        int nbr = v[e];
        if (nbr == par) continue;

        do_it(nbr, loc, e);

        if (comp[e]) {
            total += path[e];
        } else {
            all = false;
            incomp.push_back(path[e]);
        }
    }

    if (inc != -1) {
        if (!allow[loc]) {
            comp[inc] = false;
            path[inc] = 0;
        }
        else if (all) {
            comp[inc] = true;
            path[inc] = total;
        } else {
            comp[inc] = false;

            sort(incomp.begin(), incomp.end(), greater<int>());
            path[inc] = total + incomp[0];
        }
    } else {
        do_rev(0, 0, -1);
    }
}

bool check(int score) {
    for (int i = 0; i < N; i++) {
        allow[i] = val[i] >= score;
    }

    do_it(0, 0, -1);

    for (int i = 0; i < N; i++) {
        if (as_root[i] >= L) {
            return true;
        }
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0), cout.precision(15);

    cin >> N >> L;

    for (int i = 0; i < N; i++) {
        cin >> val[i];
    }

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        adj[a].push_back(2 * i);
        adj[b].push_back(2 * i + 1);

        u[2 * i] = a;
        u[2 * i + 1] = b;

        v[2 * i] = b;
        v[2 * i + 1] = a;
    }

    int ans = 1;
    int lo = 2, hi = 1000000;

    while (lo <= hi) {
        int mi = (lo + hi) / 2;

        if (check(mi)) {
            ans = mi;
            lo = mi + 1;
        } else {
            hi = mi - 1;
        }
    }

    cout << ans << "\n";
    return 0;
}