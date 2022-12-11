#include <bits/stdc++.h>
using namespace std;
const int N = 5000 + 4;
typedef long long ll;
typedef long double ld;
const ll md = 1e9 + 9;
const ll p1 = 997;
const ll p2 = 2011;

int n, k, e;
string s, bad;
pair <ll, ll> h[N];
ll st1[N], st2[N];
int a[N], b[N];

pair<ll, ll> geth(int l, int r) {
    return make_pair(
        (h[r].first - h[l].first * st1[r - l] + md * md) % md,
        (h[r].second - h[l].second * st2[r - l] + md * md) % md
    );
}

pair<ll, ll> v[1200000];
int vlen;

int main() {
    //freopen("a.in", "r", stdin);

    cin >> s >> bad >> k;

    n = s.length();
    for (int i = 0; i < n; i++)
        a[i] = s[i] - 'a';

    st1[0] = st2[0] = 1;
    for (int i = 1; i < N; i++) {
        st1[i] = (st1[i - 1] * p1) % md;
        st2[i] = (st2[i - 1] * p2) % md;
    }
    for (int i = 0; i < n; i++) {
        h[i + 1].first = (h[i].first * p1 + a[i] + 1) % md;
        h[i + 1].second = (h[i].second * p2 + a[i] + 1) % md;
    }

    for (int i = 0; i < n; i++) {
        e = 0;
        for (int j = i; j < n; j++) {
            if (bad[a[j]] == '0')
                e++;
            if (e <= k)
                v[vlen++] = geth(i, j + 1);
        }
    }

    sort(v, v + vlen);
    cout << unique(v, v + vlen) - v;

    return 0;
}