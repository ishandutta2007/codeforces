#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
int n, a[N], b[N];
int go(int a[]) {
    int lst, kol, ans = 0;
    a[n] = -1;
    kol = 1;
    lst = a[0];
    for (int i = 1; i <= n; i++)
        if (a[i] == lst)
            kol++;
        else {
            ans = max(ans, kol);
            kol = 1;
            lst = a[i];
        }
    return ans;
}
int main() {
    //freopen("a.in", "r", stdin);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[i] = a[i];
        if (a[i] % 2)
            a[i]++;
        else
            b[i]++;
    }
    cout << max(go(a), go(b));

    return 0;
}