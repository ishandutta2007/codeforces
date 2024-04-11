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

const int N = (int)1e6 + 50;

int n;
ll a[N], b[N], c[N];
ll ka[N], kb[N];
ll addk[N], addb[N];
vi qr[N];
ll q, res[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 1, n + 1) cin >> a[i];
    rep(i, 1, n + 1) {
        cin >> b[i];
        ll x = (i == 1 ? 0 : b[i]) - a[i];
        c[i] = x;
    }

    rep(i, 1, n + 1) {
        ka[i] = -c[i];
        for (int j = i; j <= n; j += i) c[j] += ka[i];
    }

    c[1] = 1;
    rep(i, 1, n + 1) {
        kb[i] = -c[i];
        for (int j = i; j <= n; j += i) c[j] += kb[i];
    }

    rep(i, 1, n + 1) {
        ll k = kb[i], y = ka[i];
        assert(k == 0 || k == -1 || k == 1);
        if(k == 0) addb[0] += abs(y);
        else {
            if(k < 0) y = -y;
            if(y >= 0) addk[0] += 1, addb[0] += y;
            else {
                y = -y;
                addk[0] += -1;
                addb[0] += y;
                if(y < N) {
                    addk[y] += 2;
                    addb[y] -= 2 * y;
                }
            }
        }
    }

    cin >> q;
    rep(i, 0, q) {
        int x; cin >> x; qr[x].push_back(i);
    }

    ll ck = 0, cb = 0;
    rep(i, 0, N) {
        ck += addk[i];
        cb += addb[i];
        for (int id : qr[i]) {
            res[id] = ck * i + cb;
        }
    }
    rep(i, 0, q) {
        cout << res[i] << "\n";
    }





}