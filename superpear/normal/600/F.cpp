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

int A,B,N,M,Ans,flag,x,y,z1,z2;
int F[2005][1005];
int xc[100005],yc[100005],ans[100005],degree[2005];

void Change(int s,int nowedge,int z,int Alter)
{
    //cout<<s<<" "<<nowedge<<" "<<z<<endl;
    int ec=F[s][z],ko;
    F[s][z]=nowedge;
    F[s][Alter-z]=ec;
    if (ec!=0)
    {
        if (xc[ec]==s) ko=yc[ec]; else ko=xc[ec];
        Change(ko,ec,Alter-z,Alter);
    }
}

int main()
{
    //freopen("F.in","r",stdin);

    scanf("%d %d %d",&A,&B,&M);
    N=A+B;
    for (int i=1;i<=M;i++)
        scanf("%d %d",&xc[i],&yc[i]),
        yc[i]+=A;
    memset(F,0,sizeof(F));
    //F[i][j] indicates the label of edge connected to vertex i with color j
    Ans=0;
    memset(degree,0,sizeof(degree));
    for (int i=1;i<=M;i++) degree[xc[i]]++,degree[yc[i]]++;
    for (int i=1;i<=N;i++) Ans=max(Ans,degree[i]);

    //Construction algorithm
    for (int i=1;i<=M;i++)
    {
        x=xc[i],y=yc[i];
        flag=0;
        for (int j=1;j<=Ans;j++)
            if ((F[x][j]==0)&&(F[y][j]==0))
            {
                flag=j;
                break;
            }
        if (flag!=0)
            F[x][flag]=i,F[y][flag]=i;
        else
        {
            z1=0,z2=0;
            for (int j=1;j<=Ans;j++)
            {
                if (F[x][j]==0) z1=j;
                if (F[y][j]==0) z2=j;
            }
            F[x][z1]=i;
            //cout<<i<<" "<<z1<<" "<<z2<<endl;
            Change(y,i,z1,z1+z2);
        }
    }

    memset(ans,0,sizeof(ans));
    for (int i=1;i<=A;i++)
        for (int j=1;j<=Ans;j++)
            if (F[i][j]!=0)
                ans[F[i][j]]=j;
    printf("%d\n",Ans);
    for (int i=1;i<=M;i++) printf("%d ",ans[i]);
    printf("\n");

    return 0;
}