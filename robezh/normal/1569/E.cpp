#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)1e5 + 50, mod = 998244353;

vi rk[N];
ll Lhs[N], Rhs[N];
unordered_map<ll, int> mp;
ll win[N];
int k;
ll A, h;
ll pw[N];
vi cur[10];


ll fp(ll x, ll k) {
    if(k == 0) return 1;
    ll hf = fp(x, k / 2);
    return k % 2 == 0 ? hf * hf % mod : hf * hf % mod * x % mod;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> k >> A >> h;
//    h = (h * fp(A, mod - 2)) % mod;
    pw[0] = 1;
    rep(i, 1, N) pw[i] = pw[i - 1] * A % mod;

    ll ht = (1 << (k - 1));
    int ng = (1 << ht);

    rep(mask, 0, ng) {
        rk[mask] = vi(ht + 1, ht + 1);
        int curmask = mask;
        rep(b, 0, 10) cur[b].clear();
        rep(l, 0, ht) cur[k - 1].push_back(l + 1);
        for (int l = k - 1; l >= 1; l--) {
            for (int j = 0; j < sz(cur[l]); j += 2) {
                int w = cur[l][j + (curmask & 1)];
                int &r = rk[mask][w];
                cur[l - 1].push_back(w);
                r = (r + 1) / 2;
                curmask >>= 1;
            }
        }
        win[mask] = cur[0][0];
//        cout << mask << ": ";
//        rep(i, 1, ht + 1) cout << rk[mask][i] << " ";
//        cout << ", win: " << win[mask] << endl;
//        cout << endl;
        rep(i, 1, ht + 1) {
            Lhs[mask] = (Lhs[mask] + i * pw[rk[mask][i]]) % mod;
            Rhs[mask] = (Rhs[mask] + (i + ht) * pw[rk[mask][i]]) % mod;
        }
    }
    rep(mask, 0, ng) {
        mp[Rhs[mask]] = mask;
    }
    rep(mask, 0, ng) {
        // L win
        ll w = win[mask];
        assert(rk[mask][w] == 2);
        ll hs = ((h - Lhs[mask] - w * (pw[1] - pw[2]))  % mod + mod) % mod;
        if(mp.count(hs)) {
            int rmask = mp[hs];
            rep(i, 1, ht + 1) {
                if(i == w) cout << 1 << " ";
                else cout << rk[mask][i] << " ";
            }
            rep(i, 1, ht + 1) cout << rk[rmask][i] << " ";
            return 0;
        }
    }

//    cout << (Lhs[7] + Rhs[10] + ((win[10] + ht) * (pw[1] - pw[2])) - h) % mod << endl;

    mp.clear();
    rep(mask, 0, ng) {
        mp[Lhs[mask]] = mask;
    }

    rep(mask, 0, ng) {
        // R win
        ll w = win[mask] + ht;
        ll hs = ((h - Rhs[mask] - w * (pw[1] - pw[2])) % mod + mod) % mod;
        if(mp.count(hs)) {
            int lmask = mp[hs];
            rep(i, 1, ht + 1) {
                cout << rk[lmask][i] << " ";
            }
            rep(i, 1, ht + 1) {
                if(i == w - ht) cout << 1 << " ";
                else cout << rk[mask][i] << " ";
            }
            return 0;
        }
    }
    cout << -1 << endl;

}