#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

const double eps = 1e-8;

vector<pair<int, int> > ways[1111];

int ok(int t) {
    int tt = (int)(sqrt(1.0 * t) + eps);
    if (tt * tt != t)
        return 0;
    return tt;
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    bool flag = false;
    for(int i = 1; i < a; i++) {
        if (!ok(a * a - i * i))
            continue;
        int aa = ok(a * a - i * i);
        for(int j = 1; j < b; j++) {
            if (!ok(b * b - j * j))
                continue;
            if (i == 3 && j == 4) {
                i = 3;
            }
            int bb = ok(b * b - j * j);
            if (i * b != a * bb)
                continue;
            if (j * a != b * aa)
                continue;
            if (aa == bb)
                continue;
            flag = true;
            printf("YES\n");
            printf("0 0\n");
            printf("%d %d\n", i, aa);
            printf("%d %d\n", -j, bb);
            return 0;
        }
    }
    
    if (!flag) {
        printf("NO\n");
    }
    return 0;
}