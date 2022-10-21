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

const int N = (int)2e5 + 50;

int n;
int a[N];


struct Seg {
    int l, r;
};



void solve() {
    cin >> n;
    rep(i, 0, n) cin >> a[i];

    vi res;
    vector<Seg> sgs;
    rep(i, 0, n) {
        if(!a[i]) continue;
        if(!sgs.empty() && sgs.back().r + 1 == i) sgs.back().r++;
        else sgs.push_back({i, i});
    }
    while(!sgs.empty()) {
        auto p = sgs.back(); sgs.pop_back();
        if((p.r - p.l + 1) % 2 == 0) {
            if(p.r + 1 < n) {
                while(p.r - 1 >= p.l) {
                    res.push_back(p.r - 1);
                    p.r -= 2;
                }
            } else if(p.l > 0) {
                while(p.l < p.r) {
                    res.push_back(p.l - 1);
                    p.l += 2;
                }
            } else {
                return cout << "NO\n", void();
            }
        } else {
            if(sgs.empty()) {
                return cout << "NO\n", void();
            } else {
                while(p.l - 2 > sgs.back().r) {
                    res.push_back(p.l - 2);
                    p.l -= 2;
                }
                if(sgs.back().r + 1 == p.l) {
                    sgs.back().r = p.r;
                } else {
//                    cout << sgs.back().r + 2 << " " << p.l << endl;
                    assert(sgs.back().r + 2 == p.l);
                    res.push_back(sgs.back().r);
                    sgs.back().r--;
                    if(sgs.back().r < sgs.back().l) sgs.pop_back();
                    p.l++;
                    while(p.l < p.r) {
                        res.push_back(p.l - 1);
                        p.l += 2;
                    }
                }

            }
        }
    }
    cout << "YES\n";
    cout << sz(res) << '\n';
    for (int idx : res) cout << idx + 1 << " ";
    cout << '\n';

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