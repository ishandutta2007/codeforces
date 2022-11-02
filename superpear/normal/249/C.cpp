#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;

const int maxn=100005;

double f[maxn][105],com[600000][6];
double nowans,cb;
int n,q,ui,vi,ki;
int a[maxn],now[maxn];
double g[105];

int main()
{
    memset(com,0,sizeof(com));
    com[0][0]=1;
    for (int i=1;i<=550000;i++)
    {
        com[i][0]=1;
        for (int j=1;j<=5;j++)
            com[i][j]=com[i-1][j]+com[i-1][j-1];
    }
    /*for (int i=1;i<=10;i++)
        for (int j=1;j<=5;j++) cout<<i<<" "<<j<<" "<<com[i][j]<<endl;*/
    //freopen("C.in","r",stdin);
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]),now[i]=a[i];
    memset(f,0,sizeof(f));
    for (int i=1;i<=n;i++) f[i][a[i]]=1;
    scanf("%d",&q);
    nowans=0;
    for (int i=1;i<=n;i++) if (a[i]==0) ++nowans;
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d %d",&ui,&vi,&ki);
        for (int j=0;j<=a[ui];j++) g[j]=0;
        for (int j=0;j<=a[ui];j++)
        {
            for (int k=0;k<=ki;k++)
                if (j>=k)
                {
                    g[j-k]+=f[ui][j]*(com[j][k]*com[now[ui]-j][ki-k]/com[now[ui]][ki]);
                    //cout<<com[now[ui]][k]<<endl;
                }
        }
        //for (int k=0;k<=ki;k++) cout<<g[k]<<" ";cout<<endl;
        //cout<<g[0]<<endl;
        nowans=nowans-f[ui][0]+g[0];
        for (int k=0;k<=a[ui];k++) f[ui][k]=g[k];
        printf("%.12lf\n",nowans);
        now[ui]-=ki;
        now[vi]+=ki;
    }

    return 0;
}