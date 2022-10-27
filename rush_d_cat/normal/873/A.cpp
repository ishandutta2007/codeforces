#include <iostream>
#include <algorithm>
using namespace std;

int n, k, x;
int a[102];
bool cmp(int x, int y) {return x > y;}
int main() {
    scanf("%d %d %d", &n, &k, &x);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n, cmp);
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        if (i <= k && a[i] >= x) ans += x;
        else ans += a[i];
    }
    cout << ans << endl;
}