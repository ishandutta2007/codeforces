#include <bits/stdc++.h>
using namespace std;
const int N = 6e5 + 34;
typedef long long ll;
typedef long double ld;

const ll md = 1e9 + 9;
const ll p1 = 2011;
const ll p2 = 103;

set <pair<ll, ll> > hsh;

pair<ll, ll> h[N];
char s[N];
int len, n, m;
ll st1[N], st2[N];

int main() {
    //freopen("a.in", "r", stdin);

    st1[0] = st2[0] = 1;
    for (int i = 1; i < N; i++) {
        st1[i] = (st1[i - 1] * p1) % md;
        st2[i] = (st2[i - 1] * p2) % md;
    }

    scanf("%d%d", &n, &m);
    while (n--) {
        scanf("%s", s);
        len = strlen(s);
        for (int i = 0; i < len; i++) {
            h[i + 1].first = (h[i].first * p1 + s[i] - 'a' + 1) % md;
            h[i + 1].second = (h[i].second * p2 + s[i] - 'a' + 1) % md;
        }
        hsh.insert(h[len]);
    }
    ll fh, sh;
    bool fnd;
    while (m--) {
        scanf("%s", s);
        len = strlen(s);
        for (int i = 0; i < len; i++) {
            h[i + 1].first = (h[i].first * p1 + s[i] - 'a' + 1) % md;
            h[i + 1].second = (h[i].second * p2 + s[i] - 'a' + 1) % md;
        }
        fnd = false;
        for (int i = 0; i < len; i++) {
            for (char c = 'a'; c <= 'c'; c++) {
                if (c != s[i]) {
                    fh = h[len].first;
                    sh = h[len].second;
                    fh = (fh + (c - s[i]) * st1[len - i - 1] + md * md) % md;
                    sh = (sh + (c - s[i]) * st2[len - i - 1] + md * md) % md;
                    if (hsh.find(make_pair(fh, sh)) != hsh.end())
                        fnd = true;
                }
            }
        }
        printf(fnd ? "YES\n" : "NO\n");
    }

    return 0;
}