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

int n, a[N], ta[N];
ll invs[35][2];
map<int, int> mp;

void solve(int b, int l, int r) {
    if(l > r || b == -1) return ;
    int cnt[2] = {0, 0};

    for(int i = l; i <= r; i++) {
        cnt[(a[i] >> b) & 1]++;
        if(!(a[i] >> b & 1)) invs[b][0] += cnt[1];
        else invs[b][1] += cnt[0];
    }
    int c[2] = {0, 0};
    for(int i = l; i <= r; i++) {
        if((a[i] >> b) & 1) ta[l + cnt[0] + (c[1]++)] = a[i];
        else ta[l + (c[0]++)] = a[i];
    }
    assert(c[0] == cnt[0]);
    assert(c[1] == cnt[1]);
    for(int i = l; i <= r; i++) a[i] = ta[i];
    solve(b - 1, l, l + cnt[0] - 1);
    solve(b - 1, l + cnt[0], r);
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int res = 0;
    ll resinvs = 0;
    rep(i, 0, n) {
        cin >> a[i];
    }
    solve(29, 0, n - 1);
    rep(b, 0, 30) {
        if(invs[b][0] <= invs[b][1]) {
            resinvs += invs[b][0];
        } else {
            resinvs += invs[b][1];
            res |= (1 << b);
        }
    }
    cout << resinvs << " " << res << '\n';



}