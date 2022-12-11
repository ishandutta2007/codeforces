#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;
int n, p, c, ans = N;
int d[N], a, b;
int main() {
    //freopen("a.in", "r", stdin);

    cin >> n >> p;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b) swap(a, b);
        d[a]++;
        d[b + 1]--;
    }
    for (int i = 0; i <= 1000; i++) {
        c += d[i];
        if (c == n)
            ans = min(ans, abs(i - p));
    }
    cout << (ans == N ? -1 : ans);

    return 0;
}