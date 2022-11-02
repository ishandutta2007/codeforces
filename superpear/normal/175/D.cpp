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

double pc1,pc2,notc,ec,c1,d1;
double f[210][210][65],suma[210][210][65],sumb[210][210][65];
int hp1,hp2,dt1,dt2,l1,l2,r1,r2,p1,p2,o,cs,cf,la,lb;
int turn[65];
double lou[65],qiu[65];

int lcm(int a,int b)
{
    for (int i=1;i<=1000;i++)
        if ((i%a==0)&&(i%b==0)) return i;
}

int main()
{
    //freopen("D.in","r",stdin);

    scanf("%d %d %d %d %d",&hp1,&dt1,&l1,&r1,&p1);
    scanf("%d %d %d %d %d",&hp2,&dt2,&l2,&r2,&p2);

    if (p1==100)
    {
        cout<<0<<endl;
        return 0;
    }

    if (p2==100)
    {
        cout<<1<<endl;
        return 0;
    }

    pc1=double(p1)/100;
    pc2=double(p2)/100;

    o=0;
    cs=lcm(dt1,dt2);
    for (int i=0;i<cs;i++)
    {
        if (i%dt1==0) ++o,turn[o]=1;
        if (i%dt2==0) ++o,turn[o]=2;
    }

    memset(suma,0,sizeof(suma));
    memset(sumb,0,sizeof(sumb));
    for (int i=1;i<=o;i++)
    {
        for (int j=0;j<=hp1;j++) f[j][0][i]=1,suma[j][0][i]=1+suma[j-1][0][i],sumb[j][0][i]=1;
        for (int j=0;j<=hp2;j++) f[0][j][i]=0;
    }

    for (int i=1;i<=hp1;i++)
        for (int j=1;j<=hp2;j++)
        {
            for (int k=1;k<=o;k++)
            {
                cf=k%o+1;
                if (turn[k]==1)
                {
                    la=j-r1,lb=j-l1;
                    if (lb<=0) ec=1; else
                        if (la<=0)
                            ec=((-la)+sumb[i][lb][cf])/double(lb-la+1);
                        else
                            ec=(sumb[i][lb][cf]-sumb[i][la-1][cf])/double(lb-la+1);
                }
                else
                {
                    la=i-r2,lb=i-l2;
                    if (lb<=0) ec=0; else
                        if (la<=0)
                            ec=(suma[lb][j][cf])/double(lb-la+1);
                        else
                            ec=(suma[lb][j][cf]-suma[la-1][j][cf])/double(lb-la+1);
                }
                if (turn[k]==1) lou[k]=pc1; else lou[k]=pc2;
                qiu[k]=ec*(1-lou[k]);
            }
            c1=lou[o],d1=qiu[o];
            for (int k=o-1;k>=1;k--)
            {
                c1=c1*lou[k];
                d1=d1*lou[k]+qiu[k];
            }
            f[i][j][1]=d1/(1-c1);
            f[i][j][o]=qiu[o]+lou[o]*f[i][j][1];
            for (int k=o-1;k>=2;k--)
                f[i][j][k]=f[i][j][k+1]*lou[k]+qiu[k];
            for (int k=1;k<=o;k++)
            {
                suma[i][j][k]=suma[i-1][j][k]+f[i][j][k];
                sumb[i][j][k]=sumb[i][j-1][k]+f[i][j][k];
            }
        }
    printf("%.10lf\n",f[hp1][hp2][1]);

    return 0;
}