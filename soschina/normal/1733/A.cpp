#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 101;

int t, n, k, a[N], b[N];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &n, &k);
        memset(b, 0, sizeof(b));
        for (int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            b[i % k] = max(b[i % k], a[i]);
        }
        long long sum = 0;
        for (int i = 0; i < k; i++)
            sum += b[i];
        printf("%lld\n", sum);
    }
    return 0;
}