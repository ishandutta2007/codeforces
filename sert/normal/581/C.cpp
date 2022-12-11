#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 1e6 + 7;

ll a[N];
ll n, m, t, k, c, v;
ll mx, b[N];
vector <pair<int, int> > s;
ll ans;

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] != 100)
            s.push_back(make_pair(10 - a[i] % 10, i));
        ans += a[i] / 10;
    }
    sort(s.begin(), s.end());
    int cur = 0;
    while (cur < s.size()) {
        v = s[cur].second;
        c = s[cur].first;
        cur++;
        if (c > k)
            break;
        if (a[v] == 100)
            continue;
        a[v] += c;
        ans++;
        k -= c;
        if (a[v] != 100)
            s.push_back(make_pair(10, v));
    }

    cout << ans;



    return 0;
}