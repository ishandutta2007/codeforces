#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 34;
int n, m, x;
int a[N], sum, ln, t, len;
bool u[N];
int b[N], c[N];

int main() {
    // freopen("a.in", "r", stdin);
    // freopen("a.out", "w", stdout);

    srand(3431);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        a[i] = a[i] % m;
    }
    sort(a, a + n);
    b[len++] = a[0];
    for (int i = 1; i < n; i++)
        if (a[i] != a[i - 1])
            b[len++] = a[i];
        else
            c[ln++] = a[i];

    random_shuffle(b, b + len);
    while (len > 20) {
        c[ln++] = b[len - 1];
        len--;
    }

    for (int i = 1; i < (1 << len); i++) {
        t = i;
        sum = 0;
        for (int j = 0; j < len; j++) {
            if (t % 2)
                sum += b[j];
            t /= 2;
        }
        if (sum % m == 0) {
            cout << "YES\n";
            return 0;
        }
        u[m - sum % m] = true;
    }

    u[0] = true;

    while (clock() * 5 < 9 * CLOCKS_PER_SEC) {
        sum = 0;
        random_shuffle(c, c + ln);
        for (int i = 0; i < ln; i++) {
            sum += c[i];
            if (u[sum % m]) {
                cout << "YES\n";
                return 0;
            }
        }
    }

    cout << "NO\n";

    return 0;
}