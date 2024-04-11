#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
typedef long long LL;

int T, N, K, X, Y;
int ans;

int main(){
    scanf("%d", &T);
    while (T--){
        scanf("%d %d %d %d", &N, &X, &Y, &K);
        ans = 1234567890;
        if (X % K == Y % K) ans = abs(X - Y) / K;
        if (Y % K == 1) ans = min(ans, (X+K-2)/K + (Y-1)/K);
        if (Y % K == N % K) ans = min(ans, (N-X+K-1)/K + (N-Y)/K);
        if (ans == 1234567890) printf("-1\n");
        else printf("%d\n", ans);
    }
    return 0;
}