#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = (int)2e5 + 500;

int n,q;
ll a[N], k[N], pa[N];

int main() {
    scanf("%d%d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%I64d", &a[i]);
        pa[i] = (i == 0 ? a[i] : pa[i-1] + a[i]);
    }
    ll cum = 0;
    for(int i = 0; i < q; i++){
        scanf("%I64d", &k[i]);
        auto now = upper_bound(pa, pa+n, k[i]+cum) - pa;
        if(now == (ll)n) printf("%d\n", n), cum = 0;
        else{
            printf("%I64d\n", (ll)n - now);
            cum += k[i];
        }
    }
}