#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 5005;

ll a[MAXN], b[MAXN], tot, mx;
int n;

void solve(int L, int R) {
    ll cur = 0;
    for(int l = L, r = R; l >= 1 && r <= n; l--, r++) {
        cur += a[l] * b[r] + a[r] * b[l] - a[l] * b[l] - a[r] * b[r];
        mx = max(mx, cur);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    for(int i = 1; i <= n; i++) {
        cin >> b[i];
        tot += a[i] * b[i];
    }

    for(int i = 1; i <= n; i++) {
        if(i + 1 <= n)
            solve(i, i + 1);
        if(i + 2 <= n)
            solve(i, i + 2);
    }

    cout << tot + mx << '\n';
}