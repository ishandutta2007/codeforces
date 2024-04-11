#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

int main() {
    int T, n, K1, K2, W, B;
    scanf("%d",&T);
    while(T--) {
        scanf("%d%d%d",&n,&K1,&K2);
        scanf("%d%d",&W,&B);
        int sW, sB;
        sW = K1 + K2;
        sB = n - K1 + n - K2;
        sW /= 2;
        sB /= 2;
        puts(sW >= W && sB >= B ? "YES" :"NO");
    }
}