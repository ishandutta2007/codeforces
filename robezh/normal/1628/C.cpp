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


const int N = 1005, B = 30;

int n, a[N][N], res[N][N];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};

bool in_bound(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) {
            rep(j, 0, n) cin >> a[i][j];
        }
        int fres = 0;
        rep(i, 0, n - 1) {
            rep(j, 0, n) {
                int sum = a[i][j];
                rep(d, 1, 4) {
                    int di = i + dx[d], dj = j + dy[d];
                    if(in_bound(di, dj)) sum ^= res[di][dj];
                }
                res[i + 1][j] = sum;
            }
        }
        rep(i, 1, n) {
            rep(j, 0, n) fres ^= res[i][j];
        }
        cout << fres << '\n';

    }
}