#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, len;
    char s[111];
    scanf("%d", &n);
    while(n --) {
        scanf("%s", s);
        len = strlen(s);
        if(len <= 10) puts(s);
        else printf("%c%d%c\n", s[0], len - 2, s[len - 1]);
    }
}