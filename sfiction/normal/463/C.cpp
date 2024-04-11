/*
ID: Sfiction
OJ: CF
PROB: 463C
*/
#include <cstdio>
#include <cstring>

const int MAXN=2000+10;

int n;
int board[MAXN][MAXN];
long long maind[MAXN<<1],minor[MAXN<<1];//diagonal

int main(){
    int i,j;

    scanf("%d",&n);
    memset(board,0,sizeof(board));
    memset(maind,0,sizeof(maind));
    memset(minor,0,sizeof(minor));
    for (i=0;i<n;++i)
        for (j=0;j<n;++j){
            scanf("%d",&board[i][j]);
            maind[j-i+n-1]+=board[i][j];
            minor[i+j]+=board[i][j];
        }

    long long max[2]={-1,-1};
    int x[2],y[2];
    long long t,sign;
    for (i=0;i<n;++i)
        for (j=0;j<n;++j){
            t=maind[j-i+n-1]+minor[i+j]-board[i][j];
            sign=(i+j)&1;
            if (max[sign]<t){
                max[sign]=t;
                x[sign]=i+1;
                y[sign]=j+1;
            }
        }
    printf("%I64d\n%d %d %d %d",max[0]+max[1],x[0],y[0],x[1],y[1]);
    return 0;
}