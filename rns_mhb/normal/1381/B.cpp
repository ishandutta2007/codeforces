#include<bits/stdc++.h>
using namespace std;

#define N 2010

int p[N<<1];
int st[N<<1];
bool dp[N];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; i ++) scanf("%d", &p[i]);
    p[2*n+1] = 2*n+1;
    st[0] = 2*n+1;
    int m = 0;
    for(int i = 2*n; i; i --) {
        while(p[st[m]] < p[i]) m --;
        st[++ m] = i;
    }
    for(int i = 0; i <= n; i ++) dp[i] = 0;
    dp[0] = 1;
    for(int i = 1; i <= m; i ++) {
        int x = st[i-1] - st[i];
        for(int i = n; i >= x; i --) if(dp[i-x]) dp[i] = 1;
    }
    if(dp[n]) puts("YES");
    else puts("NO");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t--) solve();
}