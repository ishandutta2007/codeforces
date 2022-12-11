#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cstring>

using namespace std;

typedef int ll;

const ll N = 2e5 + 34;
char s[N];
ll a[N], p[N], ans, ta;
ll n, m;

int main() {

    //freopen("a.in", "r", stdin);

    ///Test: #33, : 0 ., : 0 ,  : 0,   : 0, : CRASHED

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    scanf("%s", s);
    m = strlen(s);

    /*for (int i = 0; i < m / 2; i++)
        swap(s[i], s[m - i - 1]);*/

    p[0] = 0;
    for (int i = 0; i < n; i++)
        p[i + 1] = p[i] + a[i];

    for (int i = 0; i < m; i++)
        if (s[i] == '1')
            ans += a[i];

    for (int i = m - 1; i >= 0; i--) {
        if (s[i] == '1') {
            ans = max(ans, ta + p[i]);
            ta += a[i];
        }
    }

    cout << ans;

    return 0;
}