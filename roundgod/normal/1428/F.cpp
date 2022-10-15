#include<bits/stdc++.h>
#define MAXN 500005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
#define y1 asxdkodas
using namespace std;
typedef long long ll;
typedef pair<ll,int> P;
int n;
char str[MAXN];
int pre[MAXN],suf[MAXN];
int st[MAXN][21];
int save[MAXN];
int pr[MAXN];
void init(int n,int *arr)
{
    pr[1]=0;
    for(int i=2;i<=n;i++)
    {
        pr[i]=pr[i-1];
        if ((1<<pr[i]+1)==i) ++pr[i];
    }
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pr[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    scanf("%d",&n);
    scanf("%s",str+1);
    for(int i=1;i<=n;i++)
    {
        if(str[i]=='0') pre[i]=0; else pre[i]=pre[i-1]+1;
    }
    for(int i=n;i>=1;i--) if(str[i]=='0') suf[i]=0; else suf[i]=suf[i+1]+1;
    ll ans=0;
    init(n,suf);
    memset(save,-1,sizeof(save));
    for(int i=1;i<=n;i++)
    {
        if(pre[i]!=0)
        {
            int l=0,r=i-pre[i];
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(query(mid,i-pre[i])>=pre[i]) l=mid; else r=mid;
            }
            ans+=1LL*pre[i]*(i-pre[i]-l);
            if(i==n||pre[i+1]==0) 
            {
                ans+=1LL*pre[i]*(pre[i]+1)*(pre[i]+2)/6-pre[i];
                ans-=1LL*pre[i]*(i-pre[i]-l);
                save[i-pre[i]+1]=i-pre[i]-l;
            }
        }
    }
    init(n,pre);
    for(int i=n;i>=1;i--)
    {
        if(suf[i]!=0)
        {
            int l=i+suf[i],r=n+1;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(query(i+suf[i],mid)>suf[i]) r=mid; else l=mid;
            }
            ans+=1LL*suf[i]*(r-(i+suf[i]));
            if(i==1||suf[i-1]==0)
            {
                assert(save[i]!=-1);
                ans-=1LL*suf[i]*(r-(i+suf[i]));
                ans+=1LL*suf[i]*(save[i]+1)*(r-(i+suf[i])+1);
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}