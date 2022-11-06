#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()

#define ll long long
#define ld long double
#define int long long

const int N = 1e6 + 7, M = 1e9 + 7;

int p, k;
int us[N];
int st, en, pr[N];
bool good[N];

void dfs(int v) {
    us[v] = 1;
    int u = v * k % p;
    if (!us[u]) { pr[u] = v; dfs(u); } else {
        if (us[u] == 1) {
            st = u;
            en = v;
        }
    }
    us[v] = 2;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> p >> k;
    if (k == 0) {
        int ans = 1;
        for (int i = 1; i < p; i++) {
            ans *= p;
            ans %= M;
        }
        cout << ans;
        return 0;
    }
    int cur = 1;
    for (int i = 1; i <= p; i++) {
        cur *= k;
        cur %= p;
        good[i] = cur == 1;
    }
    int ans = 1;
    for (int i = 0; i < p; i++) {
        if (!us[i]) {
            en = st = -1;
            dfs(i);
            if (en == -1) continue;
            int cnt = 1;
            while (en != st) {
                cnt++;
                en = pr[en];
            }
            ans *= good[cnt] ? p : 1;
            ans %= M;
        }
    }
    cout << ans;
    return 0;
}