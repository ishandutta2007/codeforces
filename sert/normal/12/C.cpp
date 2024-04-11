#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
typedef long double ld;

string s[N], t;
int k[N];
int p[N];
int n, m, len;

int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> p[i];
    for (int i = 0; i < m; i++) {
        cin >> t;
        s[len] = t;
        k[len++] = 1;
        for (int j = 0; j + 1 < len; j++)
            if (s[j] == t) {
                k[j]++;
                k[--len]--;
                break;
            }
    }
    sort(k, k + len);
    sort(p, p + n);

    int mn = 0, mx = 0;
    for (int i = 0; i < len; i++) {
        mx += k[i] * p[i + n - len];
        mn += k[i] * p[len - i - 1];
    }

    cout << mn << " " << mx << "\n";

    return 0;
}