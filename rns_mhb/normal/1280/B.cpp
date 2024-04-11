#include<bits/stdc++.h>
using namespace std;

#define N 66

int n, m;
char s[N][N];

bool bad() {
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(s[i][j] == 'A') return 0;
    return 1;
}

bool zero() {
    for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) if(s[i][j] == 'P') return 0;
    return 1;
}

bool one() {
    bool flag = 1;
    for(int i = 1; i <= m; i ++) {
        if(s[1][i] == 'P') {
            flag = 0;
            break;
        }
    }
    if(flag) return 1;
    flag = 1;
    for(int i = 1; i <= m; i ++) {
        if(s[n][i] == 'P') {
            flag = 0;
            break;
        }
    }
    if(flag) return 1;
    flag = 1;
    for(int i = 1; i <= n; i ++) {
        if(s[i][1] == 'P') {
            flag = 0;
            break;
        }
    }
    if(flag) return 1;
    flag = 1;
    for(int i = 1; i <= n; i ++) {
        if(s[i][m] == 'P') {
            flag = 0;
            break;
        }
    }
    if(flag) return 1;
    return 0;
}

bool two() {
    for(int i = 1; i <= n; i ++) {
        bool flag = 1;
        for(int j = 1; j <= m; j ++) if(s[i][j] == 'P') {
            flag = 0;
            break;
        }
        if(flag) return 1;
    }
    for(int j = 1; j <= m; j ++) {
        bool flag = 1;
        for(int i = 1; i <= n; i ++) if(s[i][j] == 'P') {
            flag = 0;
            break;
        }
        if(flag) return 1;
    }
    if(s[1][1] == 'A') return 1;
    if(s[n][1] == 'A') return 1;
    if(s[1][m] == 'A') return 1;
    if(s[n][m] == 'A') return 1;
    return 0;
}

bool three() {
    for(int i = 1; i <= n; i ++) if(s[i][1] == 'A') return 1;
    for(int i = 1; i <= n; i ++) if(s[i][m] == 'A') return 1;
    for(int i = 1; i <= m; i ++) if(s[1][i] == 'A') return 1;
    for(int i = 1; i <= m; i ++) if(s[n][i] == 'A') return 1;
    return 0;
}

void solve() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%s", s[i]+1);
    if(bad()) {
        puts("MORTAL");
        return;
    }
    if(zero()) {
        puts("0");
        return;
    }
    if(one()) {
        puts("1");
        return;
    }
    if(two()) {
        puts("2");
        return;
    }
    if(three()) {
        puts("3");
        return;
    }
    puts("4");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}