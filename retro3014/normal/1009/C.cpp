#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

ll N, M;
ll S;

ll sum(ll x){
    return x*(x+1)/2;
}
ll b, s;
ll pp, mm;

int main(){
    scanf("%lld%lld", &N, &M);
    b=sum(N-1);
    s=sum(N-1);
    for(double i=2; i<=N; i++){
        b=max(b, sum(N-i)+sum(i-1));
        s=min(s, sum(N-i)+sum(i-1));
    }
    ll x;
    ll y;
    for(ll i=1; i<=M; i++){
        scanf("%lld%lld", &x, &y);
        if(y>0){
            pp+=y;
        }
        else{
            mm+=y;
        }
        S+=x*N;
    }
    S+=pp*b;
    S+=mm*s;
    printf("%lf", (double)S/(double)N);
    return 0;
}