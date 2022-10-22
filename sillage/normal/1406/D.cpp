#include<bits/stdc++.h>
using namespace std;
const int maxn = 100010;
long long a[maxn], b[maxn];
int n;
int main(){
    scanf("%d", &n);
    long long cnt = 0;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]); a[0] = 0;
    for (int i = 2; i <= n; i++){
        b[i] = a[i] - a[i-1];
        if (b[i] > 0) cnt += b[i];
    }
    long long z = (a[1] - cnt)/2;
    printf("%lld\n", max(a[1] - z, z + cnt));
    int q;
    scanf("%d", &q);
    while (q--){
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        if (l == 1) a[1] += x;
        if (l > 1){
            if (b[l] > 0) cnt -= b[l];
            b[l] += x;
            if (b[l] > 0) cnt += b[l];
        }
        if (r < n){
            r++;
            if (b[r] > 0) cnt -= b[r];
            b[r] -= x;
            if (b[r] > 0) cnt += b[r];
        }
        z = (a[1] - cnt)/2;
        printf("%lld\n", max(a[1] - z, z + cnt));
    }
    return 0;
}