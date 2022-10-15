#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define MAXN 200005
#define INF 1000000000
#define MOD 1000000007
#define F first
#define S second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int t,n,m,k;
vector<pair<P,int> > v;
int l[MAXN],r[MAXN];
ll sum[MAXN];
int cnt[MAXN];
ll a[3][MAXN];
ll st[3][MAXN][20];
int pre[MAXN];
void init(int id,int n,ll *arr)
{
    pre[1]=0;
    for(int i=2;i<=n;i++)
    {
        pre[i]=pre[i-1];
        if ((1<<pre[i]+1)==i) ++pre[i];
    }
    for(int i=n-1;i>=0;--i)
    {
        st[id][i][0]=arr[i];
        for(int j=1;(i+(1<<j)-1)<n;++j)
            st[id][i][j]=max(st[id][i][j-1],st[id][i+(1<<j-1)][j-1]);
    }
}
ll query(int id,int l,int r)
{
    if(l>r) return 0;
    //printf("id=%d l=%d r=%d\n",id,l,r);
    int len=r-l+1,k=pre[len];
    return max(st[id][l][k],st[id][r-(1<<k)+1][k]);
}
int ans[MAXN];
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<=n;i++) cnt[i]=sum[i]=0; 
        v.clear();
        for(int i=0;i<n;i++) 
        {
            int x,p;
            scanf("%d%d",&x,&p);
            v.push_back(make_pair(P(x,p),i));
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
        {
            int x=v[i].F.F,p=v[i].F.S;
            l[i]=lower_bound(v.begin(),v.end(),make_pair(P(x-p,0),0))-v.begin();
            r[i]=upper_bound(v.begin(),v.end(),make_pair(P(x+p,INF),n+1))-v.begin()-1;
            //printf("i=%d x=%d p=%d l=%d r=%d pos=%d\n",i,x,p,l[i],r[i],v[i].S);
            //[l[i],i] [i,r[i]]
            sum[l[i]]+=p-x; sum[i]-=p-x;
            cnt[l[i]]++; cnt[i]--;
            sum[i]+=p+x; sum[r[i]+1]-=p+x;
            cnt[i]--; cnt[r[i]+1]++;
        }
        for(int i=1;i<n;i++) {cnt[i]+=cnt[i-1]; sum[i]+=sum[i-1];}
        for(int i=0;i<n;i++) {sum[i]+=1LL*cnt[i]*v[i].F.F;}
       // for(int i=0;i<n;i++) {printf("%lld ",sum[i]);}
       // puts("");
        for(int i=0;i<n;i++) {a[1][i]=sum[i]; a[0][i]=a[1][i]-v[i].F.F; a[2][i]=a[1][i]+v[i].F.F;}
        for(int i=0;i<3;i++) init(i,n,a[i]);
        for(int i=0;i<n;i++)
        {
            int x=v[i].F.F,p=v[i].F.S;
            //[l[i],i] [i,r[i]]
            bool f=false;
            ll s1=query(0,l[i],i)-p+x; if(s1>m) f=true;
            ll s2=query(1,0,l[i]-1); if(s2>m) f=true;
            ll s3=query(2,i+1,r[i])-p-x; if(s3>m) f=true;
            ll s4=query(1,r[i]+1,n-1); if(s4>m) f=true;
            //printf("s1=%lld s2=%lld s3=%lld s4=%lld m=%d\n",s1,s2,s3,s4,m);
            if(f) ans[v[i].S]=0; else ans[v[i].S]=1;
        }
        for(int i=0;i<n;i++) printf("%d",ans[i]);
        puts("");
    }
    return 0;
}