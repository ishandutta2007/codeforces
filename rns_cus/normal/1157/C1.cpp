#include <bits/stdc++.h>
using namespace std;

#define N 200010

int n, a[N];
char s[N];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int cur = 0, len = 0;
    int x = 1, y = n;
    while (1) {
        if (x > y) break;
        if (x == y) {
            s[len++] = 'L';
            break;
        }
        if (a[x] <= cur && a[y] <= cur) break;
        int left = 0, right = 0, fg = 0;
        if (a[y] <= cur || a[x] == a[y]) {
            left = 1;
            for (int j = x + 1; ; j ++, left ++)
                if (a[j] <= a[j-1]) break;
            fg = 1;
        }
        if (a[x] <= cur || a[x] == a[y]) {
            right = 1;
            for (int j = y - 1; ; j --, right ++)
                if (a[j] <= a[j+1]) break;
            fg = 1;
        }
        if (fg) {
            int k = max(left, right);
            for (int j = 0; j < k; j ++) s[len++] = k == left ? 'L' : 'R';
            break;
        }
        else {
            if (a[x] < a[y]) s[len++] = 'L', cur = a[x++];
            else s[len++] = 'R', cur = a[y--];
        }
    }
    printf("%d\n%s", len, s);
}