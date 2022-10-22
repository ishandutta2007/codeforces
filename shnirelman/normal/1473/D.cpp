#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using pii = pair<int, int>;
using ld = long double;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int LOGN = 20;

int a[N];
int s[N], max2[N];
int mx[LOGN][N], mn[LOGN][N];

int getmx(int l, int r) {
    int len = r - l;
    return max(mx[max2[len]][l], mx[max2[len]][r - (1 << max2[len])]);
}

int getmn(int l, int r) {
    int len = r - l;
    return min(mn[max2[len]][l], mn[max2[len]][r - (1 << max2[len])]);
}

/*
1
8 4
-+--+--+
1 8
2 8
2 5
1 1

1
8 1
-+--+--+
1 1
*/
void solve() {
    int n, q;
    cin >> n >> q;

    string str;
    cin >> str;

    for(int i = 0; i < n; i++) {
        a[i] = (str[i] == '-' ? -1 : 1);
    }

    s[0] = 0;
    for(int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + a[i - 1];
    }

    max2[1] = 0;
    for(int i = 2; i <= n; i++) {
        max2[i] = max2[i / 2] + 1;
    }

    for(int i = 0; i <= n; i++) {
        mn[0][i] = mx[0][i] = s[i];
    }

    for(int i = 1; i < LOGN; i++) {
        for(int j = 0; j + (1 << i) <= n + 1; j++) {
            mn[i][j] = min(mn[i - 1][j], mn[i - 1][j + (1 << (i - 1))]);
            mx[i][j] = max(mx[i - 1][j], mx[i - 1][j + (1 << (i - 1))]);
        }
    }

    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        l--;

        int d = s[r] - s[l];

        int mx1 = getmx(0, l + 1);
        int mx2 = getmx(r, n + 1) - d;

        int mn1 = getmn(0, l + 1);
        int mn2 = getmn(r, n + 1) - d;

//        cout << mx1 << ' ' << mx2 << ' ' << mn1 << ' ' << mn2 << endl;

        cout << max(mx1, mx2) - min(mn1, mn2) + 1 << '\n';
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}