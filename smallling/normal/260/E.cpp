#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>

using namespace std;

struct lhy{
    int cnt,l,r,d[2],max[2],min[2];
}p[100010];

int x[100010],y[100010],X[100010],Y[100010],sumx[100010],sumy[100010];
int a[10],c[10],sum[4],flag[10],wherex[100010],wherey[100010],root,n,x1,x2,y1,y2,D,X1,Y1,X2,Y2;

int Ask(int mid,int d)
{
    int nowans=0;
    if(p[mid].min[0]>=X1&&p[mid].max[0]<=X2&&p[mid].min[1]>=Y1&&p[mid].max[1]<=Y2)return p[mid].cnt;
    if(p[mid].min[0]>X2||p[mid].max[0]<X1||p[mid].min[1]>Y2||p[mid].max[1]<Y1)return 0;
    if(p[mid].d[0]<=X2&&p[mid].d[0]>=X1&&p[mid].d[1]<=Y2&&p[mid].d[1]>=Y1)nowans=1;
    if(p[mid].l)nowans+=Ask(p[mid].l,d^1);
    if(p[mid].r)nowans+=Ask(p[mid].r,d^1);
    return nowans;
}

int ask(int x1,int y1,int x2,int y2)
{
    X1=x1,Y1=y1,X2=x2,Y2=y2;
    int nowans=Ask(root,0);
    return nowans;
}

void work()
{
    if(c[3]==9)
        c[3]=9;
    for(int i=1;i<=3;i++)
        sum[i]=0;
    for(int i=1;i<=9;i++)
        sum[(i-1)/3+1]+=a[c[i]];
    if(!wherex[sum[1]])return;
    x1=wherex[sum[1]];
    if(!wherex[sum[1]+sum[2]])return;
    x2=wherex[sum[1]+sum[2]];
    for(int i=1;i<=3;i++)
        sum[i]=0;
    for(int i=1;i<=9;i++)
        sum[(i-1)%3+1]+=a[c[i]];
    if(!wherey[sum[1]])return;
    y1=wherey[sum[1]];
    if(!wherey[sum[1]+sum[2]])return;
    y2=wherey[sum[1]+sum[2]];
    if((ask(1,1,x1,y1)!=a[c[1]])||(ask(1,y1+1,x1,y2)!=a[c[2]])||(ask(1,y2+1,x1,Y[0])!=a[c[3]])
    ||(ask(x1+1,1,x2,y1)!=a[c[4]])||(ask(x1+1,y1+1,x2,y2)!=a[c[5]])||(ask(x1+1,y2+1,x2,Y[0])!=a[c[6]])
    ||(ask(x2+1,1,X[0],y1)!=a[c[7]])||(ask(x2+1,y1+1,X[0],y2)!=a[c[8]])||(ask(x2+1,y2+1,X[0],Y[0])!=a[c[9]]))return;
    printf("%.10lf %.10lf\n%.10lf %.10lf\n",X[x1]+0.5,X[x2]+0.5,Y[y1]+0.5,Y[y2]+0.5);
    exit(0);
}

void dfs(int x)
{
    if(x>9)
    {
        work();
        return;
    }
    for(int i=1;i<=9;i++)
        if(!flag[i])
        {
            flag[i]=1;
            c[x]=i;
            dfs(x+1);
            flag[i]=0;
        }
}

inline int cmp(const lhy &a,const lhy &b)
{
    return a.d[D]<b.d[D];
}

inline void updata(int now)
{
    p[now].cnt=1;
    if(p[now].l)
    {
        for(int i=0;i<2;i++)
            p[now].min[i]=min(p[now].min[i],p[p[now].l].min[i]),
            p[now].max[i]=max(p[now].max[i],p[p[now].l].max[i]);
        p[now].cnt+=p[p[now].l].cnt;
    }
    if(p[now].r)
    {
        for(int i=0;i<2;i++)
            p[now].min[i]=min(p[now].min[i],p[p[now].r].min[i]),
            p[now].max[i]=max(p[now].max[i],p[p[now].r].max[i]);
        p[now].cnt+=p[p[now].r].cnt;
    }
}

int build(int l,int r,int d)
{
    D=d;
    int mid=(l+r)>>1;
    nth_element(p+l,p+mid,p+r+1,cmp);
    for(int i=0;i<2;i++)
        p[mid].min[i]=p[mid].max[i]=p[mid].d[i];
    if(l<mid)p[mid].l=build(l,mid-1,d^1);
    if(mid<r)p[mid].r=build(mid+1,r,d^1);
    updata(mid);
    return mid;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]),X[i]=x[i],Y[i]=y[i];
    sort(X+1,X+1+n);
    sort(Y+1,Y+1+n);
    X[0]=unique(X+1,X+1+n)-X-1;
    Y[0]=unique(Y+1,Y+1+n)-Y-1;
    for(int i=1;i<=n;i++)
        x[i]=lower_bound(X+1,X+1+X[0],x[i])-X,sumx[x[i]]++,
        y[i]=lower_bound(Y+1,Y+1+Y[0],y[i])-Y,sumy[y[i]]++,
        p[i].d[0]=x[i],p[i].d[1]=y[i];
    root=build(1,n,0);
    for(int i=1;i<=X[0];i++)
        sumx[i]+=sumx[i-1];
    for(int i=X[0];i;i--)
        if(!wherex[sumx[i]])wherex[sumx[i]]=i;
    for(int i=1;i<=Y[0];i++)
        sumy[i]+=sumy[i-1];
    for(int i=Y[0];i;i--)
        if(!wherey[sumy[i]])wherey[sumy[i]]=i;
    for(int i=1;i<=9;i++)
        scanf("%d",&a[i]);
    dfs(1);
    puts("-1");
}