#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
    int n, m, i;
    scanf("%s", s);
    n = strlen(s);
    if(n == 1) {puts("0"); return 0;}
    for(i = n - 1, n = 0; i >= 0; i --) n += s[i] - '0';
    i = 1;
    while(n > 9) {
        m = 0;
        while(n) m += n % 10, n /= 10;
        n = m;
        i ++;
    }
    printf("%d\n", i);
}