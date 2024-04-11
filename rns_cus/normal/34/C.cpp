#include <bits/stdc++.h>
using namespace std;

#define N 1010

bool vis[N];

int main() {
    #define gc getchar
    while (1) {
        char c = gc();
        if (c == EOF) break;
        int x = 0;
        for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
        vis[x] = 1;
    }
    for (int i = 1, fg = 0; i < N; i ++) {
        if (!vis[i]) continue;
        int j;
        for (j = i; j < N && vis[j]; j ++);
        if (fg) putchar(','); fg = 1;
        if (j == i + 1) printf("%d", i);
        else printf("%d-%d", i, j - 1);
        i = j;
    }
    puts("");

    return 0;
}