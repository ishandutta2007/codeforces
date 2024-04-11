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

int n, q;
ll bit[N];

void add(int x, ll val) {
    for(int i = x; i < n; i |= i + 1) bit[i] += val;
}

void add(int l, int r, ll val) {
//    cout << "adding " << l << ", " << r << ": " << val << endl;
    add(l, val);
    add(r + 1, -val);
}

ll get(int x) {
    ll res = 0;
    for(int i = x; i >= 0; i = (i & (i + 1)) - 1)  res += bit[i];
    return res;
}

struct P {
    int l, c, last;
};


vector<ll> sum[N];
map<int, P> mp;

void split(int x) {
    if(x >= n || x < 0) return ;
    auto it = mp.lower_bound(x);
    int l0 = it->second.l;
    if(l0 == x) return ;
    int r1 = it->first;
    auto p = it->second;
    mp[r1] = {x, p.c, p.last};
    mp[x - 1] = {l0, p.c, p.last};
}

void change(int l, int r, int c) {
    split(l);
    split(r + 1);
//    cout << "before " << l << " " << r << " " << c << endl;
//    for (auto p : mp) {
//        cout << p.second.l << ", " << p.first << ", color: " <<p.second.c << ", lastid: " << p.second.last << endl;
//    }
    for (auto it = mp.lower_bound(l); it != mp.end() && it->first <= r; ) {
        auto p = it->second;
        add(p.l, it->first, (sum[p.c].empty() ? 0 : sum[p.c].back()) - (p.last < 0 ? 0 : sum[p.c][p.last]));
        it = mp.erase(it);
    }
    mp[r] = {l, c, sz(sum[c]) - 1};
//    cout << "Chaing " << l << " " << r << " " << c << endl;
//    for (auto p : mp) {
//        cout << p.second.l << ", " << p.first << ", color: " <<p.second.c << ", lastid: " << p.second.last << endl;
//    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> q;
    mp[n - 1] = {0, 1, -1};
    rep(qid, 0, q) {
        string str; cin >> str;
        if(str == "Color") {
            int l, r, c; cin >> l >> r >> c; l--, r--;
            change(l, r, c);
        } else if(str == "Add") {
            int c, x; cin >> c >> x;
            sum[c].push_back(x + (sum[c].empty() ? 0 : sum[c].back()));
        } else {
            int x; cin >> x; x--;
            auto p = mp.lower_bound(x)->second;
            ll res = get(x);
//            cout << (sum[p.c].empty() ? 0 : sum[p.c].back() ) << " "  << (p.last < 0 ? 0 : sum[p.c][p.last]) << endl;
            res += (sum[p.c].empty() ? 0 : sum[p.c].back()) - (p.last < 0 ? 0 : sum[p.c][p.last]);
            cout << res << '\n';
        }
    }
}