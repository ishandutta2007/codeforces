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

int a[5005][5005],f[5005][5005],dat[5005];
string s;
int n,m,xc,yc;

void search(int l,int r)
{
    if (f[l][r]!=biglongint) return;
    if (l>r)
    {
        f[l][r]=0;
        return;
    }
    if (l==r)
    {
        f[l][r]=1;
        return;
    }
    search(l,r-1);
    search(l+1,r);
    search(l+1,r-1);
    f[l][r]=f[l][r-1]+f[l+1][r]-f[l+1][r-1]+a[l][r];
}

int main()
{
    cin>>s;
    memset(a,0,sizeof(a));
    n=s.size();
    for (int i=1;i<=n;i++) dat[i]=s[i-1];
    for (int i=1;i<=n;i++)
    {
        a[i][i]=1;
        xc=i;yc=i;
        while ((xc>1)&&(yc<n)&&(dat[xc-1]==dat[yc+1]))
        {
            --xc;++yc;
            a[xc][yc]=1;
        }
    }
    for (int i=1;i<n;i++)
        if (dat[i]==dat[i+1])
        {
            a[i][i+1]=1;
            xc=i;yc=i+1;
            while ((xc>1)&&(yc<n)&&(dat[xc-1]==dat[yc+1]))
            {
                --xc;++yc;
                a[xc][yc]=1;
            }
        }
    /*for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
            cout<<a[i][j];
        cout<<endl;
    }*/
    memset(f,127,sizeof(f));
    search(1,n);
    cin>>m;
    for (int i=1;i<=m;i++)
    {
        scanf("%d %d",&xc,&yc);
        printf("%d\n",f[xc][yc]);
    }
    return 0;
}