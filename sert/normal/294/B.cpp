#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N = 1e5 + 34;
const ll INF = 1e9;

int n, t, x, k2, k1, ans = INF, cur;
int a1[N], a2[N], p1[N], p2[N];

int main() {

    srand(3431);

    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t >> x;
        if (t == 1) a1[k1++] = x;
        else a2[k2++] = x;
    }
    sort(a1, a1 + k1);
    sort(a2, a2 + k2);

    for (int i = 1; i <= k1; i++) p1[i] = p1[i - 1] + a1[i - 1];
    for (int i = 1; i <= k2; i++) p2[i] = p2[i - 1] + a2[i - 1];

    for (int i = 0; i <= k1; i++)
        for (int j = 0; j <= k2; j++) {
            cur = k1 - i + (k2 - j) * 2;
            if (cur >= p1[i] + p2[j]) {
                ans = min(ans, cur);
            }
        }

    cout << ans;

    //while(true);
}