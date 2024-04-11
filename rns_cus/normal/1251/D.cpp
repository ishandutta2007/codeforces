#include <bits/stdc++.h>
using namespace std;

#define N 200200

typedef long long ll;

int n, l[N], r[N];
ll s;

bool check(int x) {
    vector <int> v;
    ll up = 0;
    for (int i = 1; i <= n; i ++) if (r[i] >= x) v.push_back(i); else up += l[i];
    int sz = v.size(), k = n + 1 >> 1;
    if (sz < k) return 0;
    sort(v.begin(), v.end(), [&](int i, int j) {return l[i] < l[j];});
    for (int i = 0; i < sz - k; i ++) up += l[v[i]];
    for (int i = sz - k; i < sz; i ++) up += max(x, l[v[i]]);
    return up <= s;
}

int main() {
    int T;
    scanf("%d", &T);
    while (T --) {
        scanf("%d %I64d", &n, &s);
        for (int i = 1; i <= n; i ++) scanf("%d %d", &l[i], &r[i]);
        int le = 0, ri = 1e9 + 7;
        while (le < ri - 1) {
            int mi = le + ri >> 1;
            if (check(mi)) le = mi;
            else ri = mi;
        }
        printf("%d\n", le);
    }

    return 0;
}