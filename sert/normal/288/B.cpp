#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e3 + 34;
const ll md = 1e9 + 7;
ll n, k, ans;
ll c[N][N];
int p[10];

bool check(int x) {
    bool u[10];
    for (int i = 0; i < k; i++)
        u[i] = false;
    while (true) {
        if (x == 0) return true;
        if (u[x]) return false;
        u[x] = true;
        x = p[x];
    }
}
void go(int len) {
    if (len == k) {
        bool ok;
        ok = true;
        for (int i = 0; i < k; i++)
            ok &= check(i);
        if (ok) {
            ans++;
            //cerr << p[0] << " " << p[1] << "\n";
        }
        return;
    }

    for (int i = 0; i < k; i++) {
        p[len] = i;
        go(len + 1);
    }
}

int main() {
    //freopen("a.in", "r", stdin);

    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; j++)
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % md;
    }

    cin >> n >> k;

    go(0);

    for (int i = k; i < n; i++)
        ans = (ans * (n - k)) % md;
    cout << ans;

    return 0;
}