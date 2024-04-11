#include <cstdio>
using namespace std;
const int N = 38, M = 12, P[M] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}, p = 998244353;

bool vis[N];

int main(){
    for (int i = 0; i < 12; i++)
        vis[P[i]] = true;
    int n;
    long long m;
    scanf("%d%lld", &n, &m);
    long long d = 1, mul = 1, now = 1, sum = 0;
    for (int i = 1; i <= n; i++){
        now = now * (m % p) % p;
        if(i < N && vis[i])
            mul = mul * i;
        d = d * (m / mul % p) % p;
        sum = (sum + now - d) % p;
    }
    printf("%lld", (sum + p) % p);
    return 0;
}