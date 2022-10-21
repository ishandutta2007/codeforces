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

const int N = (int)1e5 + 50;

int n, a[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    rep(i, 0, n) {
        cin >> a[i];
    }
    int r = 0;
    int res = 0;
    int la = -1, cl = 1, las = -1;
    vector<pii> ps;
    for (int i = 0; i < n; i = r) {
        while(r < n && a[i] == a[r]) r++;
        int cnt = min(r - i, 2);
        ps.push_back({a[i], cnt});
    }

    for (auto &p : ps) {
        if(p.second == 1) {
            cl |= (las != la && p.first != la);
            res++;
            las = p.first;
        } else {
            if(cl || p.first != la) res += 2;
            else res++;
            cl = 0;
            las = la = p.first;
        }
    }
    cout << res << endl;


}