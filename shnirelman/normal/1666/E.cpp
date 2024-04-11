#include <bits/stdc++.h>

using namespace std;
using li = long long;

const li INF64 = 1e18 + 13;
const int INF = 1e9 + 13;
const int N = 1e5 + 13;
const int MOD = 998244353;

int n, len;
int a[N];

bool is(int mn, int mx) {
    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        l += mn;
        r += mx;

//        if(l > a[i])
//            return false;

        l = max(l, a[i]);
        r = min(r, a[i + 1]);

        if(r < l)
            return false;
    }

    return (r >= len);
}

int get(int x) {
    int lf = x - 1, rg = len + 1;
    while(rg - lf > 1) {
        int m = (lf + rg) / 2;

        if(is(x, m))
            rg = m;
        else
            lf = m;
    }

    return (rg == len + 1 ? INF : rg - x);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> len >> n;

    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    a[n] = len;

    int mnl = 1, mnr = len + 1;
    while(mnr - mnl > 1) {
        int mid = (mnl + mnr) / 2;
        if(is(mid, len))
            mnl = mid;
        else
            mnr = mid;
    }
    /*while(mnr - mnl > 10) {
        int m1 = (mnl * 2 + mnr) / 3, m2 = (mnl + mnr * 2) / 3;
//        cout << mnl << ' ' << mnr << endl;

        if(get(m1) < get(m2))
            mnr = m2;
        else
            mnl = m1;
    }

    int ans = INF;
    int mn = mnl;
    for(int i = mnl; i < mnr; i++) {
//        cout << i << ' ' << get(i) << endl;
        int res = get(i);
        if(res < ans) {
            ans = res;
            mn = i;
        }
    }*/

    int mn = mnl;
    int mx = mn + get(mn);

    vector <int> L, R;

    int l = 0, r = 0;
    for(int i = 0; i < n; i++) {
        l += mn;
        r += mx;

//        if(l > a[i])
//            return false;

        l = max(l, a[i]);
        r = min(r, a[i + 1]);

        L.push_back(l);
        R.push_back(r);
    }

    int x = len;
//    cout << x << ' ';
    vector<int> rs(1, x);

    for(int i = n - 1; i > 0; i--)
    {
        int lp = L[i - 1], rp = R[i - 1];

        if(x <= rp + mn)
            x -= mn;
        else x = rp;

//        cout << x << ' ';
        rs.push_back(x);
        rs.push_back(x);
    }

    rs.push_back(0);

    reverse(rs.begin(), rs.end());

    for(int i = 0; i < n * 2; i += 2) {
        cout << rs[i] << ' ' << rs[i + 1] << '\n';
    }

//    cout << ans << endl;

//    cout << mnl << endl;
}