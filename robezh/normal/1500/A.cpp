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

const int N = (int)2e5 + 50, M = (int)5e6 + 50;

int n;
pii a[N];
vector<pii> c2;
vector<pii> xs;
pii have[M];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        int x; cin >> x;
        a[i] = {x, i};
    }
    sort(a, a + n);
    int r = 0;
    fill(have, have + M, pii{-1, -1});

    for (int i = 0; i < n; i = r) {
        while(r < n && a[r].first == a[i].first) r++;
        if(r - i >= 4) {
            cout << "YES" << '\n';
            rep(j, i, i + 4) cout << a[j].second + 1 << " ";
            cout << '\n';
            return 0;
        }
        if(r - i >= 2) {
            c2.push_back({a[i].second, a[i + 1].second});
            if(sz(c2) >= 2) {
                cout << "YES\n";
                cout << c2[0].first + 1 << " " << c2[1].first + 1 << " " << c2[0].second + 1 << " " << c2[1].second + 1 << '\n';
                return 0;
            }
            have[a[i].first * 2] = {a[i].second, a[i + 1].second};
        }
        xs.push_back(a[i]);
    }
    rep(i, 0, sz(xs)) {
        rep(j, 0, i) {
            int sum = xs[i].first + xs[j].first;
            if(have[sum].first != -1) {
                cout << "YES\n";
                cout << have[sum].first + 1 << " " << have[sum].second + 1 << " " << xs[i].second + 1 << " " << xs[j].second + 1 << '\n';
                return 0;
            }
            have[sum] = {xs[i].second, xs[j].second};
        }
    }
    cout << "NO\n";

}