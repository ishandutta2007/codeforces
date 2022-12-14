#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll N,K;
int avail(ll num){
    if(num==0) return false;
    ll mycnt=0,aicnt=0;
    ll temp=N;
    while(temp){
        if(temp<=num){
            mycnt+=temp;
            temp=0;
        }
        else{
            mycnt+=num;
            temp-=num;
            aicnt+=temp/10;
            temp-=temp/10;
        }
    }
    return mycnt>=aicnt;
}
int main(){
    scanf("%lld",&N);
    ll s = 0;
    ll e = N;
    K=N;
    while(s<e){
        ll m = (s+e)>>1;
        if(avail(m)){
            K=min(m,K);
            e=m-1;
        }
        else{
            s=m+1;
        }
    }
    if(avail(s)){
        K=min(K,s);
    }
    printf("%lld\n",K);
    return 0;
}