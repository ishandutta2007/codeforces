#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    scanf("%d%d", &n, &k);
    int z = k - 1;
    while(n % z) z --;
    int y = n / z;
    printf("%d\n", y * k + z);
}