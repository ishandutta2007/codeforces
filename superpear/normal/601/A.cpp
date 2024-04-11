#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;
typedef pair<int,PII> PIII;

#define LL long long
#define ULL unsigned long long
#define w1 first
#define w2 second
#define p_b push_back
#define l_b lower_bound
#define m_p make_pair

const int maxlongint=2147483647;
const int biglongint=2139062143;

int N,M,xc,yc,a[505][505],b[505][505];

int main()
{
    scanf("%d %d",&N,&M);
    memset(a,127,sizeof(a));
    memset(b,127,sizeof(b));
    for (int i=1;i<=M;i++)
    {
        scanf("%d %d",&xc,&yc);
        a[xc][yc]=a[yc][xc]=1;
    }
    for (int i=1;i<=N;i++)
        for (int j=1;j<=N;j++)
            if (a[i][j]==biglongint) b[i][j]=1;
    for (int k=1;k<=N;k++)
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if ((a[i][k]!=biglongint)&&(a[k][j]!=biglongint))
                    a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
    for (int k=1;k<=N;k++)
        for (int i=1;i<=N;i++)
            for (int j=1;j<=N;j++)
                if ((b[i][k]!=biglongint)&&(b[k][j]!=biglongint))
                    b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
    if ((a[1][N]==biglongint)||(b[1][N]==biglongint))
        cout<<-1<<endl;
    else
    {
        if (a[1][N]==1) cout<<b[1][N]<<endl; else cout<<a[1][N]<<endl;
    }
    return 0;
}