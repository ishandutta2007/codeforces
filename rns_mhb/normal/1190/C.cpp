#include<bits/stdc++.h>
using namespace std;

#define N 100010

char s[N];
int L[N][2], R[N][2], nxt[N][2], prv[N][2];

int main() {
    int n, k;
    scanf("%d%d%s", &n, &k, s+1);
    L[0][0] = 1, L[0][1] = 1;
    for(int i = 1; i <= n; i ++) L[i][s[i]-'0'] = L[i-1][s[i]-'0'];
    R[n+1][0] = 1, R[n+1][1] = 1;
    for(int i = n; i; i --) R[i][s[i]-'0'] = R[i+1][s[i]-'0'];
    for(int l = 1, r = k; r <= n; l ++, r ++) {
        if(L[l-1][0] && R[r+1][0]) {
            puts("tokitsukaze");
            return 0;
        }
        if(L[l-1][1] && R[r+1][1]) {
            puts("tokitsukaze");
            return 0;
        }
    }
    prv[0][0] = prv[0][1] = 1;
    for(int i = 1; i <= n; i ++) {
        if(s[i] == '0') {
            prv[i][0] = prv[i-1][0];
            prv[i][1] = i;
        }
        if(s[i] == '1') {
            prv[i][1] = prv[i-1][1];
            prv[i][0] = i;
        }
    }
    nxt[n+1][0] = nxt[n+1][1] = n + 1;
    for(int i = n; i; i --) {
        if(s[i] == '0') {
            nxt[i][0] = nxt[i+1][0];
            nxt[i][1] = i;
        }
        if(s[i] == '1') {
            nxt[i][1] = nxt[i+1][1];
            nxt[i][0] = i;
        }
    }
    bool flag = 0;
    for(int l = 1, r = k; r <= n; l ++, r ++) {
        for(int x = 0; x < 2; x ++) {
            int ll, rr;
            ll = max(prv[l-1][x] - k + 1, 1);
            rr = min(nxt[r+1][x] + k - 1, n);
            if(L[ll-1][x] && R[r+1][x]) continue;
            if(L[l-1][x] && R[rr+1][x]) continue;
            flag = 1;
            break;
        }
        if(flag == 1) break;
    }
    if(!flag) puts("quailty");
    else puts("once again");
}