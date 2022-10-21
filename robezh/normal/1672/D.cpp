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
const int N = (int)2e5 + 50;

int n;
vector<pii> a, b;
int ca[N], cb[N];

void read_v(vector<pii> &ps) {
    ps.clear();
    rep(i, 0, n) {
        int x; cin >> x;
        if(ps.empty() || ps.back().first != x) {
            ps.push_back({x, 1});
        } else {
            ps.back().second++;
        }
    }
}

void solve() {
    cin >> n;
    read_v(a);
    read_v(b);
    fill(cb, cb + n + 1, 0);
    int pt = sz(a) - 1;
    while(!b.empty()) {
        auto p = b.back(); b.pop_back();
        cb[p.first] += p.second;
        while(pt >= 0 && a[pt].first != p.first) {
            cb[a[pt].first] -= a[pt].second;
            if(cb[a[pt].first] < 0) {
                cout << "NO" << '\n';
                return ;
            }
            pt--;
        }
        if(pt == -1) {
            cout << "NO" << '\n';
            return ;
        }
        cb[a[pt].first] -= a[pt].second;
        if(cb[a[pt].first] < 0) {
            cout << "NO" << '\n';
            return ;
        }
        pt--;
    }
    cout << "YES\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;
    while(T--) {
        solve();
    }

}