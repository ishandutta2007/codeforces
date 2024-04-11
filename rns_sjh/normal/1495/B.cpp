#include<bits/stdc++.h>
using namespace std;

#define N 100010

int n, p[N], l[N], r[N], L[N], R[N], ml[N], mr[N];

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &p[i]);
    l[1] = 1, r[n] = n;
    L[1] = 1, R[n] = n;
    for(int i = 2; i <= n; i ++) l[i] = (p[i] < p[i - 1]) ? i : l[i - 1], L[i] = (p[i] > p[i - 1]) ? i : L[i - 1];
    for(int i = n - 1; i > 0; i --) r[i] = (p[i] < p[i + 1]) ? i : r[i + 1], R[i] = (p[i] > p[i + 1]) ? i : R[i + 1];
    ml[0] = -1;
    for(int i = 1; i <= n; i ++) ml[i] = max(ml[i - 1], max(i - L[i], R[i] - i));
    mr[n + 1] = -1;
    for(int i = n; i > 0; i --) mr[i] = max(mr[i + 1], max(i - L[i], R[i] - i));
    int ans = 0;
    for(int i = 1; i <= n; i ++) {
        int d = max(i - l[i], r[i] - i);
        if(d <= ml[l[i] - 1] || d <= mr[r[i] + 1]) continue;
        if(l[i] < i && l[i] && l[i] - L[l[i]] >= d) continue;
        if(r[i] > i && r[i] <= n && R[r[i]] - r[i] >= d) continue;
        if(l[i] < i && (i - l[i] + 1 >> 1 << 1) >= r[i] - i + 1) continue;
        if(r[i] > i && (r[i] - i + 1 >> 1 << 1) >= i - l[i] + 1) continue;
        ans ++;
    }
    printf("%d\n", ans);
}