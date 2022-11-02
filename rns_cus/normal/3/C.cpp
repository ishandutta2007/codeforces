#include <bits/stdc++.h>
using namespace std;

char s[10][10];

bool check() {
    for (int i = 0; i < 3; i ++) {
        if (s[i][0] == '.') continue;
        if (s[i][1] == s[i][0] && s[i][2] == s[i][0]) return 1;
    }
    for (int j = 0; j < 3; j ++) {
        if (s[0][j] == '.') continue;
        if (s[1][j] == s[0][j] && s[2][j] == s[0][j]) return 1;
    }
    char c = s[1][1];
    if (c == '.') return 0;
    if (s[0][0] == c && s[2][2] == c) return 1;
    if (s[0][2] == c && s[2][0] == c) return 1;
    return 0;
}

int main() {
    for (int i = 0; i < 3; i ++) scanf("%s", s[i]);
    int cnt = 0;
    for (int i = 0; i < 3; i ++) for (int j = 0; j < 3; j ++)
    if (s[i][j] == '0') cnt --; else if (s[i][j] == 'X') cnt ++;
    if (cnt != 0 && cnt != 1) return puts("illegal"), 0;
    if (!check()) {
        for (int i = 0; i < 3; i ++) for (int j = 0; j < 3; j ++) if (s[i][j] == '.') return puts(cnt ? "second" : "first");
        return puts("draw"), 0;
    }
    bool win = 0;
    for (int i = 0; i < 3; i ++) {
        for (int j = 0; j < 3; j ++) {
            char c = s[i][j];
            if (c == '.') continue;
            int x = cnt;
            if (c == '0') x ++;
            else x --;
            if (x != 0 && x != 1) continue;
            s[i][j] = '.';
            if (!check()) win = 1;
            s[i][j] = c;
        }
    }
    if (win) puts(cnt ? "the first player won" : "the second player won");
    else puts("illegal");


    return 0;
}