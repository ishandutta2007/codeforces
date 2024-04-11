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

const int N = (int)5e5 + 50;
const int MAXN = (int)2e6 + 500;

int z[MAXN],cnt[MAXN];

void getZarr(const string &str) {
    memset(z, 0, sizeof(z));
    int n = str.length();
    for(int i = 1, l = 0, r = 0; i < n; ++i){
        if(i <= r)
            z[i] = min(r - i + 1, z[i - l]);
        while(i + z[i] < n && str[z[i]] == str[i + z[i]])
            ++z[i];
        if(i + z[i] - 1 > r)
            l = i,  r = i + z[i] - 1;
    }
}



int n, m;
int lb[N], rb[N];
string A, B, s;

struct BIT {
    ll bit[N];

    void add(int x, ll val) {
        for(int i = x; i < n; i |= i + 1) bit[i] += val;
    }

    ll get(int x) {
        ll res = 0;
        for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
        return res;
    }

    ll getrange(int l, int r) {
        return get(min(n - 1, r)) - get(min(n - 1, l - 1));
    }
} bit[2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    cin >> A >> B >> s;
    string str = s + "$" + A;
    getZarr(str);
    rep(i, 0, n) {
        lb[i] = z[i + m + 1];
    }
    string rs = s;
    reverse(all(rs));
    string rB = B;
    reverse(all(rB));
    str = rs + "$" + rB;
    getZarr(str);
    rep(i, 0, n) {
        rb[n - 1 - i] = z[i + m + 1];
    }
    vector<pii> pl, pr;
    rep(i, 0, n) {
        if(lb[i]) pl.push_back({min(lb[i], m - 1), i});
    }

    rep(i, 0, n) {
        if(rb[i]) pr.push_back({min(rb[i], m - 1), i});
    }

    sort(all(pl));
    sort(all(pr), greater<pii>());
    int pt = 0;
    ll res = 0;
    for (auto &p : pl) {
        int rlen = m - p.first;
        while(pt < sz(pr) && pr[pt].first >= rlen) {
            bit[0].add(pr[pt].second, 1);
            bit[1].add(pr[pt].second, pr[pt].first);
            pt++;
        }
        int idx = p.second;
        res += bit[1].getrange(idx, idx + m - 2) - (rlen - 1) * bit[0].getrange(idx, idx + m - 2);
    }
    cout << res << '\n';

}