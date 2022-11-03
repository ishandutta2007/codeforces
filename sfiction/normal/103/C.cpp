/*
ID: Sfiction
OJ: CF
PROB: 103C
*/
#include <cstdio>
long long n,k;
int p;
void Case1(){
    long long t;
    long long lim=(n-k)<<1;
    for (;p;--p){
        scanf("%I64d",&t);
        if ((t<=lim)&&(t&1))
            printf(".");
        else printf("X");
    }
}
void Case2(){
    long long t;
    long long lim=n-(k<<1);
    for (;p;--p){
        scanf("%I64d",&t);
        if ((t>lim)&&((t&1)==0))
            printf("X");
        else
            printf(".");
    }
}
void Case3(){
    long long t;
    long long lim=n-(k<<1)+1;
    for (;p;--p){
        scanf("%I64d",&t);
        if (((t>lim)&&((t&1)==0))||(t==n))
            printf("X");
        else
            printf(".");
    }
}
void Case4(){
    for (;p;--p)
        putchar('.');
}
void Case5(){
    long long t;
    for (;p;--p){
        scanf("%I64d",&t);
        if (n==t)
            putchar('X');
        else
            putchar('.');
    }
}
int main(){
    scanf("%I64d%I64d%d",&n,&k,&p);
    if (k==0) Case4();
    else if (k==1) Case5();
        else if (n<=(k<<1)) Case1();
            else if (n&1) Case3();
                else Case2();
    return 0;
}