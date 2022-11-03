/*
ID: Sfiction
OJ: CF
PROB: 460B
*/
#include <cstdio>

const int MAXN=100,LIM=1000000000;

int cnt;
int ans[MAXN];

int MPOW(int x,int p){
    int ret=1;
    while (p--)
        ret*=x;
    return ret;
}

int main(){
    int a,b,c;

    scanf("%d%d%d",&a,&b,&c);
    int num;
    cnt=0;
    for (int i=1;i<100 && (num=(b*MPOW(i,a)+c))<LIM;++i){
        int dig=0,t;
        for (t=num;t;t/=10)
            dig+=t%10;
        if (dig==i)
            ans[cnt++]=num;
    }
    printf("%d\n",cnt);
    if (cnt)
        printf("%d",ans[0]);
    for (int i=1;i<cnt;++i)
        printf(" %d",ans[i]);
    return 0;
}