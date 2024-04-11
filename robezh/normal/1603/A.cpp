#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define subnb true
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 60;

int n, a[N], to[N];

int bit[N];

void add(int x, int val) {
    for(int i = x; i < n + 5; i |= i + 1) bit[i] += val;
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}


void solve() {
    cin >> n;
    rep(i, 1, n + 1) {
        cin >> a[i];
    }
    rep(i, 1, n + 1) {
        int c = i + 1;
        while(c >= 2 && a[i] % c == 0) {
            c--;
        }
        if(c == 1) {
            cout << "NO\n";
            return ;
        }
        to[i] = i + 1 - c;
//        cout << to[i] << " ";
    }
//    cout << endl;
    fill(bit, bit + n + 5, 0);
    rep(i, 1, n + 1) {
        if(to[i] > get(to[i] - 1)) {
            cout << "NO\n";
            return ;
        }
        add(to[i], 1);
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}