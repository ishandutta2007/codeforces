#include <iostream>
#include <cstring>
using namespace std;
int n, sum[102], ok = 1;
char s[102];
int main() {
    scanf("%d", &n);
    scanf("%s", s+1);
    for(int i=1;i<=n;i++) {
        if(s[i] != '4' && s[i] != '7') ok = 0;
        sum[i] = sum[i-1] + s[i] - '0';
    }

    if(n%2 == 0 && sum[n/2] * 2 != sum[n]) {
        ok = 0;
    }
    if(n%2 == 1 && sum[n/2] * 2 + s[n/2+1] - '0' != sum[n]) {
        ok = 0;
    }
    printf("%s\n", ok?"YES":"NO");

}