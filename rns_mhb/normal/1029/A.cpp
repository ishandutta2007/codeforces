#include<bits/stdc++.h>
using namespace std;

char s[55];

int main() {
    int n, k;
    scanf("%d%d%s", &n, &k, s);
    int m = 1;
    for(; m < n; m ++) {
        bool flag = 0;
        for(int j = 0; j + m < n; j ++) if(s[j] != s[j+m]) {
            flag = 1;
            break;
        }
        if(!flag) break;
    }
    for(int i = 1; i < k; i ++) for(int j = 0; j < m; j ++) putchar(s[j]);
    printf("%s\n", s);
}