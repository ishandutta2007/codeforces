#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int N=100+19,M=5000+19;
const double eps=1e-9;
struct Edge {int x,y,f;} E[M];
typedef double Matrix[N][N];
int n,m;
double Ans,L=0.0,R=1e7,Flow[M];
Matrix A,B;

void Gauss()
{
    for (int i=1;i<n;i++)
    {
        int r=i;
        for (int j=i+1;j<n;j++) if (fabs(A[j][i])>fabs(A[r][i])) r=j;
        if (fabs(A[r][i])<eps) continue;
        if (r!=i) for (int j=i;j<=n+1;j++) swap(A[i][j],A[r][j]);
        double x=A[i][i];
        for (int j=i;j<=n+1;j++) A[i][j]/=x;
        for (int j=1;j<n;j++)
            if (i!=j&&fabs(A[j][i])>eps)
            {
                double x=A[j][i];
                for (int k=i;k<=n+1;k++) A[j][k]-=A[i][k]*x;
            }
    }
}
int check(double x)
{
    for (int i=1;i<=n;i++)
        for (int j=1;j<=n+1;j++) A[i][j]=B[i][j];
    A[n][n+1]=x;
    for (int i=1;i<n;i++) A[i][n+1]-=x*A[i][n];
    for (int i=0;i<m;i++) Flow[i]=A[E[i].y][n+1]-A[E[i].x][n+1];
    for (int i=0;i<m;i++) if (fabs(Flow[i])>E[i].f) return 0;
    return 1;
}

int main()
{
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=0;i<m;i++) 
    {
        scanf("%d%d%d",&E[i].x,&E[i].y,&E[i].f);
        if (E[i].y!=n&&E[i].y!=1) A[E[i].y][E[i].y]++,A[E[i].y][E[i].x]--;
        if (E[i].x!=n&&E[i].x!=1) A[E[i].x][E[i].y]--,A[E[i].x][E[i].x]++;
    }

    A[1][1]=1.0;
    Gauss();
    memcpy(B,A,sizeof(A));
    
    while (R-L>eps)
    {
        double Mid=(L+R)/2;
        if (check(Mid)) L=Mid;else R=Mid;
    }

    for (int i=0;i<m;i++) if (E[i].y==1||E[i].x==1) Ans+=fabs(Flow[i]);
    printf("%.7lf\n",Ans);
    for (int i=0;i<m;i++) printf("%.7lf\n",Flow[i]);
}