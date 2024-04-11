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

int fir[N], la[N];
int add[N];
int has[N];
int n, a[N];
vector<pii> segs;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int res = 0;
    rep(i, 1, n + 1) {
        cin >> a[i];
        la[a[i]] = i;
    }
    for (int i = n; i >= 1; i--) fir[a[i]] = i;

    rep(i, 1, n + 1) {
        if(fir[i] != la[i]) {
            add[fir[i]]++;
            add[la[i] + 1]--;
            segs.push_back({fir[i], la[i]});
        }
    }
    int s = 0;
    rep(i, 1, n + 1) {
        s += add[i];
        if(s) res++;
    }
    sort(all(segs));
//    cout << res << '\n';

    int cur = 0;
    while(cur < sz(segs)) {
        int mx = -1, lim = segs[cur].second;
        res -= 2;
//        cout << "at " << segs[cur].first << ',' << segs[cur].second << endl;
        while(true) {
            mx = -1;
            int r = cur + 1;
            while(r < sz(segs) && segs[r].first < lim) {
                mx = max(mx, segs[r].second);
                r++;
            }
            if(mx <= lim) {
                cur = r;
                break;
            } else {
                res--;
                cur = r - 1;
                lim = mx;
//                cout << "go to " << lim << endl;
            }
        }
    }
    cout << res << '\n';

}