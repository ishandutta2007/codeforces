#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const int N = 5005;

int n, a[N], idx[N];
int sig[N];
int mx[N][N], mx_rem[N][10];
vi xs;
//int dp[505][505][505];

void umax(int &to, int val) {
    to = max(to, val);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) cin >> a[i], xs.push_back(a[i]);
    sort(all(xs));
    xs.resize(unique(all(xs)) - xs.begin());


    rep(i, 0, n) idx[i] = (int)(lower_bound(all(xs), a[i]) - xs.begin());
    int fres = 0;
    sig[0] = 1;
    rep(i, 0, n) {
        rep(j, 0, i) {
            sig[i] = max(sig[i], 1 + (abs(a[i] - a[j]) == 1 || (a[i] - a[j]) % 7 == 0 ? sig[j] : 0));
            int res = 1 + sig[j];
            if(idx[i] > 0 && xs[idx[i] - 1] + 1 == a[i]) {
//                cout << i << " can down" << endl;
                res = max(res, mx[j][idx[i] - 1] + 1);
            }
            if(idx[i] + 1 < sz(xs) && xs[idx[i] + 1] - 1 == a[i]) {
//                cout << i << " can up" << endl;
                res = max(res, mx[j][idx[i] + 1] + 1);
            }
            res = max(res, mx_rem[j][a[i] % 7] + 1);
            umax(mx[j][idx[i]], res);
            umax(mx[i][idx[j]], res);
            umax(mx_rem[i][a[j] % 7], res);
            umax(mx_rem[j][a[i] % 7], res);
            umax(fres, res);
//            cout << i << ", " << j << " " << res << endl;
        }
    }
    cout << fres << '\n';
}