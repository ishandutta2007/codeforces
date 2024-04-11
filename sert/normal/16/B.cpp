#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long n, m, ans;
pair <long long, long long> a[100500];

int main() {
   // freopen("a.in", "r", stdin);
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> a[i].second >> a[i].first;
    sort(a, a + m);
    for (int i = m - 1; i >= 0; i--) {
        if (a[i].second >= n) {
            ans += a[i].first * n;
            break;
        }
        ans += a[i].second * a[i].first;
        n -= a[i].second;
    }
    cout << ans;
    return 0;
}