#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = 105;

int n, m;
int xorsum[N * 2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin  >> T;
    while(T--) {
        cin >> n >> m;
        memset(xorsum, 0, sizeof(xorsum));
        rep(i, 0, n) {
            rep(j, 0, m) {
                int x; cin >> x;
                xorsum[i + j] ^= x;
            }
        }
        int nonzero = 0;
        rep(i, 0, n + m - 1) nonzero |= (xorsum[i] != 0);
        cout << (nonzero ? "Ashish" : "Jeel") << '\n';
    }


}