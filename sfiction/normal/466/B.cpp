/*
ID: Sfiction
OJ: CF
PROB: 466B
*/
#include <cstdio>

int main(){
    long long n,a,b;

    scanf("%I64d%I64d%I64d",&n,&a,&b);
    n*=6;
    if (a*b>=n){
        printf("%I64d\n%I64d %I64d",a*b,a,b);
        return 0;
    }

    bool flag=false;
    if (a>b){
        flag=true;
        a^=b^=a^=b;
    }
    long long ansa=1<<30,ansb=1<<30;
    for (;a*a<=n;++a){
        long long t=(n-1)/a+1;
        if (t<b)
            break;
        if (ansa*ansb>a*t){
            ansa=a;
            ansb=t;
        }
    }
    if (flag)
        ansa^=ansb^=ansa^=ansb;
    printf("%I64d\n%I64d %I64d",ansa*ansb,ansa,ansb);
    return 0;
}