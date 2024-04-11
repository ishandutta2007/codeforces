#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const li INF64 = 1e18 + 13;
const int N = 1000 + 13;
const int K = 17;
const int M = 1e9 + 7;
const int LOGN = 20;

int sum(int a, int b) {
    a += b;
    return (a >= M ? a - M : a);
}

int mul(int a, int b) {
    return a * 1ll * b % M;
}

void solve() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), c(n);
    vector<int> wh(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
        wh[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        b[i]--;
    }

    for(int i = 0; i < n; i++) {
        cin >> c[i];
        c[i]--;
    }

    vector<bool> used(n, false);
    int ans = 1;
    for(int i = 0; i < n; i++) {
        if(!used[i] && a[i] != b[i]) {
            bool fl = false;
            int v = i;
            while(!used[v]) {
                fl |= (c[v] != -1);
                used[v] = true;
                v = wh[b[v]];
            }

            if(!fl)
                ans = mul(ans, 2);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--)
        solve();
}