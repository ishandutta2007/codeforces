#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int N;
LL Xsum, Ysum;

int main(){
    int X, Y;
    scanf("%d", &N);
    for (int i=1; i<=2*N; i++) {
        scanf("%d %d", &X, &Y);
        Xsum += X;
        Ysum += Y;
    }
    printf("%lld %lld\n", Xsum/N, Ysum/N);
    return 0;
}