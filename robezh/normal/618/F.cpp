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

const int N = (int)1e6 + 50;

int n;
bool swapped;
ll a[N], b[N];

void output(int al, int ar, int bl, int br) {
    if(swapped) {
        swap(al, bl);
        swap(ar, br);
    }
    cout << ar - al + 1 << '\n';
    rep(i, al, ar + 1) cout << i << " ";
    cout << '\n';
    cout << br - bl + 1 << "\n";
    rep(i, bl, br + 1) cout << i << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i], a[i] += a[i - 1];
    rep(i, 1, n + 1) cin >> b[i], b[i] += b[i - 1];
    map<ll, pii> las;
    if(a[n] >= b[n]) {
        rep(i, 0, n + 1) swap(a[i], b[i]);
        swapped = true;
    }
    rep(i, 0, n + 1) {
        int j = lower_bound(b, b + n + 1, a[i]) - b;
        auto it = las.find(b[j] - a[i]);
//        cout << b[j] - a[i] << endl;
        if(it != las.end()) {
            output(it->second.first + 1, i, it->second.second + 1, j);
            return 0;
        }
        las[b[j] - a[i]] = {i, j};
    }
    assert(false);


}