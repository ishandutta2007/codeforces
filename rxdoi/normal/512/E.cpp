#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=1000+19;
struct node {int x,y;} A1[N],A2[N];
int A[N][N],n,x,y,c1,c2;

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n-3;i++)
    {
        scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);A[x][y]=1;
    }
    for (int i=2;i<n;i++)
        for (int j=n;j>=i+2;j--) if (A[i][j]) A1[c1++]=(node){i,j};
    memset(A,0,sizeof(A));
    for (int i=1;i<=n-3;i++)
    {
        scanf("%d%d",&x,&y);
        if (x>y) swap(x,y);A[x][y]=1;
    }
    for (int i=2;i<=n;i++)
        for (int j=n;j>=i+2;j--) if (A[i][j])
            for (int k=i+1;k<j;k++)
                if ((k==i+1||A[i][k])&&(k==j-1||A[k][j])) {A2[c2++]=(node){1,k};break;}
    printf("%d\n",c1+c2);
    for (int i=0;i<c1;i++) printf("%d %d\n",A1[i].x,A1[i].y);
    for (int i=c2-1;i>=0;i--) printf("%d %d\n",A2[i].x,A2[i].y);
}