#include<bits/stdc++.h>
using namespace std;

#define N 200010

char s[N];

int main() {
    scanf("%s", s);
    int n = strlen(s);
    for(int i = n; i < 2 * n; i ++) s[i] = s[i-n];
    int ans = 0, cur = 1;
    for(int i = 0; i < 2 * n - 1; i ++) {
        if(s[i] != s[i+1]) cur ++;
        else {
            if(ans < cur) ans = cur;
            cur = 1;
        }
    }
    if(ans < cur) ans = cur;
    printf("%d\n", min(ans, n));
}