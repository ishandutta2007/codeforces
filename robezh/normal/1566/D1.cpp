#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)1e5 + 50;

int n, m;
int bit[N];

void add(int x, int val) {
    for(int i = x; i < m; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

pii p[N];
int a[N], b[N];
map<int, int> la;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        la.clear();
        fill(bit, bit + m + 1, 0);
        rep(i, 0, m) cin >> a[i], b[i] = a[i];
        sort(a, a + m);
        rep(i, 0, m) la[a[i]] = i;
        int res = 0;
        rep(i, 0, m) {
            res += get(la[b[i]]);
            add(la[b[i]], 1);
            la[b[i]]--;
        }
        cout << res << '\n';

    }

}