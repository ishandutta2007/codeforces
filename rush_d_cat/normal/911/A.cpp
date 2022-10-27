#include <iostream>
using namespace std;
const int N = 100000+10;
int n, a[N];
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a[i]);
    }
    int minc = 1e9+2;
    for (int i = 1; i <= n; i ++)
        minc = min(minc, a[i]);

    int pos = 0, ans = n;
    for (int i = 1; i <= n; i ++) {
        if (a[i] == minc) {
            if (pos) {
                ans = min(ans, i - pos);
            }
            pos = i;
        }
    }
    printf("%d\n", ans);
}