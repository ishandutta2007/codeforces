#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

const int mod = 1000000007;

void smin(int& x, int& y) {
    if (x > y) {
        swap(x, y);
    }
}

void smax(int& x, int& y) {
    if (x < y) {
        swap(x, y);
    }
}

int pw(int x, int deg) {
    if (deg == 0) {
        return 1;
    }
    ll ans = pw(x, deg / 2);
    ans = ans * ans % mod;
    if (deg % 2 == 1) {
        ans = ans * x % mod;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    vector<pii> ps(n);

    for(int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
        ps[i].first = x[i];
        ps[i].second = y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());

    map<int, int> xti;
    map<int, int> yti;
    xti[x[0]] = 0;
    yti[y[0]] = 0;
    int sx = 1;
    int sy = 1;
    for (int i = 1; i < n; ++i) {
        if (x[i] != x[i - 1]) {
            xti[x[i]] = sx;
            ++sx;
        }
        if (y[i] != y[i - 1]) {
            yti[y[i]] = sy;
            ++sy;
        }
    }

    vector<vector<int>> r(sx + sy, vector<int>());
    for (int i = 0; i < n; ++i) {
        int cx = xti[ps[i].first];
        int cy = yti[ps[i].second];
        r[cx].push_back(cy + sx);
        r[cy + sx].push_back(cx);
    }
    vector<bool> used(sx + sy, false);

    ll ans = 1;
    for (int i = 0; i < sx + sy; ++i) {
        if (used[i]) {
            continue;
        }
        int cx = 0;
        int cr = 0;
        stack<int> dfs;
        dfs.push(i);
        while (!dfs.empty()) {
            int cur = dfs.top();
            dfs.pop();
            if (used[cur]) {
                continue;
            }
            used[cur] = true;
            ++cx;
            for (int i = 0; i < r[cur].size(); ++i) {
                ++cr;
                dfs.push(r[cur][i]);
            }
        }
        cr /= 2;
        if (cr < cx) {
            ans *= pw(2, cx) - 1;
        } else {
            ans *= pw(2, cx);
        }
        ans %= mod;
    }

    cout << ans << '\n';

    return 0;
}