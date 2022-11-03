/*
ID: Sfiction
OJ: CF
PROB: 467B
*/
#include <cstdio>

const int MAXN=1000+10;

int n,m,k;
int player[MAXN];

int sum_digit(int a,int b){
    int ret=0;
    for (int i=0;i<n;++i){
        ret+=(a&1)==(b&1);
        a>>=1;
        b>>=1;
    }
    return ret;
}

int main(){
    int ans=0;

    scanf("%d%d%d",&n,&m,&k);
    k=n-k;

    for (int i=0;i<=m;++i)
        scanf("%d",&player[i]);
    for (int i=0;i<m;++i){
        if (sum_digit(player[i],player[m])>=k)
            ++ans;
    }
    printf("%d",ans);
    return 0;
}