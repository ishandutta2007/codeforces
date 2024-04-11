/*
ID: Sfiction
OJ: CF
PROB: 442B
*/
#include <cstdio>

const int MAXN=2000+10;

int n,m,k;
char map[MAXN][MAXN];

void Init(){
    int i;
    scanf("%d%d%d",&n,&m,&k);
    for (i=1;i<=n;++i)
        scanf("%s",&map[i][1]);
}
int Calc(int col){
    int i;
    int sum;
    sum=0;
    for (i=2;i<=n;++i){
        if ((i-1)%2==0&&map[i][col]=='U')
            ++sum;
        if (col-i>=0&&map[i][col-i+1]=='R')
            ++sum;
        if (col+i-1<=m&&map[i][col+i-1]=='L')
            ++sum;
    }
    return sum;
}
int main(){
    Init();
    for (int i=1;i<=m;++i)
        printf("%d ",Calc(i));
    return 0;
}