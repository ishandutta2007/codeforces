#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int last_less_or_eq_ind(ll x, const vector<ll>& v) {
    int l = 0;
    int r = v.size();
    while (r - l > 1) {
        int mid = (l + r) / 2;
        if (v[mid] > x) {
            r = mid;
        } else {
            l = mid;
        }
    }
    return l;
}

ll cost(ll up, ll lo, ll a, ll r, ll m) {
    ll ans = min(up, lo);
    up -= ans;
    lo -= ans;
    ans *= m;
    ans += up * a + lo * r;
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    ll a, r, m;
    cin >> n >> a >> r >> m;
    m = min(m, a + r);
    vector<ll> h(n);
    for (int i = 0; i < n; ++i) {
        cin >> h[i];
    }
    sort(h.begin(), h.end());
    h.push_back(1111111111LL);

    vector<ll> numtou(n + 1, 0);
    vector<ll> numtol(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        numtou[i] = numtou[i - 1] + i * (h[i] - h[i - 1]);
        numtol[n - i - 1] = numtol[n - i] + i * (h[n - i] - h[n - i - 1]);
    }
    numtou[n] = 0;
    numtol[n] = 0;

    ll lh = 0;
    ll rh = h[n];
    ll lcost = numtol[0] * r;
    ll rcost = h.back() * a * n;
    while (rh - lh > 1) {
        ll mhl = lh + (rh - lh) / 3;
        int lil = last_less_or_eq_ind(mhl, h);
        ll curcol = cost(numtou[lil] + (lil + 1) * (mhl - h[lil]), numtol[lil + 1] + (n - lil - 1) * (h[lil + 1] - mhl), a, r, m);
        ll mhr = lh + ((rh - lh) * 2) / 3;
        int lir = last_less_or_eq_ind(mhr, h);
        ll curcor = cost(numtou[lir] + (lir + 1) * (mhr - h[lir]), numtol[lir + 1] + (n - lir - 1) * (h[lir + 1] - mhr), a, r, m);
        if ((curcol <= curcor && curcor <= rcost) || (lh == mhl && curcol < curcor)) {
            rcost = curcor;
            rh = mhr;
        } else if (lh == mhl && curcol >= curcor) {
            lcost = curcor;
            lh = mhr;
        } else {
            lcost = curcol;
            lh = mhl;
        }
    }

    cout << lcost << "\n";

    return 0;
}