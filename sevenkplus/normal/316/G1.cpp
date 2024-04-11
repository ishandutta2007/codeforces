#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define P 1000000007
#define N 50010
char s[N];int n,m;
char t[10][N];int tn[10],tl[10],tr[10];
int p[N];
int ps[N],pt[10][N];
int rs[N],rt[10][N];
int lb;int *pw;int *rw;
int hhx(int l,int r)
{
    return ps[r]-ps[l]*p[r-l];
}
int hhy(int l,int r)
{
    return pw[r]-pw[l]*p[r-l];
}
int lcps(int x,int y)
{
    int l=1,r=min(n-x,n-y);
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(hhx(x,x+mid)==hhx(y,y+mid))l=mid+1;else r=mid-1;
    }
    return r;
}
int lcpt(int x,int y)
{
    int l=1,r=min(tn[lb]-x,tn[lb]-y);
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(hhy(x,x+mid)==hhy(y,y+mid))l=mid+1;else r=mid-1;
    }
    return r;
}
bool cmps(int x,int y)
{
    int c=lcps(x,y);
    return s[x+c]<s[y+c];
}
bool cmpt(int x,int y)
{
    int c=lcpt(x,y);
    return t[lb][x+c]<t[lb][y+c];
}
int lcpst(int x,int y,int z)
{
    int l=1,r=min(y-x,tn[lb]-z);
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(hhx(x,x+mid)==hhy(z,z+mid))l=mid+1;else r=mid-1;
    }
    return r;
}
int getl(int l,int r,int b)
{
    lb=b;pw=pt[lb];rw=rt[lb];
    int le1=0,ri1=tn[lb]-1;
    while(le1<=ri1)
    {
        int mid=(le1+ri1)/2;
        int c=lcpst(l,r,rw[mid]);
        if(r==l+c)ri1=mid-1;else
        if(s[l+c]<t[lb][rw[mid]+c])ri1=mid-1;else le1=mid+1;
    }
    int le2=0,ri2=tn[lb]-1;
    while(le2<=ri2)
    {
        int mid=(le2+ri2)/2;
        int c=lcpst(l,r,rw[mid]);
        if(r==l+c)le2=mid+1;else
        if(s[l+c]>t[lb][rw[mid]+c])le2=mid+1;else ri2=mid-1;
    }
    //if(l==3&&r==4&&lb==1)printf("%d %d\n",le1,ri2);
    return ri2-le1+1;
}
bool F;
bool cmp1(int x,int y)
{
    bool F0=0,F1=0;
    for(int i=0;i<m;i++)
    {
        int l=getl(x,y,i);
        if(l<tl[i])F0=1;
        if(l>tr[i])F1=1;
        //if(x==3&&y==4)printf("%d %d %d %d\n",i,l,tl[i],tr[i]);
        if(F0&&F1){F=1;return 0;}
    }
    //if(x==3&&y==4)printf("%d %d\n",F0,F1);
    if(!F1)return 1;
    return 0;
}
bool cmp2(int x,int y)
{
    bool F0=0,F1=0;
    for(int i=0;i<m;i++)
    {
        int l=getl(x,y,i);
        if(l<tl[i])F0=1;
        if(l>tr[i])F1=1;
        if(F0&&F1){F=1;return 0;}
    }
    if(!F0)return 1;
    return 0;
}
int main()
{
    scanf("%s",s);n=strlen(s);
    scanf("%d",&m);
    for(int i=0;i<m;i++)scanf("%s%d%d",t[i],tl+i,tr+i),tn[i]=strlen(t[i]);
    p[0]=1;
    for(int i=1;i<N;i++)p[i]=p[i-1]*P;
    ps[0]=0;
    for(int i=0;i<n;i++)ps[i+1]=ps[i]*P+s[i];
    for(int i=0;i<m;i++)
    {
        int *pw=pt[i];char *st=t[i];
        pw[0]=0;
        for(int j=0;j<tn[i];j++)
            pw[j+1]=pw[j]*P+st[j];
    }
    for(int i=0;i<n;i++)rs[i]=i;
    sort(rs,rs+n,cmps);
    for(int i=0;i<m;i++)
    {
        int *rw=rt[i];
        for(int j=0;j<tn[i];j++)rw[j]=j;
        pw=pt[i];lb=i;
        sort(rw,rw+tn[i],cmpt);
    }
    /*
    for(int i=0;i<n;i++)
        printf("%s\n",s+rs[i]);
    puts("");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<tn[i];j++)
            printf("%s\n",t[i]+rt[i][j]);
        puts("");
    }
    */
    int S=0;
    for(int i=0;i<n;i++)
    {
        int le=0;
        if(i>0)le=lcps(rs[i],rs[i-1]);
        //printf("%s\n",s+rs[i]+le);
        int ri=n-rs[i];
        //printf("%d %d\n",le,ri);
        F=0;
        int le1=le+1,ri1=ri;
        //if(i==n-1)printf("%d %d %d\n",rs[i],rs[i]+1,cmp1(rs[i],rs[i]+1));
        while(le1<=ri1)
        {
            int mid=(le1+ri1)/2;
            if(cmp1(rs[i],rs[i]+mid))ri1=mid-1;else le1=mid+1;
            if(F)break;
        }
        //if(i==n-1)puts("STOP");
        if(F)continue;
        int le2=le+1,ri2=ri;
        while(le2<=ri2)
        {
            int mid=(le2+ri2)/2;
            if(cmp2(rs[i],rs[i]+mid))le2=mid+1;else ri2=mid-1;
            if(F)break;
        }
        if(F)continue;
        //printf("%d %d\n",le1,ri2);
        S+=max(0,ri2-le1+1);
    }
    printf("%d\n",S);
    return 0;
}