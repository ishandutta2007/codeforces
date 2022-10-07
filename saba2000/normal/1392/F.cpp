#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll h[1000009];
main(){
    ll n;
    scanf("%lld", &n);
    ll tot = 0;
    for(int i = 1; i <= n; i++){
        scanf("%lld", &h[i]);
        tot += h[i];
    }
    for(int i = 1; i <= n; i++){
        ll N = n - i + 1;
        h[i] = (2*tot-N*(N-1)+2*N-1)/(2*N);
        tot -= h[i];

    }
    for(int i = 1; i <= n; i++){
        printf("%lld ", h[i]);
    }
    printf("\n");

}
/*
0000001234
556789
*/