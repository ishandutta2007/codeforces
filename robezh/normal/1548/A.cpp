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

const int N = (int)2e5 + 50;

int n, m;
int cnt[N];
int tot = 0;

void add(int u, int v, int add) {
    if(u > v) swap(u, v);
    tot -= (cnt[u] == 0);
    cnt[u] += add;
    tot += (cnt[u] == 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    tot = n;
    rep(i, 0, m) {
        int u, v; cin >> u >> v; u--, v--;
        add(u, v, 1);
    }
    int q;
    cin >> q;
    while(q--) {
        int tp; cin >> tp;
        if(tp == 3) {
            cout << tot << '\n';
        } else {
            int u, v; cin >> u >> v; u--, v--;
            add(u, v, (tp == 1 ? 1 : -1));
        }
    }

}