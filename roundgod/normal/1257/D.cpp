#include<bits/stdc++.h>
#define MAXN 200015
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,a[MAXN],p[MAXN],s[MAXN];
int maxp[MAXN];
int st[MAXN][20];
int pre[MAXN];
void init(int n,int *arr)
{
    for(int i=n;i>=1;--i)
    {
        st[i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<=n;++j)
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
    }
}
int query(int l,int r)
{
    int len=r-l+1,k=pre[len];
    return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main()
{
    pre[1]=0;
    for(int i=2;i<=200000;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++) scanf("%d",&a[i]);
        for(int i=1;i<=n;i++) maxp[i]=0;
        scanf("%d",&m);
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&p[i],&s[i]);
            maxp[s[i]]=max(maxp[s[i]],p[i]);
        }
        for(int i=n-1;i>=0;i--) maxp[i]=max(maxp[i],maxp[i+1]);
        init(n,a);
        int ans=0,now=1;
        bool f=true;
        while(now<=n)
        {
            int l=0,r=n-now+2;
            while(r-l>1)
            {
                int mid=(l+r)/2;
                if(maxp[mid]>=query(now,now+mid-1)) l=mid; else r=mid;
            }
            if(l==0) {f=false; break;}
            else {ans++; now+=l;}
        }
        if(!f) puts("-1"); else printf("%d\n",ans);
    }
    return 0;
}