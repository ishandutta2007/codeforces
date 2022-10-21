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

const int N = 105;

int n, a[N], b[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        rep(i, 0, n) cin >> b[i];
        sort(a, a + n);
        sort(b, b + n);
        bool good = true;
        rep(i, 0, n) good &= (b[i] - a[i] == 1 || b[i] == a[i]);
        cout << (good ? "YES" : "NO") << '\n';
    }
}