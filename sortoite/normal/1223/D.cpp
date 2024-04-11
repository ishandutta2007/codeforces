#include<bits/stdc++.h>
using namespace std;

const int NN = 3e5+10;

int a[NN], fst[NN], lst[NN], dp[NN], b[NN], m, can[NN];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++) fst[i] = lst[i] = 0;
    for(int i=1; i<=n; i++) {
        scanf("%d", a+i);
        if(fst[a[i]] == 0) fst[a[i]]=i;
        lst[a[i]]=i;
    }
    m=0;
    for(int i=1; i<=n; i++) {
        if(fst[i]) {
            b[++m]=i;
        }
    }
    for(int i=1; i<m; i++) {
        can[i] = lst[b[i]] < fst[b[i+1]];
    }
    if(m == 1) {
        puts("0");
        return;
    }
    int mx=0;
    for(int i=1, j; i<m; i=j) {
        while(i<m && can[i] == 0) i++;
        if(i>=m) break;
        for(j=i; j<m && can[j]; j++);
        mx=max(mx, j-i);
    }
    printf("%d\n", m-mx-1);
}

int main() {
    //freopen("D.in", "r", stdin);
    int T;
    cin>>T;
    while(T--) solve();
    return 0;
}