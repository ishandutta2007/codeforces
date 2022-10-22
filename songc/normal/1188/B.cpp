#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

LL ans;
int N, K, P;
map<int, int> M;

int main(){
    LL x;
    scanf("%d %d %d", &N, &P, &K);
    for (int i=1; i<=N; i++){
        scanf("%lld", &x);
        x = (((x*x%P)*(x*x%P))%P - (K*x%P) + P) % P;
        ans += M[x];
        M[x]++;
    }
    printf("%lld\n", ans);
    return 0;
}