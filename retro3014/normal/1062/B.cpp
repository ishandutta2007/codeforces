#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>

using namespace std;
typedef long long ll;


ll N, C;
ll A, B;
ll ans=0;
ll two=1;
ll ans2=1;
bool tf=false;

int main(){
    cin>>N;
    if(N==1){
        printf("1 0");
        return 0;
    }
    ll t;
    for(ll i=2; i*i<=N; i++){
        t=0;
        while(N%i==0){
            t++;
            N/=i;
        }
        if(t!=0){
            ans2*=i;
        }
        if(C!=0 && t!=C && t!=0){
            tf=true;
        }
        C=max(C, t);
    }
    if(N!=1){
        if(C!=0 && C!=1){
            tf=true;
        }
        C=max(C, (ll)1);
        ans2*=N;
    }
    while(two<C){
        two*=2; ans++;
    }
    ans+=(tf||(two!=C));
    printf("%lld %lld", ans2, ans);
}