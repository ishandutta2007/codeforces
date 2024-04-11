#include<bits/stdc++.h>
using namespace std;

char s[100010];

int main() {
    int cnt = 0, ans = 0, i, j, add = 0, n;
    scanf("%d%s", &n, s);
    for(i = j = 0; s[i]; i = j) {
        while(s[i] == s[j]) j ++;
        ans ++;
        if(j - i > 1) cnt ++;
        if(j - i > 2) add = 2;
    }
    printf("%d\n", ans + max(add, min(cnt, 2)));
}