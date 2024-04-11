#include <stdio.h>
#include <algorithm>
using namespace std;
typedef long long ll;

ll w, m;
ll ww[101] = {1};

int main() {
    scanf("%I64d %I64d", &w, &m);
    if (w <= 3 || m <= 1) {
        puts("YES");
        return 0;
    }
    for (int i = 1; i <= 100; i++)
        ww[i] = ww[i-1] * w;

    int u = 100;

    while (m && u >= 0) {
        int a;
        ll s = 0;
        for (a = 0; a <= u; a++) {
            s += ww[a];
            if (s >= m) break;
        }
        if (a > u) a--;
        m = ww[a] - m;
        if (m < 0) m = -m;
        u = a - 1;
    }
    puts(m ? "NO" : "YES");
    return 0;
}