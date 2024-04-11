#include <cstdio>
#include <vector>

using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int i = 0; i < (int)(n); i++) {
        scanf("%d", &a[i]);
        a[i] -= 100;
    }

    int ans = 0;
    int cur = 0;

    for (int i = 0; i < n; i++) {
        cur += a[i];
        if (cur > 0) ans = i + 1;
        else {
            int c2 = 0;
            for (int j = 0; j + ans < i; j++) {
                c2 += a[j];
                if (c2 < cur && i - j > ans)
                    ans = i - j;
            }
        }
    }
    printf("%d\n", ans);

    return 0;
}