#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
typedef long long LL;

int n , m;
vector<int> fac[N];
int mu[N] , a[N];
int cnt[N] , f[N];
LL C[N];
int main() {

    int i , j , x;
    mu[1] = 1;
    for (i = 1 ; i < N ; ++ i) {
        for (j = i + i ; j < N ; j += i)
            mu[j] -= mu[i];            
    }
    for (i = 1 ; i < N ; ++ i) {
        if (!mu[i]) continue;
        for (j = i ; j < N ; j += i)
            fac[j].push_back(i);
    }
    scanf("%d%d" , &n , &m);
    for (i = 0 ; i <= n ; ++ i)
        C[i] = (LL) i * (i - 1) / 2;
    for (i = 1 ; i <= n ; ++ i)
        scanf("%d" , &a[i]);
    LL res = 0;
    for (i = 1 ; i <= m ; ++ i) {
        scanf("%d" , &x);
        for (auto& y : fac[a[x]]) {
            res -= C[cnt[y]] * mu[y];                
            if (!f[x]) {
                ++ cnt[y];
            } else {
                -- cnt[y];
            }
            res += C[cnt[y]] * mu[y];                
        }        
        f[x] ^= 1;
        printf("%lld\n" , res);
    }
    
    return 0;
}