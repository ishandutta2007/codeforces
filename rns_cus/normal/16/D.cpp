#include <bits/stdc++.h>
using namespace std;
 
#define N 111
 
char s[N];
 
int main() {
    int n, rlt = 0, c = 1e9, cnt = 0;
    scanf("%d", &n);
    while (n --) {
        int x, y;
        scanf(" [%02d:%02d ", &x, &y); gets(s);
        x %= 12;
        int d = x * 60 + y;
        
        if (s[0] == 'p') d += 10000;
        if (d < c) rlt ++, cnt = 0;
        else if (d == c) {
            if (cnt == 9) rlt ++, cnt = 0;
            else cnt ++;
        }
        else cnt = 0;
        c = d;
    }
    printf("%d\n", rlt);
 
    return 0;
}