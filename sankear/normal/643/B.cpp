#include <cstdio>
#include <vector>
#include <memory.h>
using namespace std;

const int N = 1050;

int num[N];

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    if (n == 4) {
        puts("-1");
        return 0;
    }
    if (k == n - 1 || k == n) {
        puts("-1");
        return 0;
    }
    memset(num, -1, sizeof(num));
    num[0] = a;
    num[n - 1] = b;
    num[1] = c;
    num[3] = d;
    int pt = 1;
    for (int i = 0; i < n; i++) {
        if (num[i] != -1)
            continue;
        while (pt == a || pt == b || pt == c || pt == d)
            pt++;
        num[i] = pt;
        pt++;
    }
    vector<int> ans[2];
    for (int i = 0; i < n; i++) {
        ans[0].push_back(i);
    }
    ans[1].push_back(1);
    ans[1].push_back(0);
    ans[1].push_back(2);
    for (int i = n - 1; i >= 3; i--)
        ans[1].push_back(i);
    for (int t = 0; t < 2; t++) {
        for (int i = 0; i < n; i++) {
            printf("%d%c", num[ans[t][i]], " \n"[i + 1 == n]);
        }
    }
}