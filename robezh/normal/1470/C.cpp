#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;

int n, k;

ll ask(int p) {
    cout << "? " << p + 1 << endl;
    fflush(stdout);
    ll x; cin >> x;
    return x;
}

int main() {
    cin >> n >> k;
    
    int cur = 0;
    rep(it, 0, N) {
        if (ask(cur) < k) {
            break;
        }
        cur += min(n / 2 - 1, 1 + it);
        cur %= n;
    }
    cur++;
    cur %= n;
    while (ask(cur) < k) cur++, cur %= n;

    cout << "! " << cur + 1 << '\n';
}