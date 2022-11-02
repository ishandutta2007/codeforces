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
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int N,len,M,xc,yc,cc,L;
char st[1000005],s[2005];
string sc[2005];
vector<int> g[2005][27];
int sum[2005][26],a[2005];
PII f[2005][2005];

int main()
{
    scanf("%d",&N);
    for (int i=1;i<=N;i++)
    {
        scanf("%s",st);
        len=strlen(st);
        for (int j=0;j<len;j++) sc[i]+=st[j];
    }
    for (int i=1;i<=N;i++)
        for (int j=1;j<=26;j++)
        {
            for (int k=0;k<=sc[i].size();k++) g[i][j].p_b(-1);
            for (int k=sc[i].size()-1;k>=0;k--)
                if (sc[i][k]-96==j) g[i][j][k]=k; else g[i][j][k]=g[i][j][k+1];
        }
    scanf("%d",&M);
    for (int i=1;i<=M;i++) scanf("%d",&a[i]);
    memset(sum,0,sizeof(sum));
    for (int i=1;i<=M;i++)
        for (int j=1;j<=26;j++)
            if (g[a[i]][j][0]!=-1)
                sum[i][j]=sum[i-1][j]+1;
            else
                sum[i][j]=sum[i-1][j];
    scanf("%s",s+1);
    L=strlen(s+1);
    for (int i=0;i<=L;i++)
        for (int j=0;j<=L;j++)
            f[i][j]=m_p(maxlongint,maxlongint);
    f[0][0]=m_p(1,0);
    for (int i=0;i<L;i++)
        for (int j=0;j<=L;j++)
            if (f[i][j].w1!=maxlongint)
            {
                //cout<<i<<" "<<j<<" "<<f[i][j].w1<<" "<<f[i][j].w2<<endl;
                cc=s[i+1]-96;
                f[i+1][j]=min(f[i+1][j],f[i][j]);
                xc=f[i][j].w1,
                yc=f[i][j].w2;
                if (xc>M) continue;
                if (g[a[xc]][cc][yc]!=-1)
                {
                    yc=g[a[xc]][cc][yc];
                    ++yc;
                    if (yc>=sc[a[xc]].size()) ++xc,yc=0;
                    f[i+1][j+1]=min(f[i+1][j+1],m_p(xc,yc));
                }
                else
                {
                    int left=xc+1,right=M,mid;
                    while (left<=right)
                    {
                        mid=(left+right)/2;
                        if (sum[mid][cc]-sum[xc][cc]>0) right=mid-1; else left=mid+1;
                    }
                    if (left<=M)
                    {
                        xc=left;
                        yc=g[a[xc]][cc][0];
                        ++yc;
                        if (yc>=sc[a[xc]].size()) ++xc,yc=0;
                        f[i+1][j+1]=min(f[i+1][j+1],m_p(xc,yc));
                    }
                }
            }
    for (int i=L;i>=0;i--)
        if (f[L][i].w1!=maxlongint)
        {
            printf("%d\n",i);
            break;
        }

    return 0;
}