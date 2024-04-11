#include <bits/stdc++.h>
using namespace std;
long long a[22], n;
bool use[233];
bool Dfs(int x, long long val) {
    if (x == n + 1) {
        for (int i = 1; i <= n; i++)
            if (!use[i])
                if (val == a[i])
                    return 1;
        return 0;
    }
    bool flag = 0;
    use[x] = 1;
    flag |= Dfs(x + 1, val - a[x]);
    flag |= Dfs(x + 1, val + a[x]);
    use[x] = 0;
    flag |= Dfs(x + 1, val);
    return flag;
}
void solve() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) if (!a[i]) {
        puts("YES");
        return;
    }
    for (int i = 1; i <= n; i++) 
        for (int j = i + 1; j <= n; j++)
            if (a[i] == a[j]) {
                puts("YES");
                return;
            }
    puts(Dfs(1, 0) ? "YES" : "NO");
}
int main() {
    int T;
    cin >> T;
    while (T--) solve();
}