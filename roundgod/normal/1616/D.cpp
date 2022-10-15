#include<bits/stdc++.h>
#define MAXN 100005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,x,a[MAXN];
ll s[MAXN];
int n,last[MAXN],dp[MAXN];
vector<ll> dis;
struct segtree
{
    int maxi[4*MAXN];
    void pushup(int k)
    {
        maxi[k]=max(maxi[k*2],maxi[k*2+1]);
    }
    void build(int k,int l,int r)
    {
        if(l==r) {maxi[k]=-INF; return;}
        int mid=(l+r)/2;
        build(k*2,l,mid); build(k*2+1,mid+1,r);
        pushup(k);
    }
    void update(int k,int l,int r,int pos,int val)
    {
        if(l==r)
        {
            maxi[k]=max(maxi[k],val);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid) update(k*2,l,mid,pos,val); else update(k*2+1,mid+1,r,pos,val);
        pushup(k);
    }
    int query(int k,int l,int r,int x,int y)
    {
        if(l>y||x>r) return -INF;
        if(l>=x&&r<=y) return maxi[k];
        int mid=(l+r)/2;
        return max(query(k*2,l,mid,x,y),query(k*2+1,mid+1,r,x,y));
    }
}seg;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        dis.clear();
        scanf("%d",&n);
        dis.push_back(0);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&x);
        for(int i=1;i<=n;i++) 
        {
            a[i]-=x;
            s[i]=s[i-1]+a[i];
            dis.push_back(s[i]);
        }
        sort(dis.begin(),dis.end());
        dis.erase(unique(dis.begin(),dis.end()),dis.end());
        int sz=(int)dis.size();
        seg.build(1,1,sz);
        int id=lower_bound(dis.begin(),dis.end(),s[0])-dis.begin()+1;
        last[0]=1;
        for(int i=1;i<=n;i++)
        {
            last[i]=last[i-1];
            int id=lower_bound(dis.begin(),dis.end(),s[i])-dis.begin()+1;
            int pos=seg.query(1,1,sz,id+1,sz);
            //printf("pos=%d\n",pos);
            if(pos==-INF) pos=1; else pos=max(1,min(pos+2,i));
            last[i]=max(last[i],pos);
            //printf("i=%d last=%d\n",i,last[i]);
            id=lower_bound(dis.begin(),dis.end(),s[i-1])-dis.begin()+1;
            seg.update(1,1,sz,id,i-1);
        }
        seg.build(1,1,n+2);
        seg.update(1,1,n+2,1,-1);
        for(int i=1;i<=n;i++)
        {
            dp[i]=seg.query(1,1,n+2,last[i],i)+i+1;
            dp[i]=max(dp[i],dp[i-1]);
            seg.update(1,1,n+2,i+2,dp[i]-(i+2));
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}