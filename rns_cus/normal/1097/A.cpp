#include <bits/stdc++.h>
using namespace std;

char s[10], t[10];

int main() {
    bool fg = 0;
    scanf("%s", t);
    for (int i = 0; i < 5; i ++) {
        scanf("%s", s);
        if (s[0] == t[0] || s[1] == t[1]) fg = 1;
    }
    puts(fg ? "YES" : "NO");
}