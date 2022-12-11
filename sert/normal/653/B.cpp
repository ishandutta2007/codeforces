#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll md = 1e9 + 7;
typedef long double ld;
const int N = 1e6 + 34;

int n, k;
string a[N], b[N];
int c[N];
int ans;

void go(int len) {
    if (len == k) {
        if (b[c[k - 1]] != "a") return;
        for (int i = 1; i < k; i++)
            if (b[c[i - 1]][0] != a[c[i]][0])
                return;
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        c[len] = i;
        go(len + 1);
    }
}

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    cin >> k >> n;
    k--;
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    go(0);
    cout << ans;

    return 0;
}