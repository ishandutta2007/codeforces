#include<bits/stdc++.h>
using namespace std;

int ch(char c) {return c - '0';}

int main() {
    int n, i, j, ans, cnt = 0, B[11], C[11], a, b, c, d, x, y;
    char E[11][6], *s;
    scanf("%d", &n);
    for(i = 0; i < n; i ++) scanf("%s%d%d", E[i], B + i, C + i);
    for(a=0;a<10;a++)for(b=0;b<10;b++)for(c=0;c<10;c++)for(d=0;d<10;d++){
        if(a == b || a == c || a == d || b == c || b == d || c == d) continue;
        for(i = 0; i < n; i ++) {
            s = E[i];
            x = 0, y = 0;
            if(a == ch(s[0])) x ++;
            if(b == ch(s[1])) x ++;
            if(c == ch(s[2])) x ++;
            if(d == ch(s[3])) x ++;
            for(j = 0; j < 4; j ++) {
                if(a == ch(s[j])) y ++;
                if(b == ch(s[j])) y ++;
                if(c == ch(s[j])) y ++;
                if(d == ch(s[j])) y ++;
            }
            if(x != B[i] || y - x != C[i]) break;
        }
        if(i == n) {
            cnt ++;
            ans = a * 1000 + b * 100 + c * 10 + d;
        }
    }
    if(cnt == 0) puts("Incorrect data");
    if(cnt > 1) puts("Need more data");
    if(cnt == 1) printf("%04d\n", ans);
}