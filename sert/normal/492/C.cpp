#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;
long long n, r, avg, sum, ans;
pair <int, int> a[100500];
int main() {
    //freopen("a.in", "r", stdin);
    cin >> n >> r >> avg;
    for (int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
        sum += a[i].second;
    }
    sort(a, a + n);
    for (int i = 0; i < n && sum < avg * n; i++) {
        if (avg * n - sum >= r - a[i].second) {
            sum += r - a[i].second;
            ans += (r - a[i].second) * a[i].first;
        } else {
            ans += (avg * n - sum) * a[i].first;
            sum = avg * n;
        }
    }
    cout << ans;
    return 0;
}