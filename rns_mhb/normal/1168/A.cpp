#include<bits/stdc++.h>
using namespace std;

#define N 300010

int n, m, a[N], b[N];

bool solve(int k) {
    b[0] = 0;
    for(int i = 1; i <= n; i ++) {
        if(a[i] + k < m) {
            if(a[i] + k < b[i-1]) return 0;
            b[i] = max(b[i-1], a[i]);
        }
        else {
            if(a[i] + k - m < b[i-1] && b[i-1] < a[i]) b[i] = a[i];
            else if(a[i] + k - m >= b[i-1]) b[i] = b[i-1];
            else b[i] = b[i-1];
        }
    }
    return 1;
}

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    int L = 0, R = m - 1;
    while(L < R) {
        int M = L + R >> 1;
        if(solve(M)) R = M;
        else L = M + 1;
    }
    printf("%d\n", R);
}