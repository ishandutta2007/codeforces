/*
ID: Sfiction
OJ: CF
PROB: E
*/
#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    long long t,a,b;
    cin>>t>>a>>b;
    if (t==1){
        if (a==1){
            printf(b==1 ? "inf" : "0");
            return 0;
        }
        else if (b>1){
            while (b%a==0)
                b/=a;
            if (b==1){
                printf("1");
                return 0;
            }
        }
    }
    int ans=b==a;
    long long temp,mod=a;
    while (b>0 && a>0){
        temp=b%mod;
        b/=mod;
        a-=temp;
        if (a<0 || a%t!=0)
            break;
        a/=t;
    }
    ans+=a==0 && b==0;
    printf("%d",ans);
    return 0;
}