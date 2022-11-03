/*
ID: Sfiction
OJ: CF
PROB: 492D
*/
#include <cstdio>
#include <cstdlib>

const int MAXL=2000000+100;

long long hit[MAXL][2];

int Comp(const void *a,const void *b){
    if (*(long long *)a==*(long long *)b)
        return 0;
    else
        return *(long long *)a>*(long long *)b ? 1 : -1;
}

int gcd(int a,int b){
    return b==0 ? a : gcd(b,a%b);
}

int main(){
    int n,x,y;
    int fac,hp;
    scanf("%d%d%d",&n,&x,&y);
    fac=gcd(x,y);
    x/=fac;
    y/=fac;
    for (int i=1;i<=x;++i){
        hit[i][0]=i*(long long)y;
        hit[i][1]=0;
    }
    for (int i=x+1;i<=x+y;++i){
        hit[i][0]=(i-x)*(long long)x;
        hit[i][1]=1;
    }
    qsort(hit+1,x+y,sizeof(hit[0]),Comp);
    while (n--){
        scanf("%d",&hp);
        hp%=x+y;
        if (hp==0 || hp+1==x+y)
            puts("Both");
        else
            puts(hit[hp][1] ? "Vova" : "Vanya");
    }
    return 0;
}