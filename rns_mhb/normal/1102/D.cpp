#include<bits/stdc++.h>
using namespace std;

char s[300010];
int n, cnt[256];

void up(int a, int b) {
    if(cnt[a] <= n / 3) return;
    for(int i = 0; i < n; i ++) if(s[i] == '0' + a) {
        if(cnt[b] >= n / 3) return;
        s[i] = '0' + b;
        cnt[b] ++;
        cnt[a] --;
        if(cnt[a] == n / 3) return;
    }
}

void down(int a, int b) {
    if(cnt[a] <= n / 3) return;
    for(int i = n - 1; i >= 0; i --) if(s[i] == '0' + a) {
        if(cnt[b] >= n / 3) return;
        s[i] = '0' + b;
        cnt[b] ++;
        cnt[a] --;
        if(cnt[a] == n / 3) return;
    }
}

int main() {;
    scanf("%d%s", &n, s);
    for(int i = 0; i < n; i ++) cnt[s[i]-'0'] ++;
    up(2, 0), up(2, 1), up(1, 0), down(1, 2), down(0, 2), down(0, 1);
    puts(s);
}