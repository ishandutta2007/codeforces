#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;

int p[N], s[N], k[N], t, n, q;
int a[N];

void cnt_p(int k) {
    for (int i = 0; i < N; i++) p[i] = 0;
    for (int i = 0; i < k * n; i++) {
        t = a[i % n];
        for (int j = t; j >= 0; j--)
            p[t] = max(p[t], p[j] + 1);
    }
    for (int i = 1; i < 343; i++)
        p[i] = max(p[i], p[i - 1]);
}

void cnt_s(int k) {
    for (int i = 0; i < N; i++) s[i] = 0;
    for (int i = n * k - 1; i >= 0; i--) {
        t = a[i % n];
        for (int j = t; j <= 300; j++)
            s[t] = max(s[t], s[j] + 1);
    }
    for (int i = 343; i >= 0; i--)
        s[i] = max(s[i], s[i + 1]);
}

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        k[a[i]]++;
    }

    if (q < 306) {
        cnt_p(q);
        cout << p[340];
        return 0;
    }

    cnt_p(151);
    cnt_s(151);

    int ans = 0;
    for (int i = 0; i <= 300; i++)
        ans = max(ans, k[i] * (q - 302) + p[i] + s[i]);

    cout << ans;

    return 0;
}