#include<bits/stdc++.h>
using namespace std;

char s[300010];

int main() {
    int n;
    scanf("%d%s", &n, s + 1);
    long long ans = 1ll * n * (n-1) / 2;
    for(int i = 1, j = 0; i <= n; i ++) {
        if(s[i] == 'A') ans -= j, j = 0;
        else j ++;
    }
    for(int i = 1, j = 0; i <= n; i ++) {
        if(s[i] == 'B') ans -= j, j = 0;
        else j ++;
    }
    for(int i = n, j = 0; i; i --) {
        if(s[i] == 'A') ans -= j, j = 0;
        else j ++;
    }
    for(int i = n, j = 0; i; i --) {
        if(s[i] == 'B') ans -= j, j = 0;
        else j ++;
    }
    for(int i = 1; i < n; i ++) if(s[i] != s[i+1]) ans ++;
    cout << ans << endl;
}