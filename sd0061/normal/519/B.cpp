#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 205;

void work() {
    int n , i , x;
    int a = 0 , b = 0 , c = 0;
    scanf("%d",&n);
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&x) , a ^= x;
    -- n;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&x) , b ^= x;
    -- n;
    for (i = 0 ; i < n ; ++ i)
        scanf("%d",&x) , c ^= x;
    printf("%d\n%d\n" , a ^ b , b ^ c);
}

int main() {
    work();
    return 0;
}