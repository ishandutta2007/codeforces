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

const int N = 1005;

int n, k;
int rs[N][N];
int mxc = 0;

void color(int l, int r, int col) {
    if(r - l <= 1) return;
    int len = r - l;
    if(r - l >= 2) mxc = max(mxc, col);
    int d = len / k, rem = len % k;
    int c = l;
    for (int i = 0; i < k; i++) {
        int clen = (i < rem) + d;
        for (int j = c; j < c + clen; j++) {
            for (int q = l; q < c; q++) rs[q][j] = col;
        }
        color(c, c + clen, col + 1);
        c += clen;
    }

}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> k;
    color(0, n, 1);
    cout << mxc << endl;
    rep(i, 0, n) rep(j, i + 1, n) cout << rs[i][j] << " ";
    cout << endl;


}