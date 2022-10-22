#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = (int)2e5 + 50;


int n;
int a[N];
ll fac[16];

ll rsum(int l, int r) {
    if(l > r) return 0;
    return 1LL * (l + r) * (r - l + 1) / 2;
}

ll gsum(int l, int r) {
    ll res = rsum(l, min(r, n - 16));
    for(int i = max(l, n - 15); i <= r; i++) {
        res += a[i];
    }
    return res;
}

void make_arr(ll xsum) {
    int st = min(n, 15);
    for(int i = n - st; i < n; i++) {
        st--;
        sort(a + i, a + n);
        int d = xsum / fac[st];
        xsum -= d * fac[st];
        swap(a[i], a[i + d]);
    }
//    for(int i = 0; i < n; i++) cout << a[i] << " ";
//    cout << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);


    fac[0] = 1;
    rep(i, 1, 16) fac[i] = fac[i - 1] * i;
    ll xsum = 0;
    cin >> n;
    rep(i, 0, n) a[i] = i;
    int q;
    cin >> q;
    while(q--) {
        int tp; cin >> tp;
        if(tp == 1) {
            int l, r; cin >> l >> r; l--, r--;
            cout << gsum(l, r) + r - l + 1 << '\n';
        } else {
            int x; cin >> x; xsum += x;
            make_arr(xsum);
        }
    }

}