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

int n,o;
string st;
LL a[maxn],all;
int cc[100],where[100],zhu[100],g[maxn],wc[maxn];
int f[66][maxn];


int main()
{
    cin>>n;
    all=0;
    for (int i=1;i<=n;i++)
    {
        cin>>a[i];
        all^=a[i];
    }
    st="";
    for (int i=1;i<=63;i++)
    {
        st=char(all%2+48)+st;
        all/=2;
    }
    o=0;
    for (int i=1;i<=63;i++)
        if (st[i-1]=='0') ++o,where[o]=i;
    for (int i=1;i<=63;i++)
        if (st[i-1]=='1') ++o,where[o]=i;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=63;j++)
        {
            cc[64-j]=a[i]%2;
            a[i]/=2;
        }
        a[i]=0;
        for (int j=1;j<=63;j++)
            a[i]=(LL)a[i]*2+cc[where[j]];
        //cout<<a[i]<<endl;
    }
    memset(f,0,sizeof(f));
    memset(g,0,sizeof(g));
    memset(zhu,0,sizeof(zhu));
    for (int i=1;i<=63;i++)
    {
        for (int j=1;j<=n;j++) f[i][j]=((LL)a[j]>>(63-i))%2;
        g[i]=1;
        for (int j=1;j<i;j++)
            if ((zhu[j]!=-1)&&(f[i][zhu[j]]==1))
            {
                for (int k=1;k<=n;k++)
                    f[i][k]^=f[j][k];
                g[i]^=g[j];
            }
        zhu[i]=-1;
        for (int j=1;j<=n;j++) if (f[i][j]==1) {zhu[i]=j;break;}
        if (zhu[i]==-1) g[i]=0;
        //cout<<g[i]<<endl;
    }
    /*for (int i=60;i<=63;i++)
    {
        for (int j=1;j<=5;j++)
            cout<<f[i][j]<<" ";
        cout<<"   "<<g[i]<<endl;
    }*/
    memset(wc,0,sizeof(wc));
    for (int i=63;i>=1;i--)
    {
        for (int j=1;j<=n;j++)
            if (f[i][j]==1) g[i]^=wc[j];
        wc[zhu[i]]=g[i];
    }
    for (int i=1;i<=n;i++) cout<<wc[i]+1<<" ";cout<<endl;

    return 0;
}