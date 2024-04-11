#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)1e5 + 50;

struct P {
    int num, i;
    bool operator < (const P &o) const {
        return num < o.num;
    }
};

int n, A, cf, cm;
ll m;
P p[N];
ll f_res = -1;
vector<ll> vals;
ll f_vals[N];

void record_vals(int l, int r, ll val) {
    for(int i = 0; i <= l; i++) vals.push_back(val);
    l = min(l, r - 1);
    for(int i = l + 1; i <= r - 1; i++) vals.push_back(p[i].num);
    for(int i = r; i < n; i++) vals.push_back(A);
    for(int i = 0; i < n; i++) f_vals[p[i].i] = vals[i];
}

void solve() {
    ll res = 0;
    int r = 0;
    ll cursum = 0;
    while(r + 1 < n && cursum + 1LL * (r + 1) * (p[r+1].num - p[r].num) <= m) {
        cursum += 1LL * (r + 1) * (p[r+1].num - p[r].num);
        r ++;
    }
    ll mn = min((p[r].num + (m - cursum) / (r + 1)), 1LL * A);
    if(mn != A) res = max(res, mn * cm);
    else res = max(res, mn * cm + 1LL * n * cf);
    if(f_res == res) {
        record_vals(r, n, mn);
        return ;
    }

    ll rm = m;
    for(int i = n - 1; i >= 0; i--) {
        rm -= (A - p[i].num);
        if(rm < 0) break;
        while(r >= 1 && (cursum > rm || r >= i)) {
            r--;
            cursum -= 1LL * (r + 1) * (p[r+1].num - p[r].num);
        }
        if(r == 0) assert(cursum == 0);
        mn = min((p[r].num + (rm - cursum) / (r + 1)), 1LL * A);
//            else mn = A;
        res = max(res, mn * cm + 1LL * (n - i) * cf);
        if(res == f_res) {
            record_vals(r, i, mn);
            return ;
        }
    }
    f_res = res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> A >> cf >> cm >> m;
    for(int i = 0; i < n; i++) cin >> p[i].num, p[i].i = i;
    sort(p, p + n);
    solve();
    solve();

    cout << f_res << endl;
    for(int i = 0; i < n; i++) cout << f_vals[i] << " ";

}