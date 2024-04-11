#include<stdio.h>
#include<algorithm>
using namespace std;
int T, n, m, K;
long long Mod = 1000000007, D[2010], F[201000], invF[201000];
struct point{
    int x, y;
    bool operator<(const point &p)const{
        return x + y < p.x + p.y;
    }
}w[2010];
long long Inv(long long a){
    int t = Mod - 2;
    long long r = 1;
    while (t){
        if (t & 1)r = r*a%Mod;
        a = a*a%Mod;
        t >>= 1;
    }
    return r;
}
long long Gap(int a, int b){
    return F[a + b] * invF[b] % Mod*invF[a] % Mod;
}
int main()
{
    int i, j;
    long long r;
    F[0] = invF[0] = 1;
    for (i = 1; i <= 200000; i++){
        F[i] = F[i - 1] * i%Mod;
        invF[i] = Inv(F[i]);
    }
    
    T = 1;
    while (T--){
        scanf("%d%d%d", &n, &m, &K);
        n--, m--;
        for (i = 0; i < K; i++){
            scanf("%d%d", &w[i].x, &w[i].y);
            w[i].x--, w[i].y--;
        }
        w[K].x = n, w[K].y = m;
        sort(w, w + K + 1);
        for (i = 0; i <= K; i++){
            r = Gap(w[i].x, w[i].y);
            for (j = 0; j < i; j++){
                if (w[j].x <= w[i].x && w[j].y <= w[i].y){
                    r = (r - D[j] * Gap(w[i].x - w[j].x, w[i].y - w[j].y) % Mod + Mod) % Mod;
                }
            }
            D[i] = r;
        }
        printf("%lld\n", D[K]);
    }
}