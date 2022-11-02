#include<bits/stdc++.h>
using namespace std;

const int mod = 998244353;

#define N 200010

char s[N];

int main() {
    int n;
    scanf("%d%s", &n, s);
    int x = 1;
    while(x < n && s[x] == s[x-1]) x ++;
    if(x == n) {
        printf("%d\n", 1ll * n * (n + 1) / 2 % mod);
        return 0;
    }
    int y = n - 2;
    while(y >= 0 && s[y] == s[y+1]) y --;
    y = n - 1 - y;
    if(s[0] == s[n-1]) {
        printf("%d\n", 1ll * (x+1) * (y+1) % mod);
        return 0;
    }
    printf("%d\n", x + y + 1);
}