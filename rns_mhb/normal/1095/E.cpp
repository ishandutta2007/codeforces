#include<bits/stdc++.h>
using namespace std;

#define N 1000010

char s[N];
int n, cnt[N], mnl[N], mnr[N];

int main() {
    scanf("%d%s", &n, s + 1);
    for(int i = 1; i <= n; i ++)
        if(s[i] == '(') cnt[i] = 1;
        else cnt[i] = -1;
    for(int i = 1; i <= n; i ++) cnt[i] += cnt[i-1];
    mnl[0] = mnr[n+1] = N;
    for(int i = 1; i <= n; i ++) mnl[i] = min(mnl[i-1], cnt[i]);
    for(int i = n; i; i --) mnr[i] = min(mnr[i+1], cnt[i]);
    int ans = 0;
    if(cnt[n] == 2) for(int i = 1; i <= n; i ++) ans += (s[i] == '(' && mnl[i-1] >= 0 && mnr[i] >= 2);
    else if(cnt[n] == -2) for(int i = 1; i <= n; i ++) ans += (s[i] == ')' && mnl[i-1] >= 0 && mnr[i] >= -2);
    printf("%d\n", ans);
}