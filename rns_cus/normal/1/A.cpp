#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int main(){
    int n, m, a;
    scanf("%d %d %d", &n, &m, &a);
    printf("%I64d\n", 1ll*((n-1)/a+1)*((m-1)/a+1));
    return 0;
}