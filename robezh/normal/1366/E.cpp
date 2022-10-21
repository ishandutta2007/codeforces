#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

const int mod = 998244353, N = (int)2e5 + 50;

int n, m;
int a[N], b[N], smin[N];
map<int, int> cnt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> a[i];
    rep(i, 0, m) cin >> b[i];
    smin[n - 1] = a[n - 1];
    cnt[smin[n-1]]++;
    for(int i = n - 2; i >= 0; i--) {
        smin[i] = min(smin[i + 1], a[i]);
        cnt[smin[i]]++;
    }
    ll res = 1;
    for(int i = 1; i < m; i++) {
        res = (res * cnt[b[i]]) % mod;
//        cout << cnt[b[i]] << endl;
    }
    if(smin[0] != b[0]) res = 0;
    cout << res << '\n';

}