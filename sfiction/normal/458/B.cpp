/*
ID: Sfiction
OJ: CF
PROB: 457B
*/
#include <cstdio>

const int MAXN=100000+10;

int m,n;
long long a[MAXN],b[MAXN];

long long suma,sumb;

void Init(){
    int i;
    scanf("%d%d",&m,&n);
    suma=0;
    for (i=0;i<m;++i){
        scanf("%I64d",&a[i]);
        suma+=a[i];
    }
    sumb=0;
    for (i=0;i<n;++i){
        scanf("%I64d",&b[i]);
        sumb+=b[i];
    }
}

void Work(){
    long long ansa,ansb;
    long long maxa,maxb;
    int cnta,cntb;
    int i;
    ansa=ansb=0;
    cnta=cntb=0;
    maxa=a[0];
    maxb=b[0];
    for (i=0;i<m;++i){
        if (a[i]<sumb)
            ansa+=a[i];
        else{
            ansa+=sumb;
            ++cnta;
        }
        if (maxa<a[i])
            maxa=a[i];
    }
    if (cnta==0)
        ansa+=sumb-maxa;

    for (i=0;i<n;++i){
        if (b[i]<suma)
            ansb+=b[i];
        else{
            ansb+=suma;
            ++cntb;
        }
        if (maxb<b[i])
            maxb=b[i];
    }
    if (cntb==0)
        ansb+=suma-maxb;
    if (ansa<ansb)
        printf("%I64d",ansa);
    else
        printf("%I64d",ansb);
}

int main(){
    Init();
    Work();
    return 0;
}