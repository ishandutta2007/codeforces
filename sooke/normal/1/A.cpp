#include <cstdio>

int n , m , k;

int main(){
    scanf("%d%d%d" , &n , &m , &k);
    printf("%lld" , (long long)((n - 1) / k + 1) * ((m - 1) / k + 1));
    return 0;
}