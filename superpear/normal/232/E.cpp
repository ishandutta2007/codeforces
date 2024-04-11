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

struct five
{
    int x1,y1,x2,y2,place;
} query[600005],querybak[600005];

bitset<505> f[505][505],cc;
int m,n,q,xc,yc,xd,yd;
int a[505][505],ans[600005];
char ch;

five make_five(int x1,int y1,int x2,int y2,int s)
{
    five cs;
    cs.x1=x1;cs.y1=y1;cs.x2=x2;cs.y2=y2;cs.place=s;
    return cs;
}

void doit(int l,int r,int ql,int qr)
{
    if (ql>qr) return;
    int mid=(l+r)/2,o1,o2,x1,y1,x2,y2;
    for (int i=1;i<=m;i++)
        for (int j=l;j<=r;j++)
            f[i][j].reset();
    for (int i=1;i<=m;i++)
        if (a[i][mid]==0) f[i][mid].set(i);
    for (int i=1;i<=m;i++)
        for (int j=mid;j<=r;j++)
        {
            if (a[i][j]==1) continue;
            if (i-1>0) f[i][j]|=f[i-1][j];
            if (j-1>=mid) f[i][j]|=f[i][j-1];
        }
    for (int i=1;i<=m;i++)
        f[i][mid].reset();
    for (int i=1;i<=m;i++)
        if (a[i][mid]==0) f[i][mid].set(i);
    for (int i=m;i>=1;i--)
        for (int j=mid;j>=l;j--)
        {
            if (a[i][j]==1) continue;
            if (i+1<=m) f[i][j]|=f[i+1][j];
            if (j+1<=mid) f[i][j]|=f[i][j+1];
        }
    //if ((l==1)&&(r==4)) cout<<f[2][2]<<" "<<f[4][4]<<endl;
    o1=ql-1;o2=qr+1;
    for (int i=ql;i<=qr;i++)
    {
        x1=query[i].x1;y1=query[i].y1;
        x2=query[i].x2;y2=query[i].y2;
        //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<l<<" "<<r<<endl;
        if (((y1<=mid)&&(y2>mid))||(l==r))
        {
            cc=f[x1][y1]&f[x2][y2];
            //cout<<f[x1][y1]<<" "<<f[x2][y2]<<endl;
            if (cc.any()) ans[query[i].place]=1;
        }
        else
        {
            if (y2<=mid)
            {
                ++o1;querybak[o1]=query[i];
            }
            else
            {
                --o2;querybak[o2]=query[i];
            }
        }
    }
    if (l<r)
    {
        for (int i=ql;i<=o1;i++) query[i]=querybak[i];
        for (int i=qr;i>=o2;i--) query[i]=querybak[i];
        doit(l,mid,ql,o1);
        doit(mid+1,r,o2,qr);
    }
}

int main()
{
    //freopen("E.in","r",stdin);
    memset(a,0,sizeof(a));
    scanf("%d %d",&m,&n);
    scanf("%c",&ch);
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            scanf("%c",&ch);
            if (ch=='.') a[i][j]=0; else a[i][j]=1;
        }
        scanf("%c",&ch);
    }
    scanf("%d",&q);
    for (int i=1;i<=q;i++)
    {
        scanf("%d %d %d %d",&xc,&yc,&xd,&yd);
        query[i]=make_five(xc,yc,xd,yd,i);
    }
    memset(ans,0,sizeof(ans));
    doit(1,n,1,q);
    for (int i=1;i<=q;i++)
        if (ans[i]==0) printf("No\n"); else printf("Yes\n");

    return 0;
}