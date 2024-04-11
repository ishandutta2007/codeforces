#include<iostream>
#include<stdio.h>
using namespace std;
typedef __int64 ll;
ll a1[1000000+2];
ll b1[1000000+2];
int main(){
    int tmp;
    bool same=true;
    ll n,q;cin>>n>>q;
    ll a=1,b=2,d;
    for(ll i=1;i<=q;i++){
        scanf("%d",&tmp);
        if(tmp==2){
            same=!same;
        }
        if(tmp==1){
            scanf("%I64d",&d);
            if(d<0) d+=n;
            if(same){
                a=a-d/2*2;
                b=b-(d+1)/2*2;
            }else{
                a=a-(d+1)/2*2;
                b=b-d/2*2;
            }
            if(a<=0) a+=n;
            if(b<=0) b+=n;
            if(d%2==1) same=!same;
        }
    }
    if(same){
        for(int i=1;i<=n/2;i++){
            printf("%I64d ",a);
            printf("%I64d ",b);
            a+=2;
            b+=2;
            if(a>n) a-=n;
            if(b>n) b-=n;
        }
    }else{
        for(int i=1;i<=n/2;i++){
            printf("%I64d ",b);
            printf("%I64d ",a);
            a+=2;
            b+=2;
            if(a>n) a-=n;
            if(b>n) b-=n;
        }
    }
    return 0;
}