#include <bits/stdc++.h>
using namespace std;

int N, Q;
int X, Y;

int main() {
    scanf("%d %d", &N, &Q);
    for (int q=0; q<Q; q++){
        scanf("%d %d", &X, &Y);
        long long ans = 0;
        if ((X+Y)&1) {
            ans += ((long long)N * N + 1)/2;
            if (N&1) {
                ans += (long long)((X-1)/2) * N;
                if (!(X&1)) ans += N/2;
            }
            else ans += (long long)(X-1) * (N/2);
            if (X&1) ans += Y/2;
            else ans += (Y+1)/2;
        }
        else{
            if (N&1) {
                ans += (long long)((X-1)/2) * N;
                if (!(X&1)) ans += (N+1)/2;
            }
            else ans += (long long)(X-1) * (N/2);
            if (X&1) ans += (Y+1)/2;
            else ans += Y/2;
        }
        printf("%I64d\n", ans);
    }
    return 0;
}