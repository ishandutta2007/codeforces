#include <bits/stdc++.h>
using namespace std;

#define N 300300

int n, s[N], t[N];

typedef pair <int, int> pii;

set <pii> S;
int tot, ai[N], aj[N], ad[N];

bool check() {
    for (int i = 1; i <= n; i ++) S.insert(pii(s[i], i));
    sort(t + 1, t + n + 1);
    for (int i = 1; i < n; i ++) {
        set <pii> :: iterator it = S.lower_bound(pii(t[i], 0));
        if (it != S.end() && (*it).first == t[i]) {S.erase(it); continue;}
        if (it == S.end() || it == S.begin()) return 0;
        pii up = *it; it --; pii dp = *it;
        ai[tot] = dp.second, aj[tot] = up.second;
        ad[tot] = min(up.first - t[i], t[i] - dp.first); tot ++;
        S.erase(up), S.erase(dp);
        int k = up.first + dp.first - t[i];
        if (up.first - t[i] > t[i] - dp.first) S.insert(pii(k, up.second));
        else S.insert(pii(k, dp.second));
    }
    return 1;
}

int main() {
    scanf("%d", &n);
    long long sum = 0;
    for (int i = 1; i <= n; i ++) scanf("%d", &s[i]), sum += s[i];
    for (int i = 1; i <= n; i ++) scanf("%d", &t[i]), sum -= t[i];
    if (sum) puts("NO");
    else if (!check()) puts("NO");
    else {
        puts("YES");
        printf("%d\n", tot);
        for (int i = 0; i < tot; i ++) printf("%d %d %d\n", ai[i], aj[i], ad[i]);
    }

    return 0;
}