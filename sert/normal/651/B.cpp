#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const int N = 1e6 + 34;

int n, a[N], u[N];
int ans, kol, lst;

int main() {
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    while (kol < n) {
        lst = -1;
        ans--;
        for (int i = 0; i < n; i++)
        if (!u[i] && a[i] > lst) {
            lst = a[i];
            u[i] = true;
            kol++;
            ans++;
        }
    }

    cout << ans;




    return 0;
}