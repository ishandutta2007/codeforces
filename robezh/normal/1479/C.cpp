#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
#define Lnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

struct edge {
    int u, v, cost;
};

int l, r;
int n = 32;
vector<edge> es;

void add_edge(int u, int v, int cost) {
    es.push_back({u, v, cost});
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> l >> r;
    for (int i = 2; i <= 21; i++) {
        for (int j = 1; j < i; j++) {
            add_edge(j, i, 1 << max(0, j - 2));
        }
    }
    int off = l - 1;
    l -= off, r -= off;
    int s = 0;
    n = 22;
    add_edge(1, n, 1), s++;
    for (int i = 2; i <= 21; i++) {
        if((r - s) >> (i - 2) & 1) {
            add_edge(i, n, s);
            s += (1 << (i - 2));
        }
    }
    cout << "YES\n";
    cout << n << " " << sz(es) << '\n';
    for (auto &e : es) {
        if(e.u == 1) e.cost += off;
        cout << e.u << " " << e.v << " " << e.cost << '\n';
    }
}