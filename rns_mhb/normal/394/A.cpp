#include<bits/stdc++.h>
using namespace std;

int main() {
    char s[400];
    int i, a, b, c;
    scanf("%s", s);
    int len = strlen(s);
    for(i = 0; i < len; i ++) if(s[i] == '+') {a = i; break;}
    for(i = 0; i < len; i ++) if(s[i] == '=') {b = i; break;}
    c = len - b - 1;
    b -= a + 1;
    if(a + b - c & 1) {puts("Impossible"); return 0;}
    if(abs(a + b - c) > 2) {puts("Impossible"); return 0;}
    if(abs(a + b - c) == 0) {puts(s); return 0;}
    if(a + b > c) {
        c ++;
        if(a > 1) a --;
        else b --;
    }
    if(a + b < c) {
        c --;
        a ++;
    }
    while(a --) putchar('|'); putchar('+');
    while(b --) putchar('|'); putchar('=');
    while(c --) putchar('|'); putchar('\n');
}