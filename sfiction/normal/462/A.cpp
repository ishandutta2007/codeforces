/*
ID: Sfiction
OJ: CF
PROB: 462A
*/
#include <cstdio>
#include <cstring>

const int MAXN=100+10;

char map[MAXN][MAXN];

bool Work(){
    int n;

    memset(map,0,sizeof(map));
    scanf("%d",&n);
    for (int i=1;i<=n;++i){
        scanf("%s",&map[i][1]);
        for (int j=1;j<=n;++j)
            map[i][j]=map[i][j]=='o';
        map[i][n+1]=0;
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if ((map[i-1][j]+map[i+1][j]+map[i][j-1]+map[i][j+1])&1)
                return false;
    return true;
}

int main(){
    printf(Work() ? "YES" : "NO");
    return 0;
}