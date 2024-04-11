#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 2e9 + 13;
const li INF64 = 2e18 + 13;
const int M = 998244353;
const int A = 1e6 + 13;
const int N = 2e5 + 13;
const int B = 400;
const int LOGN = 20;

mt19937 rnd(2);

int a[N][2];
int pref[N], suf[N][2];

void solve() {
    int n;
    cin >> n;

    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < n; j++)
            cin >> a[j][i];
    }

    for(int i = 0; i <= n + 2; i++) {
        pref[i] = suf[i][0] = suf[i][1] = 0;
    }

    //a[]

    pref[0] = 0;
    for(int i = 0; i < n; i++) {
        pref[i + 1] = pref[i] + 2 - (i == 0);
        if(i % 2 == 0) {
            pref[i + 1] = max(pref[i + 1], a[i][0] + 2 - (i == 0));
            pref[i + 1] = max(pref[i + 1], a[i][1] + 1);
        } else {
            pref[i + 1] = max(pref[i + 1], a[i][0] + 1);
            pref[i + 1] = max(pref[i + 1], a[i][1] + 2);
        }

//        cout << i + 1 << ' ' << pref[i + 1] << endl;
    }

    int ans = pref[n];

    suf[n][0] = suf[n][1] = 0;
    for(int i = n - 1; i >= 0; i--) {
        suf[i][0] = max({suf[i + 1][0] + 1, a[i][0] + 1, a[i][1] + (n - i) * 2});
        suf[i][1] = max({suf[i + 1][1] + 1, a[i][1] + 1, a[i][0] + (n - i) * 2 - (i == 0)});
        ans = min(ans, max(pref[i] + (n - i) * 2 - (i == 0), suf[i][(i % 2) ^ 1]));
//        ans = min(ans, max(pref[i], suf[i][(i % 2) ^ 1]));
//        cout << i << ' ' << suf[i][0] << ' ' << suf[i][1] << ' ' << pref[i] << endl;
    }

    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}