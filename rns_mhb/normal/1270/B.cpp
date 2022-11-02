#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

#define N 200010

int a[N];

void solve() {
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i < n; i ++) {
        if(abs(a[i] - a[i+1]) > 1) {
            puts("YES");
            printf("%d %d\n", i, i+1);
            return;
        }
    }
    puts("NO");
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}