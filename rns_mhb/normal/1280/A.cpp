#include<bits/stdc++.h>
using namespace std;

#define N 1000010

const int mod = 1e9 + 7;

char s[N<<2];

void solve() {
    int n;
    scanf("%d%s", &n, s+1);
    int len = strlen(s+1);
    bool big = 0;
    for(int c = 1; c <= n; c ++) {
        int g = s[c] - '1';
        if(big == 0) {
            int L = len;
            while(g --) for(int j = c+1; j <= L; j ++) s[++ len] = s[j];
        }
        else {
            len = (len + 1ll * g * (len-c)) % mod;
            if(len < 0) len += mod;
        }
        if(len >= n) big = 1;
    }
    printf("%d\n", len);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}