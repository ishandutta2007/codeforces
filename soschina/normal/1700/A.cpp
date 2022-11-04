#include <cstdio>
using namespace std;

int t, n, m;

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &m);
        printf("%lld\n", 1ll * (1 + n) * n * m / 2 + 1ll * m * (m - 1) / 2);
    }
    return 0;
}