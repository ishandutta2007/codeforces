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

const int N = (int)2e5 + 50, B = 450;

int ad[N];
int rem_add[B][B];
int n, m;
int at[N];

void add(int x, int y, int idx, int cur, int add) {
    int t = cur;
    if(add == 1) at[idx] = cur;
    else {
        t = at[idx];
    }

    if(x + y >= B) {

        for (int i = t; i < m; i += (x + y)) {
            ad[max(cur, i)] += add;
            ad[max(min(i + x, m), cur)] -= add;
        }
    } else {

        for (int i = t % (x + y), j = 0; j < x; j++, (i += 1) %= (x + y)) {
            rem_add[x + y][i] += add;
        }
    }
}

int x[N], y[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    int cur = 0;
    rep(i, 0, n) cin >> x[i] >> y[i];
    int tot = 0;
    rep(i, 0, m) {
        int op, k; cin >> op >> k; k--;
        add(x[k], y[k], k, i, (op == 1 ? 1 : -1));
        tot += (op == 1 ? 1 : -1);
        cur += ad[i];
        int res = cur;
        rep(r, 1, B) res += rem_add[r][i % r];
        cout << tot - res << '\n';
    }
}