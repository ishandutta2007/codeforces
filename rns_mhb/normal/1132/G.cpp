#include<bits/stdc++.h>
using namespace std;

#define N 1000010

int n, k, a[N], L[N], p[N], v[N];

int go(int x) {return x == p[x] ? x : p[x] = go(p[x]);}

int main() {
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
    for(int i = 1; i <= n; i ++) {
        L[i] = i - 1;
        while(L[i] && a[L[i]] < a[i]) L[i] = L[L[i]];
    }
    for(int i = 1, j = 1, sum = 0; i <= n; i ++) {
        p[i] = i;
        int l = go(L[i] + 1);
        if(l <= j) sum ++;
        v[l] ++, v[i+1] --;
        if(l) p[l] = l - 1;
        if(i >= k) {
            printf("%d ", sum);
            sum += v[++ j];
        }
    }
    puts("");
}