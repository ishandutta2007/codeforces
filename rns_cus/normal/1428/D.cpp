#include <bits/stdc++.h>
using namespace std;

#define N 100100

int n, a[N], b[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    vector <int> vec;
    int last = 0;
    int ans = 0;
    for (int i = n; i >= 1; i --) {
        if (!a[i]) continue;
        ans ++;
        if (a[i] == 1) vec.push_back(i);
        else if (a[i] == 2) {
            if (!last) last = i;
            if (vec.empty()) return puts("-1"), 0;
            b[i] = vec.back(); vec.pop_back();
        }
        else {
            if (!last) {
                if (vec.empty()) return puts("-1"), 0;
                b[i] = vec.back(); vec.pop_back();
            }
            else b[i] = last;
            last = i; ans ++;
        }
    }
    printf("%d\n", ans);
    for (int i = 1, r = 0; i <= n; i ++) {
        if (!a[i]) continue;
        r ++;
        if (a[i] == 1) {
            printf("%d %d\n", r, i);
        }
        else if (a[i] == 2) {
            printf("%d %d\n", r, i);
            printf("%d %d\n", r, b[i]);
            a[b[i]] = 0;
        }
        else {
            printf("%d %d\n", r, i);
            printf("%d %d\n", r, b[i]);
            if (a[b[i]] == 1) b[i] = 0;
        }
    }

    return 0;
}