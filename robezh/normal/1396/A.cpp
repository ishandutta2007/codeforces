#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n;
int a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i];
    cout << "1 1\n";
    cout << -a[0] << '\n';
    if(n == 1) {
        cout << "1 1\n0\n";
        cout << "1 1\n0\n";
    } else {
        cout << 2 << " " << n << '\n';
        rep(i, 1, n) cout << 1LL * a[i] * (n - 1) << " ";
        cout << '\n';
        cout << 1 << " " << n << "\n";
        cout << 0 << " ";
        rep(i, 1, n) cout << -1LL * a[i] * n << " ";
    }

}