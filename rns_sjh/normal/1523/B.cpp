#include<bits/stdc++.h>
using namespace std;

#define N 1010

int t, n, a[N];

int b[] = {1, 2, 1, 1, 2, 1};

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%d", &n);
        for(int i = 0; i < n; i ++) scanf("%d", a + i);
        printf("%d\n", 3 * n);
        for(int i = 1; i <= n; i += 2) {
            for(int j = 0; j < 6; j ++) printf("%d %d %d\n", b[j], i, i + 1);
        }
    }
}