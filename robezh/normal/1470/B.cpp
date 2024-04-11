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


const int N = (int)3e5 + 50, M = (int)1e6 + 50;

int sq[M];

int n;



int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    iota(sq, sq + M, 0);
    rep(i, 1, M) {
        if(sq[i] != i) continue;
        for (int j = 1; 1LL * j * j * i < M; j++) {
            sq[j * j * i] = min(sq[j * j * i], i);
        }
    }
//    rep(i, 1, 50) cout << i << ": " << sq[i] << "\n";
//    cout << endl;

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        map<int, int> mp;
        rep(i, 0, n) {
            int x; cin >> x;
            mp[sq[x]]++;
        }
        int mx0 = 0, mxodd = 0, sumeven = 0;
        for(auto &p : mp) {
            mx0 = max(mx0, p.second);
            if(p.second % 2 == 1 && p.first != 1) mxodd = max(mxodd, p.second);
            else sumeven += p.second;
        }
        int q;
        cin >> q;
        while(q--) {
            ll w; cin >> w;
            if(w == 0) cout << mx0 << '\n';
            else cout << max(sumeven, mxodd) << '\n';
        }
    }
}