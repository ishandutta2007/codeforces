#include <bits/stdc++.h>
#include<bits/extc++.h>

using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)1e5 + 50;


int n, a[N];
int ps[N];

int gsum(int l, int r) {
    return ps[r] ^ (l ? ps[l - 1] : 0);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        ps[i] = a[i];
        if(i > 0) ps[i] ^= ps[i - 1];
    }

    for(int i = 0; i + 1 < n; i++) {
        int x = a[i] ^ a[i + 1];
        if((i > 0 && a[i - 1] > x) || (i + 2 < n && x > a[i + 2])) return cout << 1 << endl, 0;
    }
    assert(n <= 100);
    int res = N;
    for(int l = 0; l < n; l++) {
        for(int r = l + 1; r < n; r++) {
            for(int m = l; m + 1 <= r; m++) {
                if(gsum(l, m) > gsum(m + 1, r)) res = min(res, r - l - 1);
            }
        }
    }
    if(res == N) res = -1;
    cout << res << '\n';

}