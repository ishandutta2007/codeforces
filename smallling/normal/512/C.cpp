#include<cstdio>
#include<climits>
#include<cstring>

using namespace std;

struct lhy{
    int x,y,f,next;
}edge[800001];

int test[9]={2,3,5,7,11,13,17,19,23};
int son[300],now[300],back[300],dis[300],pre[300],sumd[300],a[300],id[300][2],belong[300],Addi,Addj;
int Flow,tot,st,ed,ans[300][300],n,cnt,N,h,l,v,Now,k,q[300],b[300],right[300],cnt1,New[300];

int pow(int x,int m,int mo)
{
    int nowans=1;
    while(m)
    {
        if(m&1)nowans=1ll*nowans*x%mo;
        x=1ll*x*x%mo;
        m>>=1ll;
    }
    return nowans;
}

bool Check(int a,int n,int mo)
{
    int d=n-1;
    while(!(d&1))d>>=1;
    int t=pow(a,d,mo);
    while((d!=n-1)&&(t!=1)&&(t!=n-1))
    {
        t=1ll*t*t%mo;
        d<<=1;
    }
    return (t==n-1)||(d&1==1);
}

bool Miller_Rabin(int n)
{
    if(n==2)return 1;
    if(((n&1)==0)||(n==1))return 0;
    for(int i=0;i<9;i++)
    {
        if(n==test[i])return 1;
        if(!Check(test[i],n,n))return 0;
    }
    return 1;       
}

inline void add(int x,int y,int f)
{
    edge[++tot].x=x;edge[tot].y=y;edge[tot].f=f;edge[tot].next=son[x];son[x]=tot;
    edge[++tot].x=y;edge[tot].y=x;edge[tot].f=0;edge[tot].next=son[y];son[y]=tot;
}

void SAP()
{
    memset(dis,0,sizeof(dis));
    memset(back,0,sizeof(back));
    memset(pre,0,sizeof(pre));
    int i=st,j,t,tmp,flag,flow=INT_MAX,minn;
    while(dis[st]<n)
    {
        back[i]=flow;
        flag=0;
        t=now[i];
        while(t!=-1)
        {
            j=edge[t].y;
            if(edge[t].f>0&&dis[j]+1==dis[i])
            {
                flag=1;
                now[i]=t;
                pre[j]=t;
                if(edge[t].f<flow)flow=edge[t].f;
                i=j;
                if(i==ed)
                {
                    Flow+=flow;
                    while(i!=st)
                    {
                        edge[pre[i]].f-=flow;
                        edge[pre[i]^1].f+=flow;
                        i=edge[pre[i]].x;
                    }
                    flow=INT_MAX;
                }
                break;
            }
            t=edge[t].next;
        }
        if(flag)continue;
        minn=n-1;
        t=son[i];
        while(t!=-1)
        {
            if(edge[t].f>0&&dis[edge[t].y]<minn)minn=dis[edge[t].y],tmp=t;
            t=edge[t].next;
        }
        now[i]=tmp;
        if(!(--sumd[dis[i]]))break;
        sumd[dis[i]=minn+1]++;
        if(i!=st)flow=back[i=edge[pre[i]].x];
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),cnt1=cnt1+(a[i]==1);
    st=cnt=1;
    for(int i=1;i<=n;i++)
        id[i][0]=id[i][1]=++cnt,belong[cnt]=i;
    ed=++cnt;
    tot=-1;
    memset(son,-1,sizeof(son));
    for(int i=1;i<=n;i++)
    {
        if(a[i]%2==1)add(st,id[i][0],2);
        else add(id[i][0],ed,2);
    }
    for(int i=1;i<=n;i++)
        if(a[i]%2==1&&a[i]!=1)
            for(int j=1;j<=n;j++)
                if(a[j]%2==0)if(Miller_Rabin(a[i]+a[j]))add(id[i][1],id[j][0],1);
    N=n;
    n=ed;
    for(int i=1;i<=n;i++)now[i]=son[i];
    SAP();
    if(Flow!=N)return puts("Impossible"),0;
    for(int i=1;i<=n;i++)
        if(a[i]==1)
            for(int j=1;j<=n;j++)
                if(a[j]%2==0)if(Miller_Rabin(a[i]+a[j]))add(id[i][1],id[j][0],1);
    for(int i=1;i<=n;i++)now[i]=son[i];
    SAP();
    n=N;
    for(int i=1;i<=n;i++)
        if(a[i]%2==1&&!b[i])
        {
            int bo=0;
            h=l=0;
            q[++l]=i;
            b[i]=1;
            while(h<l)
            {
                v=q[++h];
                if(a[v]%2==1)
                {
                    int nowcnt=0;
                    for(int i=son[id[v][1]];i!=-1;i=edge[i].next)
                        if(edge[i].f==0)
                        {
                            nowcnt++;
                            if(!b[belong[edge[i].y]])
                            {
                                b[belong[edge[i].y]]=1;
                                q[++l]=belong[edge[i].y];
                            }
                            if(right[v]&&!right[belong[edge[i].y]])right[belong[edge[i].y]]=v;
                            else if(right[belong[edge[i].y]]!=v)right[v]=belong[edge[i].y];
                        }
                    if(nowcnt<2)
                    {
                        bo=1;
                        break;
                    }
                }
                else
                {
                    int nowcnt=0;
                    for(int i=son[id[v][0]];i!=-1;i=edge[i].next)
                        if(edge[i].f==1)
                        {
                            nowcnt++;
                            if(!b[belong[edge[i].y]])
                            {
                                b[belong[edge[i].y]]=1;
                                q[++l]=belong[edge[i].y];
                            }
                            if(right[v]&&!right[belong[edge[i].y]])right[belong[edge[i].y]]=v;
                            else if(right[belong[edge[i].y]]!=v)right[v]=belong[edge[i].y];
                        }
                    if(nowcnt<2)
                    {
                        bo=1;
                        break;
                    }
                }
            }
            if(bo)
            {
                for(int j=1;j<=l;j++)b[q[j]]=0;
                continue;
            }
            Now=q[1];
            k++;
            ans[k][1]=Now;
            ans[k][0]=1;
            Now=right[Now];
            while(Now!=q[1])
            {
                ans[k][++ans[k][0]]=Now;
                Now=right[Now];
            }
        }
    for(int i=1;i<=n;i++)
        if(!b[i])New[++New[0]]=i;
    if(New[0]>=3)
    {
        ans[++k][0]=New[0];
        for(int i=1;i<=New[0];i++)
            ans[k][i]=New[i];
    }
    else
    {
        for(int i=1;i<=k;i++)
        {
            int bo=0;
            for(int j=1;j<=ans[i][0];j++)
                if(a[ans[i][j]]==1)
                {
                    ans[i][0]+=New[0];
                    Addi=i;
                    Addj=j;
                    bo=1;
                    break;
                }
            if(bo)break;
        }
    }
    printf("%d\n",k);
    for(int i=1;i<=k;i++)
    {
        for(int j=0;j<=ans[i][0];j++)
        {
            if(Addi==i&&Addj==j)
            {
                while(New[0])putchar('1'),putchar(' '),New[0]--;
            }
            if(ans[i][j]==0)break;
            printf("%d ",ans[i][j]);
        }
        puts("");
    }
}