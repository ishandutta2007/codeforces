#include <bits/stdc++.h>
using namespace std;

#define N 1010

char s[N][N];

int main() {
    int n = 0;
    while (gets(s[n])) n ++;
    int len = 0;
    #define pc putchar
    for (int i = 0; i < n; i ++) len = max(len, (int)strlen(s[i]));
    for (int i = 0; i < len + 2; i ++) pc('*'); puts("");
    bool fg = 0;
    for (int i = 0; i < n; i ++) {
        pc('*');
        int m = len - (int)strlen(s[i]);
        int x = m >> 1, y = m - x;
        if (x != y) {
        if (fg) swap(x, y);
        fg ^= 1;
        }
        while (x --) pc(' ');
        printf("%s", s[i]);
        while (y --) pc(' ');
        puts("*");
    }
    for (int i = 0; i < len + 2; i ++) pc('*'); puts("");

    return 0;
}