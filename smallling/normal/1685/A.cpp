#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int a[N], b[N];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++)
            scanf("%d", &a[i]);
        if(n & 1 == 1) {
            puts("NO");
            continue;
        }
        sort(a + 1, a + 1 + n);
        reverse(a + 1, a + 1 + n);
        int x = 1;
        for(int i = n / 2; i; i--) {
            b[x] = a[x / 2 + 1];
            x += 2;
        }
        x = 2;
        for(int i = n / 2; i; i--) {
            b[x] = a[n / 2 + x / 2];
            x += 2;
        }
        int flag = 0;
        for(int i = 2; i <= n; i++) {
            if(b[i] == b[i - 1] || b[i] == b[i % n + 1]) {
                flag = 1;
                break;
            }
        }
        if(flag) {
            puts("NO");
            continue;
        }
        puts("YES");
        for(int i = 1; i <= n; i++) {
            printf("%d", b[i]);
            if(i == n)puts("");
            else putchar(' ');
        }

    }
}