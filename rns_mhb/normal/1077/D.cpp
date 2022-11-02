#include<bits/stdc++.h>
using namespace std;

#define N 200010

int k, cnt[N];

int main() {
    int n, x;
    scanf("%d%d", &n, &k);
    while(n --) {
        scanf("%d", &x);
        cnt[x] ++;
    }
    int L = 1, R = N;
    while(L < R) {
        int mid = L + R + 1 >> 1;
        long long tot = 0;
        for(int i = 0; i < N; i ++) tot += cnt[i] / mid;
        if(tot < k) R = mid - 1;
        else L = mid;
    }
    for(int i = 0; i < N; i ++) for(int j = 0; j < cnt[i]/R; j ++) {
        printf("%d ", i);
        if(-- k == 0) {putchar('\n');return 0;}
    }
}