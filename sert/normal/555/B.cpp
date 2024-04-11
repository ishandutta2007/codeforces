#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

struct Hole {
    ll mn, mx, num;
    Hole() {}
    Hole(ll Mn, ll Mx, ll Num) {
        mn = Mn;
        mx = Mx;
        num = Num;
    }
    bool operator<(const Hole &a) const {
        return (mx == a.mx ? num < a.num : mx < a.mx);
    }
};

bool cmp_mn(const Hole &a, const Hole &b) {
    return a.mn < b.mn;
}
bool cmp_num(const Hole &a, const Hole &b) {
    return a.num < b.num;
}

ll l[N], r[N];
Hole a[N];
pair<ll, ll> b[N];
set <Hole> s;
set <Hole> :: iterator it;
ll ans[N], ka, n, m;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d", &n, &m);
    scanf("%I64d%I64d", l, r);
    for (int i = 1; i < n; i++) {
        scanf("%I64d%I64d", l + i, r + i);
        a[i - 1] = Hole(l[i] - r[i - 1], r[i] - l[i - 1], i - 1);
    }
    sort(a, a + n - 1, cmp_mn);
    a[n] = Hole(2e18, 2e18, n);

    for (int i = 0; i < m; i++) {
        scanf("%I64d", &b[i].first);
        b[i].second = i + 1;
    }
    sort(b, b + m);
    int cur = 0;
    for (int i = 0; i < m; i++) {
        while (a[cur].mn <= b[i].first)
            s.insert(a[cur++]);
        it = s.lower_bound(Hole(-1, b[i].first, -1));
        if (it == s.end())
            continue;
        ka++;
        ans[it->num] = b[i].second;
        s.erase(it);
    }

    if (ka < n - 1)
        cout << "No\n";
    else {
        cout << "Yes\n";
        for (int i = 0; i < n - 1; i++)
            cout << ans[i] << " ";
    }


    return 0;
}