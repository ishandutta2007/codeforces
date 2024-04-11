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

int n, p[N];
int dl[N], dr[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    int lg = 0;
    map<int, int> mp;
    rep(i, 1, n + 1) {
        cin >> p[i];
        dl[i] = 1 + (i > 1 && p[i] > p[i - 1] ? dl[i - 1] : 0);
    }
    for (int i = n; i >= 1; i--) {
        dr[i] = 1 + (i < n && p[i] > p[i + 1] ? dr[i + 1] : 0);
    }
    int res = 0;
    rep(i, 1, n + 1) {
        int v = max(dl[i], dr[i]);
        mp[v]++;
        lg = max(lg, v);
    }

    rep(i, 1, n + 1) {
        if(dl[i] <= 2 || dr[i] <= 2) continue;

        int vl = dl[i], vr = dr[i];
        if(vl > vr) swap(vl, vr);
        if(vr / 2 * 2 >= vl) continue;
        int vm = max(dl[i], dr[i]);
        if(vm != lg || mp[vm] >= 2) continue;
        res++;
    }
    cout << res << '\n';
}