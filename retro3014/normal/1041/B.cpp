#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
typedef long long ll;

ll d(ll x, ll y){
    if(x==0){
        return y;
    }
    return d(y%x, x);
}

ll N, M, A, B;
ll ans;

int main(){
    scanf("%lld%lld%lld%lld", &N, &M, &A, &B);
    ll gcd=d(A, B);
    A/=gcd; B/=gcd;
    ans=N/A;
    ans=min(ans, M/B);
    printf("%lld", ans);
    return 0;
}