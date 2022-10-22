#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 1e5 + 13;

int n, m, x;
int a[N], b[N];

li get(int k) {
    li res = 0;

    for(int i = 0; i < k; i++)
        res += max(0, b[i] - a[k - i - 1]);

    return res;
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n >> m >> x;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        cin >> b[i];

    sort(b, b + m);
    sort(a, a + n);
    reverse(a, a + n);

    int l = 0, r = min(m, n) + 1;
    while(r - l > 1) {
        int mid = (l + r) / 2;

        if(get(mid) > x)
            r = mid;
        else
            l = mid;
    }

    li ans = 0;
    for(int i = 0; i < l; i++)
        ans += b[i];

    ans = max(0ll, ans - x);

    cout << l << ' ' << ans << endl;
}