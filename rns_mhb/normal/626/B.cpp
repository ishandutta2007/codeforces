#include <bits/stdc++.h>
using namespace std;

int n, r, g, b, cnt, fr, fg, fb;
char ch;
char ans[4];

int main() {
    scanf("%d ", &n);
    while (n --) {
        ch = getchar();
        if (ch == 'R') r ++;
        if (ch == 'B') b ++;
        if (ch == 'G') g ++;
    }
    bool flag = 0;
    if (!r) {
        if (!g || !b) flag = 0;
        else flag = 1;
    }
    else {
        if (!g && !b) flag = 1;
        else if (g + b == 1) flag = 0;
        else flag = 1;
    }
    if (flag) ans[cnt++] = 'R';
    flag = 0;
    if (!g) {
        if (!r || !b) flag = 0;
        else flag = 1;
    }
    else {
        if (!r && !b) flag = 1;
        else if (b + r == 1) flag = 0;
        else flag = 1;
    }
    if (flag) ans[cnt++] = 'G';
    flag = 0;
    if (!b) {
        if (!g || !r) flag = 0;
        else flag = 1;
    }
    else {
        if (!g && !r) flag = 1;
        else if (g + r == 1) flag = 0;
        else flag = 1;
    }
    if (flag) ans[cnt++] = 'B';
    sort(ans, ans + cnt);
    puts(ans);
}