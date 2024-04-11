#include<bits/stdc++.h>
using namespace std;

char s[111], prt[111];

int main() {
    int len, n = 0, i;
    scanf("%s", s);
    len = strlen(s);
    for(i == 0; i < len; i ++) {
        if(s[i] != '/') prt[n ++] = s[i];
        else if(i == 0 || s[i - 1] != '/') prt[n ++] = s[i];
    }
    if(n == 1) puts("/");
    else {
        for(i = 0; i < n - 1; i ++) putchar(prt[i]);
        if(prt[i] != '/') putchar(prt[i]);
    }
}