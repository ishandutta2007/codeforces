#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;

const int N = (int)3e5 + 50;
const int INF = (int)1e9;

int n, a[N];
int la[N], res[N], mx[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        cin >> n;
        rep(i, 0, n) cin >> a[i];
        fill(res, res + n + 1, INF);
        fill(la, la + n + 1, -1);
        fill(mx, mx + n + 1, 0);
        rep(i, 0, n) {
            mx[a[i]] = max(mx[a[i]], i - la[a[i]]);
            la[a[i]] = i;
        }
        rep(i, 1, n + 1) {
            mx[i] = max(mx[i], n - la[i]);
            if(mx[i] < n + 1) res[mx[i]] = min(res[mx[i]], i);
        }
        rep(i, 1, n + 1) {
            res[i] = min(res[i], res[i - 1]);
        }
        rep(i, 1, n + 1) cout << (res[i] == INF ? -1 : res[i]) << " ";
        cout << '\n';
    }

}