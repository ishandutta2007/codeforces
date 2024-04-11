#include<bits/stdc++.h>
#define MAXN 1000005
#define MAXM 2000005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m;
P a[MAXN],b[MAXN];
int bit[2*MAXN+1];
int sum(int i)
{
    int s=0;
    while(i>0)
    {
        s+=bit[i];
        i-=i&-i;
    }
    return s;
}
void add(int i,int x)
{
    while(i<=n)
    {
        bit[i]+=x;
        i+=i&-i;
    }
}
struct segtree
{
    int ans[4*MAXN],sum[4*MAXN],rsum[4*MAXN];
    void pushup(int k)
    {
        ans[k]=min(ans[k*2]+rsum[k*2+1],ans[k*2+1]+sum[k*2]);
        sum[k]=sum[k*2]+sum[k*2+1];
        rsum[k]=rsum[k*2]+rsum[k*2+1];
    }
    void build(int k,int l,int r)
    {
        if(l==r)
        {
            sum[k]=1; rsum[k]=0; ans[k]=0;
            return;
        }
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int p,int type)
    {
        if(l==r)
        {
            if(type==0) {sum[k]=0; rsum[k]=0;}
            else {sum[k]=0; rsum[k]=1;} 
            return;
        }
        int mid=(l+r)/2;
        if(p<=mid) update(k*2,l,mid,p,type); else update(k*2+1,mid+1,r,p,type);
        pushup(k);
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++) {scanf("%d",&a[i].F); a[i].S=i;}
        for(int i=1;i<=m;i++) {scanf("%d",&b[i].F); b[i].S=i;}
        ll ans=0;
        for(int i=1;i<=n;i++) bit[i]=0;
        sort(a+1,a+n+1); sort(b+1,b+m+1);
        int l=1;
        seg.build(1,1,n);
        vector<int> equal;
        for(int i=1;i<=m;i++)
        {
            if(i==1||b[i].F!=b[i-1].F)
            {
                for(auto x:equal)
                    seg.update(1,1,n,x,1);
                equal.clear();
            }
            else {ans+=seg.ans[1]; continue;}
            while(l<=n&&a[l].F<=b[i].F)
            {
                if(a[l].F==b[i].F) {equal.push_back(a[l].S); seg.update(1,1,n,a[l].S,0);}
                else seg.update(1,1,n,a[l].S,1);
                l++;
            }
            ans+=seg.ans[1];
        }
        int now=1;
        while(now<=n)
        {
            int cur=now;
            while(cur+1<=n&&a[cur].F==a[cur+1].F) cur++;
            for(int i=now;i<=cur;i++) ans+=sum(n+1-a[i].S);
            for(int i=now;i<=cur;i++) add(n+1-a[i].S,1);
            now=cur+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}