#include<bits/stdc++.h>
using namespace std;

int t;
long long n;

bool bad(long long n) {
    long long m = n;
    while(m) {
        int r = m % 10;
        m /= 10;
        if(r == 0) continue;
        if(n % r) return 1;
    }
    return 0;
}

int main() {
    for(scanf("%d", &t); t --; ) {
        scanf("%lld", &n);
        while(bad(n)) n ++;
        printf("%lld\n", n);
    }
}