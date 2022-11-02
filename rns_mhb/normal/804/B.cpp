#include<bits/stdc++.h>
using namespace std;

#define N 1000005
const int mod = 1e9 + 7;

char s[N];
int a[N], n, m, ans;

int main() {
    scanf("%s", s);
    int len = strlen(s), i = 0;
    while(s[i] == 'b') i ++;
    if(i == len) {puts("0"); return 0;}
    for(i ++; i <= len; i ++) {
        if(s[i] == 'a' || i == len) {
            a[n ++] = m;
            m = 0;
        }
        else m ++;
    }
    for(i = n - 1; i >= 0; i --) {
        ans = (ans + a[i]) % mod;
        if(i) a[i - 1] = (a[i - 1] + a[i] * 2 % mod) % mod;
    }
    printf("%d\n", ans);
}