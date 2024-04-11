#include <bits/stdc++.h>
using namespace std;

char s[10];
int pw[40];

int main() {
    pw[0] = 1;
    for (int i = 1; i <= 30; i ++) pw[i] = 2 * pw[i-1];
    while (1) {
        scanf("%s", s);
        if (s[0] == 'e') break;
        puts("? 0 1");
        fflush(stdout);
        scanf("%s", s);
        if (s[0] == 'x') {
            puts("! 1");
            fflush(stdout);
            continue;
        }
        int k = 0;
        while (k < 29) {
            printf("? %d %d\n", pw[k+1], pw[k]);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'y') break;
            k ++;
        }
        int l = 0, r = pw[k];
        while (l < r - 1) {
            int m = l + r >> 1;
            printf("? %d %d\n", pw[k+1], m);
            fflush(stdout);
            scanf("%s", s);
            if (s[0] == 'x') l = m;
            else assert(s[0] == 'y'), r = m;
        }
        printf("! %d\n", pw[k+1] - l);
        fflush(stdout);
    }
    return 0;
}