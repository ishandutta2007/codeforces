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
const int N = (int)1e5 + 50, INF = (int)1e9;

int n;
string A, B;

int geven() {
    int c0 = 0, c1 = 0;
    rep(i, 0, n) {
        c0 += A[i] == '1' && B[i] == '0';
        c1 += A[i] == '0' && B[i] == '1';
    }
    if(c0 == c1) return c0 + c1;
    else return INF;
}

int godd() {
    rep(i, 0, n) {
        B[i] = (B[i] == '1' ? '0' : '1');
    }
    int c0 = 0, c1 = 0;
    rep(i, 0, n) {
        c0 += A[i] == '1' && B[i] == '0';
        c1 += A[i] == '0' && B[i] == '1';
    }
    if(c0 == c1 + 1) return c0 + c1;
    else return INF;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        cin >> A >> B;
        int r0 = geven();
        int r1 = godd();
        int res = min(r0, r1);
        if(res == INF) cout << -1 << "\n";
        else cout << res << '\n';
    }

}