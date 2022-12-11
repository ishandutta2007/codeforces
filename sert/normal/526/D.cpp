#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6 + 34;

const ll p1 = 31;
const ll p2 = 2011;
const ll md = 1e9 + 9;

pair <ll, ll> h[N], e[N], ta;
ll n, k, len, ln, cnt;
char ss[N];
string s;
ll st1[N], st2[N], L, M, R, cur;
bool fail;

pair <ll, ll> get_h(int l, int r) {
    ta.first = (h[r].first - h[l].first * st1[r - l] + md * md) % md;
    ta.second = (h[r].second - h[l].second * st2[r - l] + md * md) % md;
    return ta;
}

int main() {
    ///freopen("a.in", "r", stdin);
    scanf("%I64d%I64d", &n, &k);
    if (k == 1) {
        for (int i = 0; i < n; i++)
            printf("1");
        return 0;
    }
    scanf("%s", ss);
    s = ss;
    h[0] = make_pair(0, 0);
    for (int i = 1; i <= n; i++) {
        h[i].first = (h[i - 1].first * p1 + s[i - 1] - 'a' + 1) % md;
        h[i].second = (h[i - 1].second * p2 + s[i - 1] - 'a' + 1) % md;
    }
    st1[0] = st2[0] = 1;
    for (int i = 1; i <= n; i++) {
        st1[i] = (st1[i - 1] * p1) % md;
        st2[i] = (st2[i - 1] * p2) % md;
    }

    for (int i = 1; i <= n; i++) {
        len = i;
        if (len * k > n) break;
        fail = false;
        for (int j = 1; j < k && !fail; j++)
            if (get_h(0, len) != get_h(len * j, len * (j + 1)))
                fail = true;
        if (fail) continue;
        L = len * k - 1;
        R = min(n, L + len + 1);
        while (R - L > 1) {
            M = (L + R) / 2;
            if (get_h(len * (k - 1), M + 1) == get_h(0, M + 1 - len * (k - 1)))
                L = M;
            else
                R = M;
        }

        e[ln++] = make_pair(len * k - 1, -1);
        e[ln++] = make_pair(L + 1, 1);
    }

    sort(e, e + ln);
    e[ln] = make_pair(n + 34, -1);

    cur = 0;

    for (int i = 0; i < n; i++) {
        while (e[cur].first == i) {
            cnt += e[cur].second;
            cur++;
        }
        if (cnt < 0)
            printf("1");
        else
            printf("0");
    }

    ///cerr << "\n" << "000110000111111000011\n";

    return 0;
}