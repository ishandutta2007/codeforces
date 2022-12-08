#include<bits/stdc++.h>
#define int long long
using namespace std;

int get() {
    int x = 0, f = 1; char c = getchar();
    while(!isdigit(c)) { if(c == '-') f = -1; c = getchar(); }
    while(isdigit(c)) { x = x * 10 + c - '0'; c = getchar(); }
    return x * f;
}

const int N = 2e5 + 5;
int n, a[N], f[N][20];

int gcd(int x, int y) { return y? gcd(y, x % y) : x; }

int query(int l, int r) {
    int len = (int)log2(r - l + 1);
    return gcd(f[l][len], f[r - (1 << len) + 1][len]);
}

void solve() {
    n = get();
    for(int i = 1; i <= n; i++) a[i] = get();
    int ans = 1;
    for(int i = 1; i < n; i++) f[i][0] = abs(a[i + 1] - a[i]);
    for(int j = 1; j <= 19; j++)
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
            f[i][j] = gcd(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
    for(int i = 1; i <= n; i++) {
        int l = i + 1, r = n, res = i;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(query(i, mid - 1) > 1) res = mid, l = mid + 1;
            else r = mid - 1;
        }
        ans = max(ans, res - i + 1);
    }
    printf("%d\n", ans);
}

signed main() {
    int T = get();
    while(T--) solve();
    return 0;
}

/*
1
5
1 5 2 4 6
*/