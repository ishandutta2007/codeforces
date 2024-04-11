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
const int N = (int)1e5 + 50;

int n, x;
int a[N], b[N];


bool solve() {
    cin >> n >> x;
    rep(i, 0, n) cin >> a[i], b[i] = a[i];
    sort(b, b + n);
    rep(i, 0, n) {
        if(i < x && n - 1 - i < x && b[i] != a[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }

}