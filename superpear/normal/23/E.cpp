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

const int maxn=705;
vector<int> a[maxn];
string f[maxn][maxn];
string g[maxn][maxn];
stringstream stream;
int n,xc,yc;

bool big(const string &x,const string &y)
{
    if (x.size()<y.size()) return false;
    if (x.size()>y.size()) return true;
    return x>y;
}

string cheng(const string &x,const string &y)
{
    int n=x.size(),m=y.size(),s;
    int a[n+m+1],b[n+m+1],c[n+m+1];
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for (int i=1;i<=n;i++) a[i]=x[n-i]-48;
    for (int i=1;i<=m;i++) b[i]=y[m-i]-48;
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
        {
            s=a[i]*b[j]+c[i+j-1];
            c[i+j-1]=s%10;
            c[i+j]+=s/10;
        }
    string st="";
    s=m+n;
    while ((s>1)&&(c[s]==0)) --s;
    for (int i=s;i>=1;i--) st+=c[i]+48;
    return st;
}

void dfs(int s,int fa)
{
    int c,o=0,u[maxn];
    for (int i=0;i<a[s].size();i++)
    {
        c=a[s][i];
        if (c!=fa)
        {
            dfs(c,s);
            ++o;u[o]=c;
        }
    }
    string now,st,t;
    for (int i=1;i<=o;i++)
    {
        now="1";
        for (int j=1;j<=o;j++)
            if (j!=i) now=cheng(now,f[u[j]][0]);
        for (int j=1;j<n;j++)
        {
            t=cheng(now,f[u[i]][j]);
            if (big(t,f[s][j+1])) f[s][j+1]=t;
        }
    }
    for (int i=0;i<=o;i++)
        for (int j=0;j<=o;j++)
            g[i][j]="0";
    g[0][0]="1";
    for (int i=0;i<o;i++)
        for (int j=0;j<=i;j++)
        {
            t=cheng(g[i][j],f[u[i+1]][0]);
            if (big(t,g[i+1][j])) g[i+1][j]=t;
            t=cheng(g[i][j],f[u[i+1]][1]);
            if (big(t,g[i+1][j+1])) g[i+1][j+1]=t;
        }
    for (int i=0;i<=o;i++)
        if (big(g[o][i],f[s][i+1])) f[s][i+1]=g[o][i];
    for (int i=1;i<=n;i++)
    {
        stream.clear();
        stream<<i;
        stream>>st;
        st=cheng(st,f[s][i]);
        if (big(st,f[s][0])) f[s][0]=st;
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    cin>>n;
    for (int i=1;i<n;i++)
    {
        cin>>xc>>yc;
        a[xc].p_b(yc);
        a[yc].p_b(xc);
    }
    for (int i=0;i<maxn;i++)
        for (int j=0;j<maxn;j++)
            f[i][j]="0";
    dfs(1,0);
    cout<<f[1][0]<<endl;

    return 0;
}