#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 3;

int t, n, h[N];
long long ansl[N], ansr[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &h[i]);
        if(n & 1){
            long long ans = 0;
            for (int i = 2; i < n; i += 2){
                if(h[i] <= max(h[i - 1], h[i + 1]))
                    ans += max(h[i - 1], h[i + 1]) - h[i] + 1;
            }
            printf("%lld\n", ans);
            continue;
        }
        for (int i = 2; i < n; i += 2){
            ansl[i] = ansl[i - 2];
            if(h[i] <= max(h[i - 1], h[i + 1]))
                ansl[i] += max(h[i - 1], h[i + 1]) - h[i] + 1;
        }
        long long ans = ansl[n - 2];
        ansr[n + 1] = 0;
        for (int i = n - 1; i > 1; i -= 2){
            ansr[i] = ansr[i + 2];
            if(h[i] <= max(h[i - 1], h[i + 1]))
                ansr[i] += max(h[i - 1], h[i + 1]) - h[i] + 1;
            ans = min(ans, ansl[i - 3] + ansr[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}