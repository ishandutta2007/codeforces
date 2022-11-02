#include<bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    scanf("%I64d", &n);
    int m = sqrt(n) + 1;
    for(int i = 2; i <= m; i ++) if(n % i == 0) {
        printf("%I64d\n", (n - i) / 2 + 1);
        return 0;
    }
    puts("1");
}