#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 1, mod = 1e9 + 7;

int t, n, a, p[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 0; i < n; i++){
            scanf("%d", &a);
            p[a] = i;
        }
        int l = p[0], r = p[0], ans = 1;
        for (int i = 1; i < n; i++){
            if(p[i] < l || p[i] > r){
                l = min(l, p[i]);
                r = max(r, p[i]);
            }else
                ans = 1ll * ans * (r - l - i + 1) % mod;
        }
        printf("%d\n", ans);
    }
    return 0;
}