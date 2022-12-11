#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6 + 34;
ll n, a[N], b, ans;
int main()  {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> b;
        a[b - 1] = i;
    }
    for (int i = 1; i < n; i++)
        ans += abs(a[i] - a[i - 1]);
    cout << ans;

    return 0;
}