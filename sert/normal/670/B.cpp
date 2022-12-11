//made by Sert
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

ll a[N];
ll n, m, k, p, t;
string s;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);

    scanf("%I64d%I64d", &n, &k);
    for (int i = 1; i <= n; i++)
        scanf("%I64d", a + i);
    for (int i = 1; i <= n; i++) {
        if (k <= i) {
            cout << a[k];
            return 0;
        }
        k -= i;
    }

    return 0;
}