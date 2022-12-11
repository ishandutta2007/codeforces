#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 34;
typedef long long ll;
typedef long double ld;

int n, k, la = 1, lb = 1, a[N], b[N];
int ans;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')
            a[la++] += i + 1;
        else
            b[lb++] += i + 1;
    }
    a[0] = b[0] = 0;
    a[la++] = b[lb++] = n + 1;

    if (la - 2 <= k) ans = max(ans, a[la - 1] - a[0] - 1);
    if (lb - 2 <= k) ans = max(ans, b[lb - 1] - b[0] - 1);

    for (int i = 0; i + k + 1 < la; i++)
        ans = max(ans, a[i + k + 1] - a[i] - 1);
    for (int i = 0; i + k + 1 < lb; i++)
        ans = max(ans, b[i + k + 1] - b[i] - 1);
    cout << ans;

    return 0;
}