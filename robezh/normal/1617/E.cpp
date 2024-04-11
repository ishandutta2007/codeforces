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
typedef pair<int, pii> P;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
const int N = (int)2e5 + 5;

int n, a[N];
P res = {-1, {-1, -1}};

vector<int> v[N];
int idx[N];

void solve(int bt, int l, int r) {
    if(l > r) return ;
    vector<pii> bs;
    while(l <= r && sz(v[idx[l]]) <= bt) {
        bs.push_back({bt, idx[l]});
        l++;
    }
    int rb = l;
    for (int j = l; j <= r; j = rb) {
        pii pr = {-1, -1};
        while(rb <= r && v[idx[rb]][bt] == v[idx[j]][bt]) {
            pr = max(pr, {sz(v[idx[rb]]), idx[rb]});
            rb++;
        }
        bs.push_back(pr);
        solve(bt + 1, j, rb - 1);
    }
    sort(all(bs), greater<>());
    if(sz(bs) >= 2) {
        res = max(res, {bs[0].first + bs[1].first - 2 * bt, {bs[0].second, bs[1].second}});
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
        vi vs;
        if(a[i] == 0) {}
        else {
            int c = 1;
            while (a[i] % 2 == 0) c++, a[i] /= 2;
            a[i]--, a[i] /= 2;
            vs.push_back(c);
            while (a[i]) {
                int c0 = 0, c1 = 0;
                while (a[i] % 2 == 0) c0++, a[i] /= 2;
                while (a[i] % 2 == 1) c1++, a[i] /= 2;
                if (c0) vs.push_back(c0);
                if (c1) vs.push_back(c1);
            }
        }
        v[i] = vs;
    }
    iota(idx, idx + n, 0);
    sort(idx, idx + n, [](const int i, const int j) {
        return v[i] < v[j];
    });
    solve(0, 0, n - 1);
    cout << res.second.first + 1 << " " << res.second.second + 1 << " " << res.first << '\n';

}