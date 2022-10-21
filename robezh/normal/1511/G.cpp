#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int N = (int)2e5 + 50, LOGN = 20, P = 512;

int n, m;
int in[N];
int rsum[LOGN][N];
int psum[N];


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    rep(i, 1, n + 1) {
        int a; cin >> a;
        in[a] ^= 1;
    }
    rep(i, 1, m + 1) psum[i] = psum[i - 1] + in[i];

    rep(i, 1, m + 1) rsum[0][i] = 0;
    rep(p, 1, LOGN) {
        for(int i = 0; i + (1 << p) - 1 <= m; i++) {
            rsum[p][i] = rsum[p - 1][i] ^ rsum[p - 1][i + (1 << (p - 1))];
            if((psum[i + (1 << p) - 1] - psum[i + (1 << (p - 1)) - 1]) % 2 == 1)
                rsum[p][i] ^= (1 << (p - 1));
        }
    }

    int q;
    cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;
        int nim = 0;
        for(int p = LOGN - 1; p >= 0; p--) {
            if(r - l + 1 >= (1 << p)) {
                nim ^= rsum[p][l];
                l += (1 << p);
                if((psum[r] - psum[l - 1]) % 2 == 1) nim ^= (1 << p);
            }
        }
        cout << (nim == 0 ? "B" : "A");
    }
    cout << endl;

}