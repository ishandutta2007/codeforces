#include<bits/stdc++.h>
using namespace std;

#define N 100010

int a[N];

void solve() {
    int n;
    scanf("%d", &n);
    int x = 0;
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]), x ^= a[i];
    if(x == 0) puts("DRAW");
    else {
        int y = 30;
        while(x >> y & 1 ^ 1) y --;
        int m = 0, k = 0;
        for(int i = 0; i < n; i ++) {
            if(a[i] >> y & 1) m ++;
            else k ++;
        }
        if(k % 2 == 1) puts("WIN");
        else if(m % 4 == 3) puts("LOSE");
        else puts("WIN");
    }
}

int main() {
    int t;
    scanf("%d", &t);
    while(t --) solve();
}