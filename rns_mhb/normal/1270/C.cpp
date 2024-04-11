#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 100010

void solve() {
    int n;
    scanf("%d", &n);
    ll sum = 0, xx = 0;
    for(int i = 1; i <= n; i ++) {
        int x;
        scanf("%d", &x);
        sum += x;
        xx ^= x;
    }
    ll b3 = 1ll<<50;
    if(sum & 1) b3 ^= 1;
    sum += b3;
    xx ^= b3;
    ll d = 2*xx - sum;
    puts("3");
    printf("%I64d %I64d %I64d\n", d/2, d/2, b3);
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}