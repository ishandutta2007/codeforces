#include<cstdio>
#include<cctype>
#include<cstring>
#include<algorithm>

#define For(i,x,y) for (int i=x;i<y;i++)
using namespace std;

int IN()
{
    int c,x;
    while (!isdigit(c=getchar()));x=c-'0';
    while (isdigit(c=getchar())) x=(x<<1)+(x<<3)+c-'0';return x;
}

const int N=100+19,V=100*12+19;
int v1,v2,t,d;
int F[N][V];

int main()
{
    scanf("%d%d%d%d",&v1,&v2,&t,&d);
    memset(F,128,sizeof(F));
    F[1][v1]=v1;
    For(i,1,t+1)
        For(j,0,v1+t*d+1)
            if (F[i][j]>=0)
                For(k,-d,d+1)
                    if (j+k>=0) F[i+1][j+k]=max(F[i+1][j+k],F[i][j]+(j+k));
    printf("%d\n",F[t][v2]);
}