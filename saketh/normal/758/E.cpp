#include <bits/stdc++.h>
using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;

tuple<ll, ll, list<int>> solve(vvi &adj, vi &u, vi &v, vi &w, vi &s, vi &r, int loc, int par) {
    ll max_weight = 0, removable = 0;
    list<int> order;

    for (int e : adj[loc]) {
        int nbr = u[e] + v[e] - loc;
        if (nbr == par) continue;

        ll child_max, child_rem;
        list<int> child_order;
        tie(child_max, child_rem, child_order) = solve(adj, u, v, w, s, r, nbr, loc);

        if (child_max - child_rem > s[e]) {
            cout << -1 << "\n";
            exit(0);
        }

        while (child_max > s[e]) {
            int rem = child_order.front();
            child_order.pop_front();

            ll take = min(ll(r[rem]), child_max - s[e]);
            child_max -= take;
            child_rem -= take;
            w[rem] -= take;
            s[rem] -= take;
            r[rem] -= take;

            if (r[rem] > 0) {
                child_order.push_front(rem);
                break;
            }
        }

        ll rem_e = min(w[e] - 1, s[e]);
        rem_e = min(rem_e, s[e] - (child_max - child_rem));
        r[e] = rem_e;

        max_weight += child_max + w[e];
        removable += child_rem + rem_e;
        child_order.push_back(e);

        order.splice(order.end(), child_order);
    }

    return make_tuple(move(max_weight), move(removable), move(order));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cout << fixed << setprecision(15);

    int N;
    cin >> N;

    vvi adj(N);
    vi u(N-1), v(N-1), w(N-1), s(N-1);

    for (int e = 0; e < N - 1; e++) {
        cin >> u[e] >> v[e] >> w[e] >> s[e];
        u[e]--, v[e]--;
        adj[u[e]].push_back(e);
        adj[v[e]].push_back(e);
    }

    vi rem(N - 1);
    solve(adj, u, v, w, s, rem, 0, 0);

    cout << N << "\n";
    for (int e = 0; e < N - 1; e++) {
        cout << u[e] + 1 << " " << v[e] + 1 << " " << w[e] << " " << s[e] << "\n";
    }

    return 0;
}