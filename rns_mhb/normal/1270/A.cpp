#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200010

int a[N];

void solve() {
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    int ma = -1, mb =-1;
    while(a --) {
        int x;
        scanf("%d", &x);
        ma = max(ma, x);
    }
    while(b --) {
        int x;
        scanf("%d", &x);
        mb = max(mb, x);
    }
    if(ma > mb) puts("YES");
    else puts("NO");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}