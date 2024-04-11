#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, a, mn = 100000, sum = 0, gas = 0, nn;
    scanf("%d", &n);
    nn = 2 * n - 1;
    while(nn --) {
        scanf("%d", &a);
        sum += abs(a);
        mn = min(mn, abs(a));
        if(a < 0) gas ++;
    }
    if(n & 1) {printf("%d", sum); return 0;}
    if(gas & 1) {printf("%d", sum - 2 * mn); return 0;}
    printf("%d", sum);
}